/*
 * exti_hardware.h
 *
 *  Created on: Dec 13, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_

#include "stm32_config.h"

#define UPDATE_EXTI_C1_ISR						LL_EXTI_LINE_1
#define UPDATE_EXTI_C1_ISR_IRQ					EXTI1_IRQHandler(void)
#define UPDATE_EXTI_C1_ISR_FLAG  		     	LL_EXTI_IsActiveFlag_0_31(UPDATE_EXTI_C1_ISR)
#define UPDATE_EXTI_C1_ISR_CLEAR_FLAG       	LL_EXTI_ClearFlag_0_31(UPDATE_EXTI_C1_ISR)

#define UPDATE_EXTI_C2_ISR						LL_EXTI_LINE_2
#define UPDATE_EXTI_C2_ISR_IRQ					EXTI2_IRQHandler(void)
#define UPDATE_EXTI_C2_ISR_FLAG  		     	LL_EXTI_IsActiveFlag_0_31(UPDATE_EXTI_C2_ISR)
#define UPDATE_EXTI_C2_ISR_CLEAR_FLAG       	LL_EXTI_ClearFlag_0_31(UPDATE_EXTI_C2_ISR)

#define UPDATE_EXTI_C3_ISR						LL_EXTI_LINE_3
#define UPDATE_EXTI_C3_ISR_IRQ					EXTI3_IRQHandler(void)
#define UPDATE_EXTI_C3_ISR_FLAG  		     	LL_EXTI_IsActiveFlag_0_31(UPDATE_EXTI_C3_ISR)
#define UPDATE_EXTI_C3_ISR_CLEAR_FLAG       	LL_EXTI_ClearFlag_0_31(UPDATE_EXTI_C3_ISR)

#define UPDATE_EXTI_C4_ISR						LL_EXTI_LINE_4
#define UPDATE_EXTI_C4_ISR_IRQ					EXTI4_IRQHandler(void)
#define UPDATE_EXTI_C4_ISR_FLAG  		     	LL_EXTI_IsActiveFlag_0_31(UPDATE_EXTI_C4_ISR)
#define UPDATE_EXTI_C4_ISR_CLEAR_FLAG       	LL_EXTI_ClearFlag_0_31(UPDATE_EXTI_C4_ISR)
void exti_hardware_init_ex(void);
void exti_hardware_enable_interrupt(void);
void exti_hardware_disable_interrupt(void);
#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_ */
