#include <stdint.h>
#include "bsp.h"

int main (void)
{
    /* BSP_Init */
	BSP_init();

    /* Forever Loop */
    while(1)
    {
#if USE_AHB
        /* ON GREEN LED */
    	BSP_led_ahb_on(ATOMIC, L_GREEN);

    	/* Delay (ON) */
    	BSP_delay(BSP_TICKS_PER_SEC / 4U);

        /* OFF GREEN LED */
    	BSP_led_ahb_off(ATOMIC, L_GREEN);

    	/* Delay (OFF) */
        BSP_delay(BSP_TICKS_PER_SEC * 3U / 4U);
#else
        /* ON GREEN LED */
        BSP_led_apb_on(ATOMIC, L_GREEN);

        /* Delay (ON) */
        BSP_delay(BSP_TICKS_PER_SEC / 4U);

        /* OFF GREEN LED */
        BSP_led_apb_off(ATOMIC, L_GREEN);

        /* Delay (OFF) */
        BSP_delay(BSP_TICKS_PER_SEC * 3U / 4U);

#endif
    }
}
