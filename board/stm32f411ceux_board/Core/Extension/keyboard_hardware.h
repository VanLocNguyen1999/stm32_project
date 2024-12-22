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
#define C1_STATE				LL_GPIO_IsInputPinSet(C1_GPIO_Port, C1_Pin)
#define C2_STATE				LL_GPIO_IsInputPinSet(C2_GPIO_Port, C2_Pin)
#define C3_STATE				LL_GPIO_IsInputPinSet(C3_GPIO_Port, C3_Pin)
#define C4_STATE				LL_GPIO_IsInputPinSet(C4_GPIO_Port, C4_Pin)
typedef struct Keyboard_hardware_t Keyboard_hardware;
void keyboard_hardware_scan(Keyboard_hardware *keyboard);
Keyboard_hardware* keyboard_hardware_create(void);
void keyboard_hardware_init(Keyboard_hardware *keyboard);

char keyboard_hardware_update_code(Keyboard_hardware *keyboard);
struct Keyboard_hardware_t{
//
	uint8_t columns_check;
	uint8_t rows_check;

	uint8_t columns;
	uint8_t rows;

	uint32_t keyboard_counter;
	bool key_active;
};

static inline void keyboard_hardware_rows_set(const uint8_t rows){

    if ((rows) == 1) { R1_SET; R2_RESET; R3_RESET; R4_RESET; }
    else if ((rows) == 2) { R1_RESET; R2_SET; R3_RESET; R4_RESET; }
    else if ((rows) == 3) { R1_RESET; R2_RESET; R3_SET; R4_RESET; }
    else if ((rows) == 4) { R1_RESET; R2_RESET; R3_RESET; R4_SET; }
}

static inline bool keyboard_hardware_get_state_columns(const uint8_t columns){

	if ((columns) == 1) {
		return C1_STATE;
	} else if ((columns) == 2) {
		return C2_STATE;
	} else if ((columns) == 3) {
		return C3_STATE;
	} else if ((columns) == 4) {
		return C4_STATE;
	}
	return 0;
}

static inline uint8_t keyboard_hardware_get_columns(Keyboard_hardware* keyboard){

	return keyboard->columns;
}


static inline void keyboard_hardware_scan_columns(Keyboard_hardware *keyboard) {
    static uint8_t key_active = 0;

    if (keyboard_hardware_get_state_columns(keyboard->columns_check)) {
        if (!key_active) {
            keyboard->keyboard_counter++;
            if (keyboard->keyboard_counter > 100) {
                keyboard->columns = keyboard->columns_check;
                key_active = 1;
                keyboard->key_active = TRUE;
                return;
            }
        }
    } else {
        keyboard->keyboard_counter = 0;
        key_active = 0;
        keyboard->columns = 0;
        keyboard->columns_check = (keyboard->columns_check % 5) + 1;
    }
}



#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_KEYBOARD_HARDWARE_H_ */
