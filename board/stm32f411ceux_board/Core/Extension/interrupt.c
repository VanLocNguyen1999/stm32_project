/*
 * interrupt.c
 *
 *  Created on: Dec 14, 2024
 *      Author: vanlo
 */

#include "interrupt.h"

void interrupt_hardware_init(void){

	exti_hardware_init_ex();
	update_timer_it_hw_init_ex();
}

void interrupt_hardware_enable(void){

	update_timer_it_hw_enable();
	exti_hardware_enable_interrupt();
}

void interrupt_hardware_disable(void){

	update_timer_it_hw_disable();
	exti_hardware_disable_interrupt();
}
