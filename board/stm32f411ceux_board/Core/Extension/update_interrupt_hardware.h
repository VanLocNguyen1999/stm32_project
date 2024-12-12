/*
 * update_interrupt_hardware.h
 *
 *  Created on: Dec 12, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_UPDATE_INTERRUPT_HARDWARE_H_
#define BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_UPDATE_INTERRUPT_HARDWARE_H_

#include "tim.h"
#include "stm32_config.h"

#define UPDATE_1KHZ_ISR_TIMER				TIM2
#define UPDATE_1KHZ_ISR_IRQ					TIM2_IRQn
#define UPDATE_1KHZ_ISR_CLOCK				SYS_CLK
#define UPDATE_1KHZ_ISR_CLEAR_FLAG       	LL_TIM_ClearFlag_UPDATE(UPDATE_1KHZ_ISR_TIMER)


void update_1khz_it_hw_init_ex(void);
void update_it_hw_change_freq(const uint32_t freq_Hz);
static inline void update_1khz_it_hw_enable(void) {
	NVIC_EnableIRQ(UPDATE_1KHZ_ISR_IRQ);
}

static inline void update_1khz_it_hw_disable(void) {
	NVIC_DisableIRQ(UPDATE_1KHZ_ISR_IRQ);
}
#endif /* BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_UPDATE_INTERRUPT_HARDWARE_H_ */
