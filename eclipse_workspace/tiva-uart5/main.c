#include "TM4C123.h"
#include <stdint.h>
#include <stdlib.h>

#define UART_INTERRUPT 1

/* SPI Buffer Size */
#define SPI_BUFFER_SIZE (200)
char Spi_buffer[SPI_BUFFER_SIZE];
int  Spi_index = 0;
int  Spi_Command_Count = 0;

void Delay(unsigned long counter);
char UART0_Receiver(void);
void UART0_Transmitter(unsigned char data);
void printstring(char *str);
void printchar(char c);
char *numtostring(unsigned int num, unsigned int base);

void UART0_Handler( void )
{
	unsigned char rx_data = 0;
	UART0->ICR &= ~(0x010); // Clear receive interrupt
	rx_data = UART0->DR ; // get the received data byte

	// SPI
	if(Spi_index >= SPI_BUFFER_SIZE)
	{
		Spi_index = 0;
	}

	printstring("Spi_Index=");
	printstring(numtostring(Spi_index,10));
	printstring("\n\r");

	printstring("Received Char Hex=");
	printstring(numtostring(rx_data,16));
	printstring("\n\r");

	Spi_buffer[Spi_index++] = rx_data;

	if(rx_data == 'A')
		GPIOF->DATA  = 0x02;
	else if(rx_data == 'B')
		GPIOF->DATA  = 0x00;

	printstring("Received Char=");
	UART0_Transmitter(rx_data); // send data that is received
	printstring("\n\r");
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

    // enable interrupt
      UART0->ICR &= ~(0x0780);; // Clear receive interrupt
      UART0->IM  = 0x0010;
      NVIC->ISER[0] |= 0x00000020; /* enable IRQ5 for UART0 */

      SYSCTL->RCGCGPIO |= 0x20; // turn on bus clock for GPIOF
        GPIOF->DIR       |= 0x02; //set GREEN pin as a digital output pin
        GPIOF->DEN       |= 0x02;  // Enable PF3 pin as a digital pin

	  Delay(1);
	printstring("Enter Command:\n");
	Delay(10);
	while(1)
	{
		Delay(10);
		printstring("\n\rIn Main Loop\r\n");
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
//void SystemInit(void)
//{
//    __disable_irq();    /* disable all IRQs */

    /* Grant coprocessor access */
    /* This is required since TM4C123G has a floating point coprocessor */
//    SCB->CPACR |= 0x00F00000;
//}
