#include "TM4C123.h"
#include <stdint.h>
#include <stdlib.h>

#define UART_INTERRUPT 1

#define DBG_PRINT    0

/* SPI Buffer Size */
#define SPI_BUFFER_SIZE        (100)
#define SPI_COMMAND_SIZE_BYTES   (8)
#define SPI_PROCESS_SIZE        (10)

#define SPI_HEADER             ('A')

#define COMMAND_PROCESS          (1)

/* SPI Raw Buffer and index */
char Spi_RawBuffer[SPI_BUFFER_SIZE];
int  Spi_RawBufferFillIndex = 0;
int  Spi_RawBufferProcessIndex = 0;
int  RawBytesRemainingForProcess = 0;

/* SPI Command count, Current SPI command packet to parse */
int  Spi_CommandCount = 0;
char Spi_CurrentCommandPacket[SPI_COMMAND_SIZE_BYTES];
int  Spi_CurrentCommandPacketIndex = 0;
uint8_t  Spi_HeaderDetected = 0;

void Delay(unsigned long counter);
char UART0_Receiver(void);
void UART0_Transmitter(unsigned char data);
void printstring(char *str);
void printchar(char c);
char *numtostring(unsigned int num, unsigned int base);
void Spi_ParseCommand(void);
void Spi_PrintCommand(void);

void UART0_Handler( void )
{
	unsigned char rx_data = 0;
	UART0->ICR &= ~(0x010); // Clear receive interrupt
	rx_data = UART0->DR ; // get the received data byte

	// SPI
	if(Spi_RawBufferFillIndex >= SPI_BUFFER_SIZE)
	{
		Spi_RawBufferFillIndex = 0;
	}

	printstring("[RX] New Byte : ");
	printstring("Spi_RawBuffer[");
	printstring(numtostring(Spi_RawBufferFillIndex,10));
	printstring("] Hex = ");
	printstring(numtostring(rx_data,16));
	printstring("\n\r");

	Spi_RawBuffer[Spi_RawBufferFillIndex++] = rx_data;
	RawBytesRemainingForProcess++; /* The bytes remaining to process */

	if(rx_data == 'A')
		GPIOF->DATA  = 0x02;
	else if(rx_data == 'B')
		GPIOF->DATA  = 0x00;
#if DBG_PRINT

	printstring(" : Char = ");
	UART0_Transmitter(rx_data); // send data that is received
	printstring("\n\r");
#endif
}

int main(void)
{

#if !UART_INTERRUPT // Polling UART0
	//SYSCTL->RCGCUART |= 0x20;  /* enable clock to UART5 */
	SYSCTL->RCGCUART |= 0x01;  /* enable clock to UART0 */

    //SYSCTL->RCGCGPIO |= 0x10;  /* enable clock to PORTE for PE4/Rx and RE5/Tx */
    SYSCTL->RCGCGPIO |= 0x01;  /* enable clock to PORTA for PA0/Rx and PA1/Tx */

    Delay(1);
    /* UART0 initialization */
    UART0->CTL = 0;         /* UART5 module disbable */
    UART0->IBRD = 104;      /* for 9600 baud rate, integer = 104 */
    UART0->FBRD = 11;       /* for 9600 baud rate, fractional = 11*/
    UART0->CC = 0;          /*select system clock*/
    UART0->LCRH = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
    UART0->CTL = 0x301;     /* Enable UART5 module, Rx and Tx */

    /* UART0 TX5 and RX5 use PE4 and PE5. Configure them digital and enable alternate function */
    GPIOA->DEN = 0x03;      /* set PA0 and PA! as digital */
    GPIOA->AFSEL = 0x03;    /* Use PE4,PE5 alternate function */
    GPIOA->AMSEL = 0;    /* Turn off analg function*/
    GPIOA->PCTL = 0x00000011;     /* configure PE4 and PE5 for UART */

	  Delay(1);
	printstring("Hello World \n");
	Delay(10);
	while(1)
	{
		printstring("\n\rIn Main Loop\r\n");

		char c = UART0_Receiver();          /* get a character from UART5 */
		UART0_Transmitter(c);
	}

#else

	//SYSCTL->RCGCUART |= 0x20;  /* enable clock to UART5 */
	SYSCTL->RCGCUART |= 0x01;  /* enable clock to UART0 */

    //SYSCTL->RCGCGPIO |= 0x10;  /* enable clock to PORTE for PE4/Rx and RE5/Tx */
    SYSCTL->RCGCGPIO |= 0x01;  /* enable clock to PORTA for PA0/Rx and PA1/Tx */

    Delay(1);
    /* UART0 initialization */
    UART0->CTL = 0;         /* UART5 module disbable */
    UART0->IBRD = 104;      /* for 9600 baud rate, integer = 104 */
    UART0->FBRD = 11;       /* for 9600 baud rate, fractional = 11*/
    UART0->CC = 0;          /*select system clock*/
    UART0->LCRH = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
    UART0->CTL = 0x301;     /* Enable UART5 module, Rx and Tx */

    /* UART0 TX5 and RX5 use PE4 and PE5. Configure them digital and enable alternate function */
    GPIOA->DEN = 0x03;      /* set PA0 and PA! as digital */
    GPIOA->AFSEL = 0x03;    /* Use PE4,PE5 alternate function */
    GPIOA->AMSEL = 0;    /* Turn off analg function*/
    GPIOA->PCTL = 0x00000011;     /* configure PE4 and PE5 for UART */

    /* Enable Interrupt */
    UART0->ICR &= ~(0x0780);; // Clear receive interrupt
    UART0->IM  = 0x0010;
    NVIC->ISER[0] |= 0x00000020; /* enable IRQ5 for UART0 */

    /* Configure GREEN LED */
    SYSCTL->RCGCGPIO |= 0x20; // turn on bus clock for GPIOF
    GPIOF->DIR       |= 0x02; //set GREEN pin as a digital output pin
    GPIOF->DEN       |= 0x02;  // Enable PF3 pin as a digital pin

	Delay(10);

	/* Initialize SPI data index and counters */
	Spi_RawBufferFillIndex = 0;
	Spi_RawBufferProcessIndex = 0;
	RawBytesRemainingForProcess = 0;

	Spi_CommandCount = 0;
	Spi_CurrentCommandPacketIndex = 0;

	printstring("\n\rEnter Characters:\n\r");
	Delay(10);
	while(1)
	{
		Delay(1000);
		// printstring("\n\rIn Main Loop\r\n");

		/* If there are sufficient bytes available for processing */
		if(RawBytesRemainingForProcess >= SPI_PROCESS_SIZE)
		{
#if DBG_PRINT
			/* Most probably, you have the full command */
			printstring("\n\rFull Command is there probably\r\n");
#endif

			Spi_ParseCommand();
		}
	}
#endif
}

char UART0_Receiver(void)
{
    char data;
	  while((UART0->FR & (1<<4)) != 0); /* wait until Rx buffer is not full */
    data = UART0->DR ;  	/* before giving it another byte */
    return (unsigned char) data;
}

void UART0_Transmitter(unsigned char data)
{
    while((UART0->FR & (1<<5)) != 0); /* wait until Tx buffer not full */
    UART0->DR = data;                  /* before giving it another byte */
}

void printstring(char *str)
{
  while(*str)
	{
		UART0_Transmitter(*(str++));
	}
}

void printchar(char c)
{
  UART0_Transmitter(c);
}

void Delay(unsigned long counter)
{
	unsigned long i = 0;

	for(i=0; i< counter; i++);
}

char *numtostring(unsigned int num, unsigned int base)
{
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = Representation[num%base];
		num /= base;
	}while(num != 0);

	return(ptr);
}

void Spi_ParseCommand(void)
{
	__disable_irq();

	/* If minimum SPI_COMMAND_SIZE_BYTES bytes available in buffer */
	while(RawBytesRemainingForProcess >= SPI_COMMAND_SIZE_BYTES)
	{
		/* Reset Spi_RawBufferProcessIndex on overflow */
		if(Spi_RawBufferProcessIndex >= SPI_BUFFER_SIZE)
		{
			Spi_RawBufferProcessIndex = 0;
		}

		if(Spi_RawBuffer[Spi_RawBufferProcessIndex] == SPI_HEADER)
		{
#if DBG_PRINT
			printstring("[PR] Process  : ");
			printstring("Spi_RawBuffer[");
			printstring(numtostring(Spi_RawBufferProcessIndex,10));
			printstring("] Hex = ");
			printstring(numtostring(Spi_RawBuffer[Spi_RawBufferProcessIndex],16));
			printstring(" : Char = ");
			UART0_Transmitter(Spi_RawBuffer[Spi_RawBufferProcessIndex]); // send data that is received
			printstring(" : Header Detected\n\r");
#endif
			/* There is chance that you captured full packet already and Spi_HeaderDetected = 1 */
			if((Spi_CurrentCommandPacketIndex == SPI_COMMAND_SIZE_BYTES) && (Spi_HeaderDetected == 1))
			{
				Spi_PrintCommand();
				Spi_HeaderDetected = 0;
				//Spi_CurrentCommandPacketIndex = 0;
			}

			Spi_HeaderDetected = 1;

			/* NOTE: Assumes that the Header is never comes as DATA character */

#if COMMAND_PROCESS
			/* Update the Spi_CurrentCommandPacket buffer */
			Spi_CurrentCommandPacketIndex = 0;  /* Index reset to 0 */
			Spi_CurrentCommandPacket[Spi_CurrentCommandPacketIndex] = Spi_RawBuffer[Spi_RawBufferProcessIndex];
			Spi_CurrentCommandPacketIndex++;
#endif

			/* Should be at the end */
			Spi_RawBufferProcessIndex++;
			RawBytesRemainingForProcess--;
		}
		else
		{
#if DBG_PRINT

			printstring("[PR] Process  : ");
			printstring("Spi_RawBuffer[");
			printstring(numtostring(Spi_RawBufferProcessIndex,10));
			printstring("] Hex = ");
			printstring(numtostring(Spi_RawBuffer[Spi_RawBufferProcessIndex],16));
			printstring(" : Char = ");
			UART0_Transmitter(Spi_RawBuffer[Spi_RawBufferProcessIndex]); // send data that is received
			printstring(" : Not Header\n\r");
#endif

#if COMMAND_PROCESS
			// if header detected, then fill data till size of SPI command Bytes.
			// If buffer full, reset header_detected abd parse comamnd
			// If buffer not full just fill buffer63


			// if Header is not detected, then this is invalid data, ignore.

			if(Spi_HeaderDetected == 1)
			{
				/* Have captured full packet already */
				if(Spi_CurrentCommandPacketIndex == SPI_COMMAND_SIZE_BYTES)
				{
					Spi_PrintCommand();
					Spi_HeaderDetected = 0;
					//Spi_CurrentCommandPacketIndex = 0;
				}
				else if(Spi_CurrentCommandPacketIndex < SPI_COMMAND_SIZE_BYTES)
				{
					/* Then it is data that need to be added into Spi_CurrentCommandPacket */
					Spi_CurrentCommandPacket[Spi_CurrentCommandPacketIndex] = Spi_RawBuffer[Spi_RawBufferProcessIndex];
					Spi_CurrentCommandPacketIndex++;
				}
				else
				{
					printstring(".................................????????????\n\r");
				}
			}
			else
			{
#if DBG_PRINT

				printstring(".................................Searching for Header....\n\r");
#endif
			}

#endif

			Spi_RawBufferProcessIndex++;
			RawBytesRemainingForProcess--;
		}
	}

	__enable_irq();
}

void Spi_PrintCommand(void)
{
	printstring("[SPI_COMMAND] ");
	for(int index = 0; index < SPI_COMMAND_SIZE_BYTES; index++)
	{
		printstring(numtostring(Spi_CurrentCommandPacket[index],16));
		printstring(" ");
	}
	printstring("\n\r");
}

//void SystemInit(void)
//{
//    __disable_irq();    /* disable all IRQs */

    /* Grant coprocessor access */
    /* This is required since TM4C123G has a floating point coprocessor */
//    SCB->CPACR |= 0x00F00000;
//}
