/*
 * exti_hardware.c
 *
 *  Created on: Dec 13, 2024
 *      Author: vanlo
 */

#include "exti_hardware.h"

void exti_hardware_init_ex(void) {

	NVIC_SetPriority(EXTI9_5_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
	NVIC_DisableIRQ(EXTI9_5_IRQn);
}

void exti_hardware_enable_interrupt(void){

	NVIC_EnableIRQ(EXTI9_5_IRQn);
}
void exti_hardware_disable_interrupt(void){

	NVIC_DisableIRQ(EXTI9_5_IRQn);

}
