/*
 * board.h
 *
 *  Created on: Feb 21, 2025
 *      Author: Admin
 */

#ifndef CORE_EXTENSION_BOARD_H_
#define CORE_EXTENSION_BOARD_H_

#include "delay_hardware.h"
#include "lcd.h"
#include "pwm.h"
#include "stm32_config.h"

#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"

void board_hardware_init_ex(void);

#endif /* CORE_EXTENSION_BOARD_H_ */
