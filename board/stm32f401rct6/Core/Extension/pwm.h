/*
 * pwm.h
 *
 *  Created on: Feb 22, 2025
 *      Author: Admin
 */

#ifndef BOARD_CORE_EXTENSION_PWM_H_
#define BOARD_CORE_EXTENSION_PWM_H_

#include "stm32_config.h"
#include "tim.h"

#define PWM_FRQ_HZ						SYS_CLOCK
#define PWM_FRQ_MHZ						SYS_CLOCK/1000000

#define PWM_TIMER						TIM3
#define PWM_CHANNEL						LL_TIM_CHANNEL_CH1
#define ADC_TRIG_CHANNEL				LL_TIM_CHANNEL_CH4
#define PWM_TIMER_TOP_COUNTER			PWM_TIMER->ARR

#define PWM_ENABLE_CHANNEL				LL_TIM_CC_EnableChannel(PWM_TIMER,PWM_CHANNEL)
#define PWM_DISABLE_CHANNEL				LL_TIM_CC_DisableChannel(PWM_TIMER,PWM_CHANNEL)

#define PWM_ENABLE_OUTPUT				LL_TIM_EnableAllOutputs(PWM_TIMER)
#define PWM_DISABLE_OUTPUT				LL_TIM_DisableAllOutputs(PWM_TIMER)

#define PWM_DUTY						PWM_TIMER->CCR1
#define PWM_SET_DUTY(x)	        		PWM_DUTY = (x)

#define PHASE_PWM_RESET 				PWM_TIMER->CNT = PWM_TIMER_TOP_COUNTER - 1;
#define PWM_STARTUP						PWM_TIMER->CNT = 0;


void pwm_init_ex(void);
void pwm_set_frq(uint32_t frq);
#endif /* BOARD_CORE_EXTENSION_PWM_H_ */
