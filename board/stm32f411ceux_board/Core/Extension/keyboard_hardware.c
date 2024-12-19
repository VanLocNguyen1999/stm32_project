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

Keyboard* keyboard_create(void){

	Keyboard* keyboard = (Keyboard*)malloc(sizeof(Keyboard));
	while(keyboard==NULL){

    };
	keyboard_init(keyboard);
	return keyboard;
}

void keyboard_init(Keyboard *keyboard){

//	keyboard->c1_state = 0;
//	keyboard->c2_state = 0;
//	keyboard->c3_state = 0;
//	keyboard->c4_state = 0;

	keyboard->columns = 0;
	keyboard->rows    = 0;
}
OPTIMIZE_ATTR void keyboard_scan(Keyboard *keyboard) {
    for (int i = 1; i < 5; i++) {
        keyboard_rows_set(i);
        if (keyboard->columns) {
            keyboard->rows = i - 1;
            return;
        }
    }
    keyboard->rows = -1;
}

OPTIMIZE_ATTR char keyboard_update_code(Keyboard *keyboard) {

	uint8_t row 	= keyboard->rows - 1;
	uint8_t column  = keyboard->columns - 1;
    if (row >= 0 && row < 4 && column >= 0 && column < 4) {
        return keyboard_code[row][column];
    } else {
        return '\0';
    }
}


