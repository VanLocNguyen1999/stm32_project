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

#define UPDATE_IT_TIM2					TIM2
#define UPDATE_IT_TIM2_IRQ				TIM2_IRQn
#define UPDATE_IT_TIM2_CLOCK			SYS_CLK
#define UPDATE_IT_TIM2_CLEAR_FLAG       LL_TIM_ClearFlag_UPDATE(UPDATE_IT_TIM2)


void update_1khz_it_hw_init_ex(void);
void update_1khz_it_hw_enable(void);
void update_1khz_it_hw_disable(void);
void update_it_hw_change_freq(const uint8_t freq_Hz);

static inline void update_disable_all_interrupt(void);
static inline void update_enable_all_interrupt(void);

static inline void update_disable_all_interrupt(void) {

	__disable_irq();
}
static inline void update_enable_all_interrupt(void) {

	__enable_irq();
}

#endif /* BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_UPDATE_INTERRUPT_HARDWARE_H_ */
