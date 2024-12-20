/*
 * keyboard_hardware.h
 *
 *  Created on: Dec 17, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_KEYBOARD_HARDWARE_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_KEYBOARD_HARDWARE_H_

#include "stm32_config.h"
#include "delay.h"

// hàng _ Rows
#define R1_SET					LL_GPIO_SetOutputPin(R1_GPIO_Port,R1_Pin)
#define R2_SET					LL_GPIO_SetOutputPin(R2_GPIO_Port,R2_Pin)
#define R3_SET					LL_GPIO_SetOutputPin(R3_GPIO_Port,R3_Pin)
#define R4_SET					LL_GPIO_SetOutputPin(R4_GPIO_Port,R4_Pin)

#define R1_RESET				LL_GPIO_ResetOutputPin(R1_GPIO_Port,R1_Pin)
#define R2_RESET				LL_GPIO_ResetOutputPin(R2_GPIO_Port,R2_Pin)
#define R3_RESET				LL_GPIO_ResetOutputPin(R3_GPIO_Port,R3_Pin)
#define R4_RESET				LL_GPIO_ResetOutputPin(R4_GPIO_Port,R4_Pin)
// hàng _ Columns

typedef struct Keyboard_t Keyboard;
void keyboard_scan(Keyboard *keyboard);
Keyboard* keyboard_create(void);
void keyboard_init(Keyboard *keyboard);
struct Keyboard_t{
//
	uint8_t c1_state;
	uint8_t c2_state;
	uint8_t c3_state;
	uint8_t c4_state;

	uint8_t columns;
	uint8_t rows;
};

static inline void keyboard_rows_set(const uint8_t rows){

    if ((rows) == 1) { R1_SET; R2_RESET; R3_RESET; R4_RESET; }
    else if ((rows) == 2) { R1_RESET; R2_SET; R3_RESET; R4_RESET; }
    else if ((rows) == 3) { R1_RESET; R2_RESET; R3_SET; R4_RESET; }
    else if ((rows) == 4) { R1_RESET; R2_RESET; R3_RESET; R4_SET; }
}

static inline void keyboard_update_columns(Keyboard* keyboard){

	uint8_t columns = keyboard->c1_state + keyboard->c2_state
			+ keyboard->c3_state + keyboard->c4_state;
	keyboard->columns = columns;
}
static inline uint8_t keyboard_get_columns(Keyboard* keyboard){

	return keyboard->columns;
}

static inline void keyboard_set_states_columns(Keyboard *keyboard,uint8_t columns) {
	// Đặt trạng thái của cột dựa trên giá trị của columns
	if (columns == 1) {
		keyboard->c1_state = 1;
		keyboard->c2_state = keyboard->c3_state = keyboard->c4_state = 0;
	} else if (columns == 2) {
		keyboard->c2_state = 2;
		keyboard->c1_state = keyboard->c3_state = keyboard->c4_state = 0;
	} else if (columns == 3) {
		keyboard->c3_state = 3;
		keyboard->c2_state = keyboard->c1_state = keyboard->c4_state = 0;
	} else if (columns == 4) {
		keyboard->c4_state = 4;
		keyboard->c2_state = keyboard->c3_state = keyboard->c1_state = 0;
	} else {
		// Xử lý mặc định nếu columns không hợp lệ
		keyboard->c1_state = keyboard->c2_state = keyboard->c3_state =
				keyboard->c4_state = 0;
	}
}

#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_KEYBOARD_HARDWARE_H_ */
