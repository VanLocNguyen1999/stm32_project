/*
 * gpio_mode.h
 *
 *  Created on: Jan 17, 2025
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_GPIO_MODE_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_GPIO_MODE_H_

#include "board.h"
#include "delay_hardware.h"


#define PORT_READ(port, pinmask)      		((port->IDR & pinmask) != 0) // Đọc trạng thái chân
#define PORT_WRITE_LOW(port, pinmask) 		(port->BSRR = ((uint32_t)pinmask << 16)) // Đặt chân LOW
#define PORT_WRITE_HIGH(port, pinmask) 		(port->BSRR = pinmask) // Đặt chân HIGH

#define PORT_SET_MODE_INPUT(port, pinmask) do { \
												LL_GPIO_SetPinMode(port, pinmask, LL_GPIO_MODE_INPUT); \
												LL_GPIO_SetPinPull(port, pinmask, LL_GPIO_PULL_NO); \
											} while(0)

#define PORT_SET_MODE_OUTPUT(port, pinmask) do { \
												LL_GPIO_SetPinMode(port, pinmask, LL_GPIO_MODE_OUTPUT); \
												LL_GPIO_SetPinPull(port, pinmask, LL_GPIO_PULL_NO); \
												LL_GPIO_SetPinSpeed(port, pinmask, LL_GPIO_SPEED_FREQ_VERY_HIGH); \
											} while(0)

#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_GPIO_MODE_H_ */
