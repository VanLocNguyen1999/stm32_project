/*
 * exti_hardware.h
 *
 *  Created on: Dec 13, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_

#include "stm32_config.h"

#define UPDATE_EXTI9_5_ISR_IRQ					EXTI9_5_IRQHandler
#define UPDATE_EXTI9_5_ISR_FLAG  		     	LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_5)
#define UPDATE_EXTI9_5_ISR_CLEAR_FLAG       	LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_5)

#define UPDATE_EXTI5_FLAG       				LL_GPIO_IsInputPinSet(EXTI5_GPIO_Port, EXTI5_Pin)

void exti_hardware_init_ex(void);
void exti_hardware_enable_interrupt(void);
void exti_hardware_disable_interrupt(void);
#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_ */
