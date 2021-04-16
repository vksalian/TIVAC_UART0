/*
 * bsp.c
 *
 *  Created on: 14-Apr-2021
 *      Author: vksalian
 */

#include "bsp.h"
#include "led.h"


/* This function will override the weak function */
void HardFault_Handler(void)
{
	/* TODO : Safely Handle the faults without forever loop */
    while(1);
}

/* This function will override the weak function */
void NMI_Handler(void)
{
	/* TODO : Safely Handle the faults without forever loop */
    while(1);
}

/* This function will override the weak function */
void SysTick_Handler(void)
{
#if USE_AHB
        /* Toggle RED LED */
        led_ahb_toggle(ATOMIC, L_RED);
#else
        /* Toggle RED LED */
        led_apb_toggle(ATOMIC, L_RED);
#endif
}
