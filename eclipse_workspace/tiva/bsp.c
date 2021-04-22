/*
 * bsp.c
 *
 *  Created on: 14-Apr-2021
 *      Author: vksalian
 */

#include "bsp.h"
#include "led.h"

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

__attribute__((naked)) void assert_failed (char const *file, int line) {
    /* TBD: damage control */
    NVIC_SystemReset(); /* reset the system */
}

