#pragma once

#include_next <mcuconf.h>

#undef STM32L443_MCUCONF
#define STM32L433_MCUCONF

// Setup clock to use the onboard oscillator
#undef STM32_HSI16_ENABLED
#define STM32_HSI16_ENABLED                 FALSE

#undef STM32_HSI48_ENABLED
#define STM32_HSI48_ENABLED                	TRUE

#undef STM32_HSE_ENABLED
#define STM32_HSE_ENABLED                   TRUE

#undef STM32_SW
#define STM32_SW                            STM32_SW_HSE

#undef STM32_PLLSRC
#define STM32_PLLSRC                        STM32_PLLSRC_HSE

#undef STM32_PLLM_VALUE
#define STM32_PLLM_VALUE                    3

#undef STM32_PLLN_VALUE
#define STM32_PLLN_VALUE                    12

#undef STM32_PLLQ_VALUE
#define STM32_PLLQ_VALUE                    4

#undef STM32_PLLR_VALUE
#define STM32_PLLR_VALUE                    4

#undef STM32_PLLSAI1N_VALUE
#define STM32_PLLSAI1N_VALUE                12

#undef STM32_PLLSAI1Q_VALUE
#define STM32_PLLSAI1Q_VALUE                4

#undef STM32_PLLSAI1R_VALUE
#define STM32_PLLSAI1R_VALUE                4

#undef STM32_CLK48SEL
#define STM32_CLK48SEL                      STM32_CLK48SEL_PLL


// Setup I2C for RGB LEDs and EEPROM
#undef STM32_I2C_USE_DMA
#define STM32_I2C_USE_DMA					TRUE

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1                  TRUE


// Setup 'serial' Console for debugging
#undef STM32_UART_USE_USART2
#define STM32_UART_USE_USART2               TRUE

