/*
 * interrupt.h
 *
 *  Created on: Dec 14, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_INTERRUPT_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_INTERRUPT_H_

#include "stm32_config.h"
#include "update_interrupt_hardware.h"
#include "exti_hardware.h"



void interrupt_hardware_init(void);
void interrupt_hardware_enable(void);
void interrupt_hardware_disable(void);



static inline void enable_all_interrupt(void){

	__enable_irq();
}

static inline void disable_all_interrupt(void){

	__disable_irq();
}
#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_INTERRUPT_H_ */
