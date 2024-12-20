/*
 * exti_hardware.c
 *
 *  Created on: Dec 13, 2024
 *      Author: vanlo
 */

#include "exti_hardware.h"

void exti_hardware_init_ex(void) {

	NVIC_SetPriority(EXTI1_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
	NVIC_DisableIRQ(EXTI1_IRQn);

	NVIC_SetPriority(EXTI2_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
	NVIC_DisableIRQ(EXTI2_IRQn);

	NVIC_SetPriority(EXTI3_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
	NVIC_DisableIRQ(EXTI3_IRQn);

	NVIC_SetPriority(EXTI4_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
	NVIC_DisableIRQ(EXTI4_IRQn);

}

void exti_hardware_enable_interrupt(void){

	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
}
void exti_hardware_disable_interrupt(void){

	NVIC_DisableIRQ(EXTI1_IRQn);
	NVIC_DisableIRQ(EXTI2_IRQn);
	NVIC_DisableIRQ(EXTI3_IRQn);
	NVIC_DisableIRQ(EXTI4_IRQn);

}
