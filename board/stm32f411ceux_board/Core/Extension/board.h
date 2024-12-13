/*
 * board.h
 *
 *  Created on: Dec 12, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_BOARD_H_
#define BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_BOARD_H_

#include "stm32_config.h"
#include "update_interrupt_hardware.h"
#include "pwm_hardware.h"


#define BOARD_TP1_SET			LL_GPIO_SetOutputPin(BOARD_TP_GPIO_Port,BOARD_TP_Pin)
#define BOARD_TP1_RESET			LL_GPIO_ResetOutputPin(BOARD_TP_GPIO_Port,BOARD_TP_Pin)
#define BOARD_TP1_TOGGLEPIN		LL_GPIO_TogglePin(BOARD_TP_GPIO_Port,BOARD_TP_Pin)

void board_hardware_init(void);


#endif /* BOARD_STM32F103CBTX_BOARD_CORE_EXTENSION_BOARD_H_ */
