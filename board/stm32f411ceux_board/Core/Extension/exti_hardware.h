/*
 * exti_hardware.h
 *
 *  Created on: Dec 13, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_

#include "stm32_config.h"

#define UPDATE_EXTI_ISR						LL_EXTI_LINE_3
#define UPDATE_EXTI_ISR_IRQ					EXTI3_IRQHandler(void)
#define UPDATE_EXTI_ISR_FLAG  		     	LL_EXTI_IsActiveFlag_0_31(UPDATE_EXTI_ISR)
#define UPDATE_EXTI_ISR_CLEAR_FLAG       	LL_EXTI_ClearFlag_0_31(UPDATE_EXTI_ISR)


void exti_hardware_init_ex(void);

static inline void exti_hardware_enable_interrupt(void){

	NVIC_EnableIRQ(EXTI3_IRQn);
}
static inline void exti_hardware_disable_interrupt(void){

	NVIC_DisableIRQ(EXTI3_IRQn);
}

#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_EXTI_HARDWARE_H_ */
