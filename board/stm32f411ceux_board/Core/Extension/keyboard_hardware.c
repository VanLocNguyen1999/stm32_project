/*
 * keyboard_hardware.c
 *
 *  Created on: Dec 17, 2024
 *      Author: vanlo
 */
#include "keyboard_hardware.h"

const char keyboard_code[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

Keyboard_hardware* keyboard_hardware_create(void){

	Keyboard_hardware* keyboard = (Keyboard_hardware*)malloc(sizeof(Keyboard_hardware));
	while(keyboard==NULL){

    };
	keyboard_hardware_init(keyboard);
	return keyboard;
}

void keyboard_hardware_init(Keyboard_hardware *keyboard){

	keyboard->columns_check = 1;

	keyboard->columns = 0;
	keyboard->rows    = 1;

	keyboard->keyboard_counter = 0;
	keyboard->key_active = FLASE;
}

OPTIMIZE_ATTR void keyboard_hardware_scan(Keyboard_hardware *keyboard) {
    for (int i = 1; i < 5; i++) {
        keyboard_hardware_rows_set(i);
        keyboard_hardware_scan_columns(keyboard);
        if (keyboard->columns) {
            keyboard->rows = i - 1;
            return;
        }
    }
    keyboard->rows = -1;
}

OPTIMIZE_ATTR char keyboard_hardware_update_code(Keyboard_hardware *keyboard) {

	uint8_t row 	= keyboard->rows;
	uint8_t column  = keyboard->columns ;
    if (row > 0 && row < 5 && column > 0 && column < 5) {
        return keyboard_code[keyboard->rows - 1][keyboard->columns - 1];
    } else {
        return '\0';
    }
}


