#ifndef LED_H
#define LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "tm4c123gh6pm.h"

#define BIT(n)       (1U<<(n))
#define L_RED        BIT(1)
#define L_BLUE       BIT(2)
#define L_GREEN      BIT(3)
#define PORTF_CLK    BIT(5)

typedef enum _gpio_dir {
    INPUT  = 0,
    OUTPUT = 1
}gpio_dir;

typedef enum _gpio_dig {
    DISABLE = 0,
    ENABLE  = 1
}gpio_dig;

void led_dir(gpio_dir dir, uint8_t pin);
void led_dig_en(gpio_dig en, uint8_t pin);

void led_on(uint8_t pin);
void led_off(uint8_t pin);
void led_off_all(void);

#ifdef __cplusplus
}
#endif

#endif /* LED_H */