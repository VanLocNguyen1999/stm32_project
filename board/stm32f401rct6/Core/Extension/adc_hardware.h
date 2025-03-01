/*
 * adc_hardware.h
 *
 *  Created on: Feb 22, 2025
 *      Author: Admin
 */

#ifndef BOARD_CORE_EXTENSION_ADC_HARDWARE_H_
#define BOARD_CORE_EXTENSION_ADC_HARDWARE_H_

#include "pwm.h"
#include "stm32_config.h"
#include "adc.h"

#define ADC_NUMBER					2
#define ADC_TIMER					PWM_TIMER
extern uint32_t adc1_buffer[ADC_NUMBER];

void adc_hardware_init_ex(void);

#endif /* BOARD_CORE_EXTENSION_ADC_HARDWARE_H_ */
