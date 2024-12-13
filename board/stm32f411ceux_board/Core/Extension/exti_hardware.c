/*
 * exti_hardware.c
 *
 *  Created on: Dec 13, 2024
 *      Author: vanlo
 */

#include "exti_hardware.h"

void exti_hardware_init_ex(void){

	NVIC_SetPriority(EXTI3_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(),
			1, 0));
	exti_hardware_disable_interrupt();
}
