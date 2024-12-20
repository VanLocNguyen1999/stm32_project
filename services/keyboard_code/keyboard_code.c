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

static inline bool error_code_is_exists(Error_code* p_error_code, uint32_t code);
static inline bool error_code_is_empty(Error_code* p_error_code);
static inline void error_code_handle_retrieval_complete(Error_code* p_error_code);

Error_code* error_code_created(uint8_t min_get_count) {

	Error_code *p_error_code =
			(Error_code*) malloc(sizeof(Error_code));
	while (p_error_code == NULL) {

	};
	error_code_init(p_error_code,min_get_count);
	return p_error_code;
}

void error_code_init(Error_code *p_error_code, uint8_t min_get_count) {

	while (p_error_code == NULL) {

	};
	p_error_code->p_fifo =  fifo_queue_created();
	p_error_code->min_send_count = min_get_count;
	p_error_code->send_count = 0;
}

void error_code_set_code(Error_code *p_error_code, uint32_t code) {

	if (code == 0 || (error_code_is_exists(p_error_code, code))) {
		return;
	}
	else {

			fifo_queue_enqueue(p_error_code->p_fifo, code);
		}
	}


uint8_t error_code_get_selex_code(Error_code *p_error_code) {

	uint32_t selex_error = 0;

	selex_error = fifo_queue_peek(p_error_code->p_fifo);
	if (selex_error == 0) {

		return 0;
	} else {

		p_error_code->send_count++;
		error_code_handle_retrieval_complete(p_error_code);
		selex_error >>= 16;
		return (uint8_t) selex_error;
	}

}

static inline bool error_code_is_exists(Error_code* p_error_code, uint32_t code){

	return fifo_queue_is_exists(p_error_code->p_fifo, code);
}

static inline bool error_code_is_empty(Error_code* p_error_code){

	return fifo_queue_is_empty(p_error_code->p_fifo);
}
static inline void error_code_handle_retrieval_complete(Error_code* p_error_code){

	if (p_error_code->send_count >= p_error_code->min_send_count) {
		fifo_queue_dequeue(p_error_code->p_fifo);
		p_error_code->send_count = 0;
	}
}
