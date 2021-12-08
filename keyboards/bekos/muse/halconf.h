#pragma once

#define HAL_USE_I2C TRUE
#define HAL_USE_PAL  TRUE
#define HAL_USE_UART TRUE
#define UART_USE_WAIT TRUE
#define HAL_USE_SERIAL FALSE

#include_next <halconf.h>
