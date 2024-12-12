/*
 * pwm_hardware.c
 *
 *  Created on: Dec 12, 2024
 *      Author: vanlo
 */


#include "pwm_hardware.h"

static inline void pwm_hardware_set_frq( const uint32_t  frequency);
static inline void pwm_hardware_start(TIM_TypeDef *TIMx, uint32_t Channels);

void pwm_hardware_init_ex(void){

	pwm_hardware_set_frq(10000);
//	pwm_hardware_set_deadtime(10000);
	PWM_SET_DUTY(0);

	PWM_DISABLE_OUPUT;
	PWM_ENABLE_COUNTER;
}


static inline void pwm_hardware_set_frq( const uint32_t  frequency){

	uint32_t result = 0;
	result = (TMR_FRQ_HZ / frequency /2 );
	PWM_TIMER->ARR = result;
}

static inline void pwm_hardware_start(TIM_TypeDef *TIMx, uint32_t Channels){

	LL_TIM_CC_EnableChannel(TIMx,Channels);
	LL_TIM_EnableAllOutputs(TIMx);
	LL_TIM_EnableCounter(TIMx);
}
