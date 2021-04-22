#include "led.h"

void led_dir(gpio_dir dir, uint8_t pin)
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

void led_dig_en(gpio_dig en, uint8_t pin)
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

void led_on(uint8_t pin)
{
    GPIOF->DATA |= pin;
}

void led_off(uint8_t pin)
{
    GPIOF->DATA &= ~(pin);
}

void led_off_all(void)
{
    GPIOF->DATA &= ~(L_RED|L_BLUE|L_GREEN);
}