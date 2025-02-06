/*
 * update_interrupt_hardware.h
 *
 *  Created on: Dec 12, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_UPDATE_INTERRUPT_HARDWARE_H_
#define BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_UPDATE_INTERRUPT_HARDWARE_H_

#include "stm32_config.h"

#define UPDATE_TIMER_ISR_TIMER				TIM2
#define UPDATE_TIMER_ISR_IRQ				TIM2_IRQn
#define UPDATE_TIMER_ISR_CLOCK				SYS_TICK
#define UPDATE_1KHZ_ISR_CLEAR_FLAG       	LL_TIM_ClearFlag_UPDATE(UPDATE_TIMER_ISR_TIMER)


void update_timer_it_hw_init_ex(void);
void update_timer_it_hw_enable(void);
void update_timer_it_hw_disable(void);
static inline void update_it_hw_set_freq(const uint32_t freq_Hz) {
	uint32_t result = 0;
	result = LL_TIM_GetPrescaler(UPDATE_TIMER_ISR_TIMER) + 1;
	result = (UPDATE_TIMER_ISR_CLOCK / result / freq_Hz) - 1;
	UPDATE_TIMER_ISR_TIMER->ARR = result;
}

#endif /* BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_UPDATE_INTERRUPT_HARDWARE_H_ */
