/*
 * keyboard_code.h
 *
 *  Created on: Dec 20, 2024
 *      Author: vanlo
 */

#ifndef SERVICES_KEYBOARD_CODE_KEYBOARD_CODE_H_
#define SERVICES_KEYBOARD_CODE_KEYBOARD_CODE_H_

#include "keyboard_hardware.h"

typedef struct Keyboard_code_t Keyboard_code;

struct Keyboard_code_t{

	Keyboard_hardware keyboard;
	char keyboard_code;

	bool get_code_state;
};
Keyboard_code* keyboard_code_created(void);
void keyboard_code_init(Keyboard_code* p_keyboard_code);
void keyboard_code_update_code(Keyboard_code* p_keyboard_code);
char keyboard_code__get_code(Keyboard_code* p_keyboard_code);

static inline void keyboard_code_set_code(Keyboard_code *p_keyboard_code,char data) {

	if (p_keyboard_code->keyboard.key_active == TRUE) {

		p_keyboard_code->keyboard_code = data;
		p_keyboard_code->keyboard.key_active = FLASE;
	}
}

static inline char keyboard_code_get_code(Keyboard_code* p_keyboard_code) {

    char data = p_keyboard_code->keyboard_code;
    return data;
}

static inline void keyboard_code_scan(Keyboard_code* p_keyboard_code){

	keyboard_hardware_scan(&p_keyboard_code->keyboard);
}

#endif /* SERVICES_KEYBOARD_CODE_KEYBOARD_CODE_H_ */
