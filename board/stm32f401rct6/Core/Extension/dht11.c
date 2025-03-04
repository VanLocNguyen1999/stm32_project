/*
 * dht11.c
 *
 *  Created on: Mar 3, 2025
 *      Author: Admin
 */
#include "dht11.h"

void dht11_init_ex(Dht11* dht11){

	dht11->humidity = 0;
	dht11->temp		= 0;

	dht11->data[5] = 0;

	CHANGE_DATA_PORT_TO_OUPUT;
	SET_DATA_PORT;
	delay_ms(1);
}

static inline void dht11_start(void){

	RESET_DATA_PORT;
	delay_ms(TIME_MS_LOW_START);
	SET_DATA_PORT;
}

static inline uint8_t dht11_is_response(void){

	delay_us(TIME_US_LOW_RESPONSE);
	CHANGE_DATA_PORT_TO_INPUT;
	uint8_t response = 0;
	if(!(DATA_PORT_IS_INPUT)){

		delay_us(TIME_US_HIGH_RESPONSE);
		if(DATA_PORT_IS_INPUT){

			response = 1;
			while(DATA_PORT_IS_INPUT);
		}
	}
	return response;
}
 static inline uint8_t dht11_read_byte(void){

	 uint8_t byte = 0;

	 for(uint8_t i = 0 ; i < 8 ; i++){
		 while(DATA_PORT_IS_INPUT);
		 delay_us(40);
		 if(DATA_PORT_IS_INPUT){

			 byte |= (1 << (7 - i));
		 }
		 while(!DATA_PORT_IS_INPUT);
	 }
	 return byte;
 }
uint8_t dht11_read_data(Dht11 *dht11) {

	uint8_t i;

	dht11_start();
	while (dht11_is_response()) {

		for (i = 0; i < sizeof(dht11->data); i++) {

			dht11->data[i] = dht11_read_byte();
		}
		uint8_t check_sum = dht11->data[0] + dht11->data[1] + dht11->data[2]
				+ dht11->data[3];
		if (check_sum == dht11->data[4]) {

			return 1;
		}
	}
	return 0;
}
