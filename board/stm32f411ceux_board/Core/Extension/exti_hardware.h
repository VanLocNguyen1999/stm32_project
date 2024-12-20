/*
 * exti_hardware.h
 *
 *  Created on: Dec 13, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_

#include "stm32_config.h"

#define UPDATE_EXTI_C1_ISR_IRQ					EXTI1_IRQHandler
#define UPDATE_EXTI_C1_ISR_FLAG  		     	LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_1)
#define UPDATE_EXTI_C1_ISR_CLEAR_FLAG       	LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_1)

#define UPDATE_EXTI_C2_ISR_IRQ					EXTI2_IRQHandler
#define UPDATE_EXTI_C2_ISR_FLAG  		     	LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_2)
#define UPDATE_EXTI_C2_ISR_CLEAR_FLAG       	LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_2)

#define UPDATE_EXTI_C3_ISR_IRQ					EXTI3_IRQHandler
#define UPDATE_EXTI_C3_ISR_FLAG  		     	LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_3)
#define UPDATE_EXTI_C3_ISR_CLEAR_FLAG       	LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_3)

#define UPDATE_EXTI_C4_ISR_IRQ					EXTI4_IRQHandler
#define UPDATE_EXTI_C4_ISR_FLAG  		     	LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_4)
#define UPDATE_EXTI_C4_ISR_CLEAR_FLAG       	LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_4)
void exti_hardware_init_ex(void);
void exti_hardware_enable_interrupt(void);
void exti_hardware_disable_interrupt(void);
#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_ */
