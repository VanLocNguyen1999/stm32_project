/*
 * main.c
 *
 *  Created on: Mar 1, 2025
 *      Author: Admin
 */

#include "board.h"
#include "dht11.h"

Dht11 dht11;

uint16_t counter = 0;



int main(void) {

	board_hardware_init_ex();
	dht11_init_ex(&dht11);
	while (1) {

		counter ++;
		if(counter > 500){

			counter = 0;
			dht11_read_data(&dht11);
		}

	}
}

void HAL_IncTick(void){

	uwTick += uwTickFreq;

}
