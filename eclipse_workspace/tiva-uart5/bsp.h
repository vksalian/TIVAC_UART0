/*
 * bsp.h
 *
 *  Created on: 14-Apr-2021
 *      Author: vksalian
 */

#ifndef BSP_H_
#define BSP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "TM4C123.h"

#define BIT(n)                (1U<<(n))
#define L_RED                 BIT(1)
#define L_BLUE                BIT(2)
#define L_GREEN               BIT(3)
#define PORTF_CLK             BIT(5)

#define USE_AHB               (1)
#define SYS_CLK_HZ            (16000000U)

/* system clock tick [Hz] */
#define BSP_TICKS_PER_SEC     (100U)

typedef enum _gpio_atomic {
    NON_ATOMIC  = 0,
    ATOMIC = 1
}gpio_atomic;

typedef enum _gpio_dir {
    INPUT  = 0,
    OUTPUT = 1
}gpio_dir;

typedef enum _gpio_dig {
    DISABLE = 0,
    ENABLE  = 1
}gpio_dig;

void BSP_init(void);
uint32_t BSP_tickCtr(void);
void BSP_delay(uint32_t ticks);
uint32_t BSP_SysTick_Config(uint32_t ticks);

/* APB */
void BSP_led_apb_dir(gpio_dir dir, uint8_t pin);
void BSP_led_apb_dig_en(gpio_dig en, uint8_t pin);
void BSP_led_apb_toggle(gpio_atomic atom, uint8_t pin);
void BSP_led_apb_on(gpio_atomic atom, uint8_t pin);
void BSP_led_apb_off(gpio_atomic atom, uint8_t pin);
void BSP_led_apb_off_all(gpio_atomic atom);

/* AHB */
void BSP_led_ahb_dir(gpio_dir dir, uint8_t pin);
void BSP_led_ahb_dig_en(gpio_dig en, uint8_t pin);
void BSP_led_ahb_toggle(gpio_atomic atom, uint8_t pin);
void BSP_led_ahb_on(gpio_atomic atom, uint8_t pin);
void BSP_led_ahb_off(gpio_atomic atom, uint8_t pin);
void BSP_led_ahb_off_all(gpio_atomic atom);

#ifdef __cplusplus
}
#endif

#endif /* BSP_H_ */
