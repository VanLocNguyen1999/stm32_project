/*
 * keyboard_code.h
 *
 *  Created on: Dec 20, 2024
 *      Author: vanlo
 */

#ifndef SERVICES_KEYBOARD_CODE_KEYBOARD_CODE_H_
#define SERVICES_KEYBOARD_CODE_KEYBOARD_CODE_H_

#include "keyboard_hardware.h"

#define QUEUE_SIZE		4

typedef struct Keyboard_code_t Keyboard_code;

struct Keyboard_code_t{

	Keyboard_hardware keyboard;
	char keyboard_code[QUEUE_SIZE];
	uint8_t head;
	uint8_t tail;
	uint8_t size;
};
Keyboard_code* keyboard_code_created(void);
void keyboard_code_init(Keyboard_code* p_keyboard_code);
void keyboard_code_update_code(Keyboard_code* p_keyboard_code);
char keyboard_code__get_code(Keyboard_code* p_keyboard_code);

static inline bool keyboard_code_queue_is_empty(Keyboard_code* p_keyboard_code) {
    return  p_keyboard_code->size == 0;
}

static inline bool keyboard_code_queue_is_full(Keyboard_code* p_keyboard_code) {

	return (p_keyboard_code->size = QUEUE_SIZE);
}

static inline void keyboard_code_queue_enqueue(Keyboard_code* p_keyboard_code, char data) {
	if (p_keyboard_code->keyboard.key_active == TRUE) {
		if (keyboard_code_queue_is_full(p_keyboard_code)) {
			p_keyboard_code->head =
					(p_keyboard_code->head + 1 >= QUEUE_SIZE) ? 0 : p_keyboard_code->head + 1;
		} else {
			p_keyboard_code->size++;
		}
		p_keyboard_code->keyboard_code[p_keyboard_code->tail] = data;
		p_keyboard_code->tail =
				(p_keyboard_code->tail + 1 >= QUEUE_SIZE) ? 0 : p_keyboard_code->tail + 1;
		p_keyboard_code->keyboard.key_active = FLASE;
	}
}

static inline char keyboard_code_queue_peek(Keyboard_code* p_keyboard_code) {
    if (keyboard_code_queue_is_empty(p_keyboard_code)) {

        return '\0';
    }
    char data = p_keyboard_code->keyboard_code[p_keyboard_code->head];
    return data;
}

static inline void keyboard_code_queue_dequeue(Keyboard_code* p_keyboard_code){

	if(!keyboard_code_queue_is_empty(p_keyboard_code)){

		p_keyboard_code->size --;
		p_keyboard_code->head = (p_keyboard_code->head + 1 >= QUEUE_SIZE) ? 0 : p_keyboard_code->head + 1;
	}
}

static inline void keyboard_code_scan(Keyboard_code* p_keyboard_code){

	keyboard_hardware_scan(&p_keyboard_code->keyboard);
}

#endif /* SERVICES_KEYBOARD_CODE_KEYBOARD_CODE_H_ */
