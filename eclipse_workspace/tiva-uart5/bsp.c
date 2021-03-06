/*
 * bsp.c
 *
 *  Created on: 14-Apr-2021
 *      Author: vksalian
 */

#include "bsp.h"

/* tick counter variable. To prevent from compiler optimization, we used volatile */
static uint32_t volatile l_tickCtr;

/* This function will override the weak function */
void SysTick_Handler(void)
{
    ++l_tickCtr;
}

uint32_t BSP_tickCtr(void)
{
	uint32_t tickCtr;

	__disable_irq();
	tickCtr = l_tickCtr;
	__enable_irq();

	return tickCtr;
}

void BSP_delay(uint32_t ticks)
{
	uint32_t start = BSP_tickCtr();
	while ((BSP_tickCtr() - start) < ticks)
	{
		/* Do nothing */
	}
}

uint32_t BSP_SysTick_Config(uint32_t ticks)
{
	if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk)
	  {
	    return (1UL);                                                   /* Reload value impossible */
	  }

	  SysTick->LOAD  = (uint32_t)(ticks - 1UL);                         /* set reload register */
	  SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */
	  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
	                   SysTick_CTRL_TICKINT_Msk   |
	                   SysTick_CTRL_ENABLE_Msk;                         /* Enable SysTick IRQ and SysTick Timer */
	  return (0UL);
}

void BSP_init(void)
{
		/* Enable Clock for GPIO Port F */
	    SYSCTL->RCGCGPIO |= PORTF_CLK;

	#if USE_AHB
	    /* Enable AHB for GPIO Port F */
	    SYSCTL->GPIOHBCTL |= (1U<<5);

	    /* Set directions of All LEDs pins to Output */
	    BSP_led_ahb_dir(OUTPUT, L_RED|L_BLUE|L_GREEN);

	    /* Enable Digital functionality for All LED pins */
	    BSP_led_ahb_dig_en(ENABLE, L_RED|L_BLUE|L_GREEN);

	    /* Turn off All LEDs */
	    BSP_led_ahb_off_all(ATOMIC);
	#else
	    /* Enable AHB for GPIO Port F */
	    SYSCTL->GPIOHBCTL &= ~(1U<<5);

	    /* Set directions of All LEDs pins to Output */
	    BSP_led_apb_dir(OUTPUT, L_RED|L_BLUE|L_GREEN);

	    /* Enable Digital functionality for All LED pins */
	    BSP_led_apb_dig_en(ENABLE, L_RED|L_BLUE|L_GREEN);

	    /* Turn off All LEDs */
	    BSP_led_apb_off_all(ATOMIC);
	#endif

	    /* Note: Here we are directly calling the functions to configure SysTick
	     * timer.
	     */
	    SystemCoreClockUpdate();

	    /* Note: I tried using the direct function "SysTick_Config", but
	     * the function has some ASM statements which did not allow me to
	     * debug the code in eclipse, hence written a new function named
	     * BSP_SysTick_Config and used below.
	     */
	    BSP_SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);

		/* Enable Interrupts */
		__enable_irq();
}

/* APB */

void BSP_led_apb_dir(gpio_dir dir, uint8_t pin)
{
    if (dir == OUTPUT)
    {
        GPIOF->DIR |= pin;
    }
    else
    {
        GPIOF->DIR &= ~(pin);
    }
}

void BSP_led_apb_dig_en(gpio_dig en, uint8_t pin)
{
    if (en == ENABLE)
    {
        GPIOF->DEN |= pin;
    }
    else
    {
        GPIOF->DEN &= ~(pin);
    }
}

void BSP_led_apb_toggle(gpio_atomic atom, uint8_t pin)
{
	if(atom == ATOMIC)
	{
		GPIOF->DATA_BITS[pin] ^= pin;
	}
	else
	{
		GPIOF->DATA ^= pin;
	}
}

void BSP_led_apb_on(gpio_atomic atom, uint8_t pin)
{
	if(atom == ATOMIC)
	{
		GPIOF->DATA_BITS[pin] = pin;
		/* The below is the way to use atomic Write. The atomic write makes use
		 * of initial 256 registers (0-255) with each 32-bit register for 1 bit
		 * modification (8pins * 32 = 256) */
		 // *((volatile unsigned int *)(0x40025000 + (pin << 2))) = pin;
	}
	else
	{
		GPIOF->DATA |= pin;
	}
}

void BSP_led_apb_off(gpio_atomic atom, uint8_t pin)
{
	if(atom == ATOMIC)
	{
		GPIOF->DATA_BITS[pin] = 0;
		/* The below is the way to use atomic Write. The atomic write makes use
		 * of initial 256 registers (0-255) with each 32-bit register for 1 bit
		 * modification (8pins * 32 = 256) */
		 // *((volatile unsigned int *)(0x40025000 + (pin << 2))) = pin;
	}
	else
	{
		GPIOF->DATA &= ~(pin);
	}
}

void BSP_led_apb_off_all(gpio_atomic atom)
{
	if(atom == ATOMIC)
	{
		GPIOF->DATA_BITS[L_RED] = 0;
		GPIOF->DATA_BITS[L_BLUE] = 0;
		GPIOF->DATA_BITS[L_GREEN] = 0;
	}
	else
	{
		GPIOF->DATA &= ~(L_RED|L_BLUE|L_GREEN);
	}
}

/* AHB */
void BSP_led_ahb_dir(gpio_dir dir, uint8_t pin)
{
    if (dir == OUTPUT)
    {
        GPIOF_AHB->DIR |= pin;
    }
    else
    {
        GPIOF_AHB->DIR &= ~(pin);
    }
}

void BSP_led_ahb_dig_en(gpio_dig en, uint8_t pin)
{
    if (en == ENABLE)
    {
        GPIOF_AHB->DEN |= pin;
    }
    else
    {
        GPIOF_AHB->DEN &= ~(pin);
    }
}

void BSP_led_ahb_toggle(gpio_atomic atom, uint8_t pin)
{
	if(atom == ATOMIC)
	{
		GPIOF_AHB->DATA_BITS[pin] ^= pin;
	}
	else
	{
		GPIOF_AHB->DATA ^= pin;
	}
}

void BSP_led_ahb_on(gpio_atomic atom, uint8_t pin)
{
	if(atom == ATOMIC)
	{
		GPIOF_AHB->DATA_BITS[pin] = pin;

		/* The below is the way to use atomic Write. The atomic write makes use
			 * of initial 256 registers (0-255) with each 32-bit register for 1 bit
			 * modification (8pins * 32 = 256) */
		    // *((volatile unsigned int *)(0x40025000 + (pin << 2))) = pin;
	}
	else
	{
		GPIOF_AHB->DATA |= pin;
	}
}

void BSP_led_ahb_off(gpio_atomic atom, uint8_t pin)
{
	if(atom == ATOMIC)
	{
		GPIOF_AHB->DATA_BITS[pin] = 0;

		/* The below is the way to use atomic Write. The atomic write makes use
		 * of initial 256 registers (0-255) with each 32-bit register for 1 bit
		 * modification (8pins * 32 = 256) */
		 // *((volatile unsigned int *)(0x40025000 + (pin << 2))) = pin;
	}
	else
	{
		GPIOF_AHB->DATA &= ~(pin);
	}
}

void BSP_led_ahb_off_all(gpio_atomic atom)
{
	if(atom == ATOMIC)
	{
		GPIOF_AHB->DATA_BITS[L_RED] = 0;
		GPIOF_AHB->DATA_BITS[L_BLUE] = 0;
		GPIOF_AHB->DATA_BITS[L_GREEN] = 0;
	}
	else
	{
		GPIOF_AHB->DATA &= ~(L_RED|L_BLUE|L_GREEN);
	}
}

__attribute__((naked)) void assert_failed (char const *file, int line) {
    /* TBD: damage control */
    NVIC_SystemReset(); /* reset the system */
}

