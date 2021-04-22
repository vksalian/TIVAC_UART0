#include <stdint.h>
#include "bsp.h"
#include "led.h"
#include "TM4C123.h"

#define DELAY_NUM             (1600000UL)

uint32_t dummy = 100;

void soft_delay(uint32_t n);

int main (void)
{
    /* Enable Clock for GPIO Port F */
    SYSCTL->RCGCGPIO |= PORTF_CLK;

#if USE_AHB
    /* Enable AHB for GPIO Port F */
    SYSCTL->GPIOHBCTL |= (1U<<5);

    /* Set directions of All LEDs pins to Output */
    led_ahb_dir(OUTPUT, L_RED|L_BLUE|L_GREEN);

    /* Enable Digital functionality for All LED pins */
    led_ahb_dig_en(ENABLE, L_RED|L_BLUE|L_GREEN);

    /* Turn off All LEDs */
    led_ahb_off_all(ATOMIC);
#else
    /* Enable AHB for GPIO Port F */
    SYSCTL->GPIOHBCTL &= ~(1U<<5);

    /* Set directions of All LEDs pins to Output */
    led_apb_dir(OUTPUT, L_RED|L_BLUE|L_GREEN);

    /* Enable Digital functionality for All LED pins */
    led_apb_dig_en(ENABLE, L_RED|L_BLUE|L_GREEN);

    /* Turn off All LEDs */
    led_apb_off_all(ATOMIC);
#endif

    /* SysTick Configuration */
    /* Note: These definitions of registers are part of core_cm4.h file.
     * But TM4C123GH6PM MCU datasheet has different name for these registers.
     * SysTick->LOAD = STRELOAD
     * SysTick->VAL  = STCURRENT
     * SysTick->CTRL = STCTRL */


#if((SYS_CLK_HZ - 1U) > 0x00FFFFFFU)
#error "SysTick RELOAD value overflow"
#endif

    SysTick->LOAD = SYS_CLK_HZ - 1U;
    SysTick->VAL  = 0U;
	SysTick->CTRL = (1U<<0) | (1U<<1) | (1U<<2);

	/* Note: Always check if the SysTick->LOAD is not exceeding / overflowing
	   the 24-bit size. */

	/* Enable Interrupts */
	__enable_irq();

    /* Forever Loop */
    while(1)
    {
#if USE_AHB
        /* ON GREEN LED */
        led_ahb_on(ATOMIC, L_GREEN);

        /* OFF GREEN LED */
        led_ahb_on(ATOMIC, L_GREEN);
#else
        /* ON GREEN LED */
        led_apb_on(ATOMIC, L_GREEN);

        /* OFF GREEN LED */
        led_apb_off(ATOMIC, L_GREEN);

#endif
    }
}

void soft_delay(uint32_t n)
{
    for (uint32_t i = 0; i < n; i++)
    {
        ;
    }
}


