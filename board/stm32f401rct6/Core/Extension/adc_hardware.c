/*
 * adc_hardware.c
 *
 *  Created on: Feb 22, 2025
 *      Author: Admin
 */

#include "adc_hardware.h"

uint32_t adc1_buffer[ADC_NUMBER] = {0};

static inline void adc_hardware_set_duty_trigger(uint32_t duty){

	ADC_TIMER->CCR4 = duty;
	LL_TIM_CC_EnableChannel(ADC_TIMER,ADC_TRIG_CHANNEL);
}

static inline void adc_hardware_set_trigger(void){


}
