#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "led.h"

#define DELAY_NUM             (1000000UL)

void soft_delay(uint32_t n);

int main (void)
{
    /* Enable Clock for GPIO Port F */
    SYSCTL->RCGCGPIO |= PORTF_CLK;

    /* Set directions of All LEDs pins to Output */
    led_dir(OUTPUT, L_RED|L_BLUE|L_GREEN);

    /* Enable Digital functionality for All LED pins */
    led_dig_en(ENABLE, L_RED|L_BLUE|L_GREEN);

    /* Turn off All LEDs */
    led_off_all();

    /* Forever Loop */
    while(1)
    {
        /* Turn off All LEDs */
        led_off_all();

        /* Turn On RED LED */
        led_on(L_RED);

        /* Software delay */
        soft_delay(DELAY_NUM);

        /* Turn off All LEDs */
        led_off_all();

        /* Turn On BLUE LED */
        led_on(L_BLUE);

        /* Software delay */
        soft_delay(DELAY_NUM);

        /* Turn off All LEDs */
        led_off_all();

        /* Turn On GREEN LED */
        led_on(L_GREEN);

        /* Software delay */
        soft_delay(DELAY_NUM);
    }
}

void soft_delay(uint32_t n)
{
    for (uint32_t i = 0; i < n; i++)
    {
        ;
    }
}

/* This function will override the weak function */
void HardFault_Handler(void)
{
    while(1);
}

/* This function will override the weak function */
void NMI_Handler(void)
{
    while(1);
}