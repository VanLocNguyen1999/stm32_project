/*
 * main.c
 *
 *  Created on: Mar 1, 2025
 *      Author: Admin
 */

#include "board.h"

uint16_t AD_RES = 0;

int main(void){

	board_hardware_init_ex();

	PWM_TIMER->CCR1 = 0.2*PWM_TIMER_TOP_COUNTER;
	PWM_STARTUP;
	PWM_ENABLE_CHANNEL;
	PWM_ENABLE_OUTPUT;
    // Calibrate The ADC On Power-Up For Better Accuracy
    HAL_ADCEx_Calibration_Start(&hadc1);
	HAL_ADC_Start(&hadc1);
	// Poll ADC1 Perihperal & TimeOut = 1mSec
	HAL_ADC_PollForConversion(&hadc1, 100);
	// Read The ADC Conversion Result & Map It To PWM DutyCycle
	AD_RES = HAL_ADC_GetValue(&hadc1);
	while(1){

		// Start ADC Conversion
		HAL_ADC_Start(&hadc1);
		// Poll ADC1 Perihperal & TimeOut = 1mSec
		HAL_ADC_PollForConversion(&hadc1, 100);
		// Read The ADC Conversion Result & Map It To PWM DutyCycle
		AD_RES = HAL_ADC_GetValue(&hadc1);
		delay_ms(1);
		if(AD_RES > 2040){
			lcd_gotoxy(8, 1);
			lcd_puts("volt > 2.5");
		}else {
			lcd_gotoxy(8, 1);
			lcd_puts("volt < 2.5");
		}
	}
}


