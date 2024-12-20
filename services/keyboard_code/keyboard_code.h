/*
 * keyboard_code.h
 *
 *  Created on: Dec 20, 2024
 *      Author: vanlo
 */

#ifndef SERVICES_KEYBOARD_CODE_KEYBOARD_CODE_H_
#define SERVICES_KEYBOARD_CODE_KEYBOARD_CODE_H_

#include "fifo_queue.h"
#include "keyboard_hardware.h"

typedef struct Keyboard_code_t Keyboard_code;

struct Keyboard_code_t{

	uint8_t send_count;
    uint8_t min_send_count;
    Fifo_queue *p_fifo;
};
Error_code* error_code_created(uint8_t min_get_count);
void error_code_init(Error_code* p_error_code, uint8_t min_get_count);
void error_code_set_code(Error_code* p_error_code, uint32_t code);
uint8_t error_code_get_selex_code(Error_code* p_error_code);

#endif /* SERVICES_KEYBOARD_CODE_KEYBOARD_CODE_H_ */
