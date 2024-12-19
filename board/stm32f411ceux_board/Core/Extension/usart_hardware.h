/*
 * usart_hardware.h
 *
 *  Created on: Dec 17, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_USART_HARDWARE_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_USART_HARDWARE_H_
#include "stm32_config.h"

uint32_t uart_write_one(uint8_t data);
void uart_change_baudrate(uint32_t baudrate);

void uart_receive_data(uint8_t *buffer, uint32_t buffer_size);
uint32_t uart_read_one(uint8_t *data);
#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_USART_HARDWARE_H_ */
