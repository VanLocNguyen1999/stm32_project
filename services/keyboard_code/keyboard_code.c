/*
 * keyboard_code.c
 *
 *  Created on: Dec 20, 2024
 *      Author: vanlo
 */

#include <keyboard_code.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/_stdint.h>
#include "keyboard_code.h"

Keyboard_code* keyboard_code_created(void) {

	Keyboard_code *p_keyboard_code =
			(Keyboard_code*) malloc(sizeof(Keyboard_code));
	while (p_keyboard_code == NULL) {

	};
	keyboard_code_init(p_keyboard_code);
	return p_keyboard_code;
}

void keyboard_code_init(Keyboard_code* p_keyboard_code) {

	while (p_keyboard_code == NULL) {

	};
	p_keyboard_code->get_code_state = FLASE;
	keyboard_hardware_init(&p_keyboard_code->keyboard);
}

void keyboard_code_update_code(Keyboard_code *p_keyboard_code) {

	char code = keyboard_hardware_update_code(&p_keyboard_code->keyboard);
	if (code != '\0') {
		keyboard_code_set_code(p_keyboard_code, code);
	}
}


char keyboard_code__get_code(Keyboard_code *p_keyboard_code) {

	char keyboard_code = keyboard_code_get_code(p_keyboard_code);
	p_keyboard_code->keyboard_code = 0;
	return keyboard_code;
}


