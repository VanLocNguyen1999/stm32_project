/*
 * pwm_hardware.h
 *
 *  Created on: Dec 12, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_PWM_HARDWARE_H_
#define BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_PWM_HARDWARE_H_

#include "tim.h"

#define PWM_TIMER				TIM1
#define TIMER_COUNTER_TOP		PWM_TIMER->ARR

#define TMR_FRQ_HZ				SYS_CLK

#define HS_PWM		LL_TIM_CHANNEL_CH1
#define LS_PWM		LL_TIM_CHANNEL_CH1

#define PWM_ENABLE(x)	do{ \
	LL_TIM_CC_EnableChannel(PWM_TIMER,##x##_PWM); \
}while(0)

#define PWM_DISABLE(x)	do{ \
	LL_TIM_CC_DisableChannel(PWM_TIMER, ##x##_PWM); \
}while(0)

#define PWM_ENABLE_OUPUT 					LL_TIM_EnableAllOutputs(PWM_TIMER)
#define PWM_DISABLE_OUPUT 					LL_TIM_DisableAllOutputs(PWM_TIMER)

#define PWM_ENABLE_COUNTER 					LL_TIM_EnableCounter(PWM_TIMER)
#define PWM_DISABLE_COUNTER 				LL_TIM_DisableCounter(PWM_TIMER)

#define PHASE_PWM_RESET 					PWM_TIMER->CNT = TIMER_COUNTER_TOP - 1;
#define PHASE_PWM_STARTUP 					PWM_TIMER->CNT = 0;

#define PWM_DUTY		PWM_TIMER->CCR1

#define PWM_SET_DUTY(x)  		do{\
					PWM_DUTY=(x);\
					}while(0)

void pwm_hardware_init_ex(void);
#endif /* BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_PWM_HARDWARE_H_ */
