#ifndef LED_H
#define LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "TM4C123.h"
#include "bsp.h"

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

/* APB */
void led_apb_dir(gpio_dir dir, uint8_t pin);
void led_apb_dig_en(gpio_dig en, uint8_t pin);
void led_apb_toggle(gpio_atomic atom, uint8_t pin);
void led_apb_on(gpio_atomic atom, uint8_t pin);
void led_apb_off(gpio_atomic atom, uint8_t pin);
void led_apb_off_all(gpio_atomic atom);

/* AHB */
void led_ahb_dir(gpio_dir dir, uint8_t pin);
void led_ahb_dig_en(gpio_dig en, uint8_t pin);
void led_ahb_toggle(gpio_atomic atom, uint8_t pin);
void led_ahb_on(gpio_atomic atom, uint8_t pin);
void led_ahb_off(gpio_atomic atom, uint8_t pin);
void led_ahb_off_all(gpio_atomic atom);

#ifdef __cplusplus
}
#endif

#endif /* LED_H */
