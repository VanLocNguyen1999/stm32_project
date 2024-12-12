/*
 * update_interrupt_hardware.c
 *
 *  Created on: Dec 12, 2024
 *      Author: vanlo
 */

#include "update_interrupt_hardware.h"

static inline void update_it_hw_start(void) ;

void update_1khz_it_hw_init_ex(void) {

	update_it_hw_start();
	NVIC_SetPriority(UPDATE_IT_TIM2_IRQ,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
	update_1khz_it_hw_disable();
}
static inline void update_it_hw_start(void) {

	LL_TIM_EnableIT_UPDATE(UPDATE_IT_TIM2);
	LL_TIM_EnableCounter(UPDATE_IT_TIM2);
}

void update_1khz_it_hw_enable(void) {
	NVIC_EnableIRQ(UPDATE_IT_TIM2_IRQ);
}

void update_1khz_it_hw_disable(void) {
	NVIC_DisableIRQ(UPDATE_IT_TIM2_IRQ);
}
void update_it_hw_change_freq(const uint8_t freq_Hz) {
	uint32_t result = 0;
	result = LL_TIM_GetPrescaler(UPDATE_IT_TIM2) + 1;
	result = (UPDATE_IT_TIM2_CLOCK / result / freq_Hz) - 1;
	UPDATE_IT_TIM2->ARR = result;
}

