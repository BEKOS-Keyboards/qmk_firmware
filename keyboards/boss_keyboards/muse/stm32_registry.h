#pragma once

#undef  STM32_HAS_GPIOD
#define STM32_HAS_GPIOD                     TRUE

#undef  STM32_GPIO_EN_MASK
#define STM32_GPIO_EN_MASK          (RCC_AHB2ENR_GPIOAEN |          \
                                     RCC_AHB2ENR_GPIOBEN |          \
                                     RCC_AHB2ENR_GPIOCEN |          \
                                     RCC_AHB2ENR_GPIODEN |          \
                                     RCC_AHB2ENR_GPIOHEN)

#include_next <stm32_registry.h>
