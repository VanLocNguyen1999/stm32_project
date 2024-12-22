/*
 * update_interrupt_hardware.c
 *
 *  Created on: Dec 12, 2024
 *      Author: vanlo
 */

#include "update_interrupt_hardware.h"

static inline void update_it_hw_start(void) ;

void update_1khz_it_hw_init_ex(void) {

	update_it_hw_set_freq(500);
	update_it_hw_start();
	NVIC_SetPriority(UPDATE_1KHZ_ISR_IRQ,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
	update_1khz_it_hw_disable();
}
static inline void update_it_hw_start(void) {

	LL_TIM_EnableIT_UPDATE(UPDATE_1KHZ_ISR_TIMER);
	LL_TIM_EnableCounter(UPDATE_1KHZ_ISR_TIMER);
}


void update_it_hw_change_freq(const uint32_t freq_Hz) {
	uint32_t result = 0;
	result = LL_TIM_GetPrescaler(UPDATE_1KHZ_ISR_TIMER) + 1;
	result = (UPDATE_1KHZ_ISR_CLOCK / result / freq_Hz) - 1;
	UPDATE_1KHZ_ISR_TIMER->ARR = result;
}

void update_1khz_it_hw_enable(void) {
    NVIC_EnableIRQ(UPDATE_1KHZ_ISR_IRQ);
}

void update_1khz_it_hw_disable(void) {
    NVIC_DisableIRQ(UPDATE_1KHZ_ISR_IRQ);
}
