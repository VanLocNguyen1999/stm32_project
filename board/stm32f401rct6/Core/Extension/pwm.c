/*
 * pwm.c
 *
 *  Created on: Feb 22, 2025
 *      Author: Admin
 */

#include "pwm.h"

void pwm_init_ex(void){

	pwm_set_frq(1000);
	PWM_SET_DUTY(0);
	PWM_DISABLE_OUTPUT;
	LL_TIM_EnableCounter(PWM_TIMER);
}
void pwm_set_frq(uint32_t frq){

	uint32_t result = 0;

	result = (PWM_FRQ_HZ/frq/2) - 1;
	PWM_TIMER->ARR = result;
}

