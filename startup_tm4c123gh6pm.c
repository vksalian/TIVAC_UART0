#include <stdint.h>
#include "tm4c123gh6pm.h"

#define SRAM_START        (0x20000000UL)
#define SRAM_SIZE         (32*1024)
#define SRAM_END          (SRAM_START + SRAM_SIZE)

#define STACK_START       (SRAM_END)

/* Re-Declaration of external linker script symbols */
extern uint32_t _s_data;
extern uint32_t _e_data;
extern uint32_t _s_bss;
extern uint32_t _e_bss;
extern uint32_t _e_text;

int main(void);            // Declaration of main function

/* Note: Whenever the MCU gets reset, then the first fynction that gets 
   executed is Reset_Handler(). This function is needed because all Stack
   initialization, copy .data section from FLASH to SRAM and calling of main()
   function happens here */
void Reset_Handler(void) __attribute__((weak));
void Default_Handler(void);

/* Apart from the Reset_Handler(), you might want to implement other Handler
   functions too. The sample function declaration is below for NMI_Handler().
   But sometimes you may not want to implement all the Handler functions. So,
   you create a simple Default_Handler function and create alias to other
   Handler functions using compiler attribute "alias". Similarly, if "weak"
   compiler attribute allows users to override the Handler functions in user
   program.

   Refer datasheet for getting details on all the Handlers. */
void NMI_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler (void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler (void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void GPIOA_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void GPIOB_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void GPIOC_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void GPIOD_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void GPIOE_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void UART0_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void UART1_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void SSI0_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void I2C0_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void PMW0_FAULT_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PWM0_0_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void PWM0_1_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void PWM0_2_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void QEI0_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void ADC0SS0_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void ADC0SS1_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void ADC0SS2_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void ADC0SS3_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void WDT_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void TIMER0A_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void TIMER0B_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void TIMER1A_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void TIMER1B_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void TIMER2A_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void TIMER2B_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void COMP0_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void COMP1_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void SYSCTL_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void FLASH_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void GPIOF_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void UART2_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void SSI1_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void TIMER3A_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void TIMER3B_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void I2C1_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void QEI1_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void CAN1_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void HIB_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void USB0_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void PWM0_3_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void UDMA_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void UDMAERR_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void ADC1SS0_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void ADC1SS1_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void ADC1SS2_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void ADC1SS3_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void SSI2_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void SSI3_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void UART3_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void UART4_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void UART5_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void UART6_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void UART7_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void I2C2_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void I2C3_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void TIMER4A_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void TIMER4B_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void TIMER5A_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void TIMER5B_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER0A_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER0B_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER1A_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER1B_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER2A_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER2B_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER3A_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER3B_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER4A_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER4B_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER5A_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void WTIMER5B_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void FPU_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void PMW1_0_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void PWM1_1_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void PWM1_2_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void PWM1_3_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void PWM1_FAULT_Handler(void) __attribute__((weak, alias("Default_Handler")));

/* First thing to implement in Startup code is an array of ISR vectors which we
   call as vector table or vectrors, But we have to create this global variable
   in special section called ".isr_vector" (not in ".data" section) for which
   we use compiler attribute "section" */
uint32_t vectors[] __attribute((section(".isr_vector"))) = 
{
    (uint32_t) STACK_START,           // Initial Stack Pointer
    (uint32_t) &Reset_Handler,        // Start of executable code (Initial PC)
    (uint32_t) &NMI_Handler,          // Non-maskable Interrupt Handler
    (uint32_t) &HardFault_Handler,    // Hard Fault Handler
    (uint32_t) &MemManage_Handler,    // MPU Fault Handler
    (uint32_t) &BusFault_Handler,     // Bus Fault Handler
    (uint32_t) &UsageFault_Handler,   // Usage Fault Handler
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    (uint32_t) &SVC_Handler,          // SVCall Handler
    (uint32_t) &DebugMon_Handler,     // Debug Monitor Handler
    0,                                // Reserved
    (uint32_t) &PendSV_Handler,       // PendSV Handler
    (uint32_t) &SysTick_Handler,      // SysTick Handler
    // External Interrupts
    (uint32_t) &GPIOA_Handler,        // GPIO Port A 
    (uint32_t) &GPIOB_Handler,        // GPIO Port B 
    (uint32_t) &GPIOC_Handler,        // GPIO Port C 
    (uint32_t) &GPIOD_Handler,        // GPIO Port D 
    (uint32_t) &GPIOE_Handler,        // GPIO Port E 
    (uint32_t) &UART0_Handler,        // UART0 Rx and Tx 
    (uint32_t) &UART1_Handler,        // UART1 Rx and Tx 
    (uint32_t) &SSI0_Handler,         // SSI0 Rx and Tx 
    (uint32_t) &I2C0_Handler,         // I2C0 Master and Slave 
    (uint32_t) &PMW0_FAULT_Handler,   // PWM Fault 
    (uint32_t) &PWM0_0_Handler,       // PWM Generator 0 
    (uint32_t) &PWM0_1_Handler,       // PWM Generator 1 
    (uint32_t) &PWM0_2_Handler,       // PWM Generator 2 
    (uint32_t) &QEI0_Handler,         // Quadrature Encoder 0 
    (uint32_t) &ADC0SS0_Handler,      // ADC Sequence 0 
    (uint32_t) &ADC0SS1_Handler,      // ADC Sequence 1 
    (uint32_t) &ADC0SS2_Handler,      // ADC Sequence 2 
    (uint32_t) &ADC0SS3_Handler,      // ADC Sequence 3 
    (uint32_t) &WDT_Handler,          // Watchdog timers 0 and 1
    (uint32_t) &TIMER0A_Handler,      // Timer 0 subtimer A 
    (uint32_t) &TIMER0B_Handler,      // Timer 0 subtimer B 
    (uint32_t) &TIMER1A_Handler,      // Timer 1 subtimer A 
    (uint32_t) &TIMER1B_Handler,      // Timer 1 subtimer B 
    (uint32_t) &TIMER2A_Handler,      // Timer 2 subtimer A 
    (uint32_t) &TIMER2B_Handler,      // Timer 2 subtimer B 
    (uint32_t) &COMP0_Handler,        // Analog Comparator 0 
    (uint32_t) &COMP1_Handler,        // Analog Comparator 1 
    0,                                // Reserved on TM4C123GH6PM
    (uint32_t) &SYSCTL_Handler,       // System Control (PLL, OSC, BO) 
    (uint32_t) &FLASH_Handler,        // FLASH and EEPROM Control 
    (uint32_t) &GPIOF_Handler,        // GPIO Port F 
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    (uint32_t) &UART2_Handler,        // UART2 Rx and Tx 
    (uint32_t) &SSI1_Handler,         // SSI1 Rx and Tx 
    (uint32_t) &TIMER3A_Handler,      // Timer 3 subtimer A 
    (uint32_t) &TIMER3B_Handler,      // Timer 3 subtimer B 
    (uint32_t) &I2C1_Handler,         // I2C1 Master and Slave 
    (uint32_t) &QEI1_Handler,         // Quadrature Encoder 1 
    (uint32_t) &CAN0_Handler,         // CAN0 
    (uint32_t) &CAN1_Handler,         // CAN1 
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    (uint32_t) &HIB_Handler,          // Hibernate 
    (uint32_t) &USB0_Handler,         // USB0 
    (uint32_t) &PWM0_3_Handler,       // PWM Generator 3 
    (uint32_t) &UDMA_Handler,         // uDMA Software Transfer 
    (uint32_t) &UDMAERR_Handler,      // uDMA Error 
    (uint32_t) &ADC1SS0_Handler,      // ADC1 Sequence 0 
    (uint32_t) &ADC1SS1_Handler,      // ADC1 Sequence 1 
    (uint32_t) &ADC1SS2_Handler,      // ADC1 Sequence 2 
    (uint32_t) &ADC1SS3_Handler,      // ADC1 Sequence 3 
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    (uint32_t) &SSI2_Handler,         // SSI2 Rx and Tx 
    (uint32_t) &SSI3_Handler,         // SSI3 Rx and Tx 
    (uint32_t) &UART3_Handler,        // UART3 Rx and Tx 
    (uint32_t) &UART4_Handler,        // UART4 Rx and Tx 
    (uint32_t) &UART5_Handler,        // UART5 Rx and Tx 
    (uint32_t) &UART6_Handler,        // UART6 Rx and Tx 
    (uint32_t) &UART7_Handler,        // UART7 Rx and Tx 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    (uint32_t) &I2C2_Handler,         // I2C2 Master and Slave 
    (uint32_t) &I2C3_Handler,         // I2C3 Master and Slave 
    (uint32_t) &TIMER4A_Handler,      // Timer 4 subtimer A 
    (uint32_t) &TIMER4B_Handler,      // Timer 4 subtimer B 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    0,                                // Reserved 
    (uint32_t) &TIMER5A_Handler,      // Timer 5 subtimer A 
    (uint32_t) &TIMER5B_Handler,      // Timer 5 subtimer B 
    (uint32_t) &WTIMER0A_Handler,     // Wide Timer 0 subtimer A 
    (uint32_t) &WTIMER0B_Handler,     // Wide Timer 0 subtimer B 
    (uint32_t) &WTIMER1A_Handler,     // Wide Timer 1 subtimer A 
    (uint32_t) &WTIMER1B_Handler,     // Wide Timer 1 subtimer B 
    (uint32_t) &WTIMER2A_Handler,     // Wide Timer 2 subtimer A 
    (uint32_t) &WTIMER2B_Handler,     // Wide Timer 2 subtimer B 
    (uint32_t) &WTIMER3A_Handler,     // Wide Timer 3 subtimer A 
    (uint32_t) &WTIMER3B_Handler,     // Wide Timer 3 subtimer B 
    (uint32_t) &WTIMER4A_Handler,     // Wide Timer 4 subtimer A 
    (uint32_t) &WTIMER4B_Handler,     // Wide Timer 4 subtimer B 
    (uint32_t) &WTIMER5A_Handler,     // Wide Timer 5 subtimer A 
    (uint32_t) &WTIMER5B_Handler,     // Wide Timer 5 subtimer B 
    (uint32_t) &FPU_Handler,          // FPU ?? System Exception (imprecise)
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM 
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    0,                                // Reserved on TM4C123GH6PM
    (uint32_t) &PMW1_0_Handler,       // PWM 1 Generator 0 
    (uint32_t) &PWM1_1_Handler,       // PWM 1 Generator 1 
    (uint32_t) &PWM1_2_Handler,       // PWM 1 Generator 2 
    (uint32_t) &PWM1_3_Handler,       // PWM 1 Generator 3 
    (uint32_t) &PWM1_FAULT_Handler    // PWM 1 Fault 
};

/* Function Definitions */
void Default_Handler(void)
{
    while(1);
}

void Reset_Handler(void)
{
    /* Copy .data section from FLASH to .data of RAM */
    /* Note: The .data section contains the initialized global and static 
       variable values which have to be copied to SRAM on startup. So, we can
       think of this as copying .data section from FLASH to SRAM. For this we
       must know the start address of .data in .elf file and start address of
       the destination .data section in SRAM. In .elf file, .data section
       starts after .isr_vector, .text and .rodata. So, end of _e_text symbol
       will give the source address of .data on FLASH. The destination address
       for .data on SRAM is given by the symbol _s_data. The size of .data to
       be copied has to be calulated as difference 
       ((uint32_t) &_e_data - (uint32_t) &_s_data) */

    uint32_t size = (uint32_t)&_e_data - (uint32_t)&_s_data;

    uint8_t * pSrc = (uint8_t *) &_e_text;
    uint8_t * pDst = (uint8_t *) &_s_data;

    for (uint32_t i = 0; i < size; i++)
    {
        *pDst++ = *pSrc++;
    }

    /* Initialize .bss section to 0 in SRAM */
    size = (uint32_t)&_e_bss - (uint32_t)&_s_bss;
    pDst = (uint8_t *) &_s_bss;

    for (uint32_t i = 0; i < size; i++)
    {
        *pDst++ = 0;
    }

    /* Call main function */
    main();
}