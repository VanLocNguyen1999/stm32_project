/*
 * pluse_in.c
 *
 *  Created on: Jan 17, 2025
 *      Author: vanlo
 */

#include "pluse_in.h"

void pluse_in_init(Pluse_In *pluse, uint8_t pluse_state, uint8_t init_state, uint32_t time_out){

	pluse->time = 0;
	pluse->time_out = time_out;

	pluse->init_state = init_state;
	pluse->state = pluse_state;
}
