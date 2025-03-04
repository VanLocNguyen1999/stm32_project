/*
 * dht11.h
 *
 *  Created on: Mar 3, 2025
 *      Author: Admin
 */

#ifndef BOARD_STM32F401RCT6_CORE_EXTENSION_DHT11_H_
#define BOARD_STM32F401RCT6_CORE_EXTENSION_DHT11_H_

#include "main.h"
#include "delay_hardware.h"

typedef struct Dht11_t Dht11;

#define DATA_PORT		DHT11__DATA_GPIO_Port
#define DATA_PIN		DHT11__DATA_Pin
#define INPUT			LL_GPIO_MODE_INPUT
#define OUPUT			LL_GPIO_MODE_OUTPUT

#define GET_DATA_PORT_MODE				LL_GPIO_GetPinMode(DATA_PORT,DATA_PIN)

#define CHANGE_DATA_PORT_TO_INPUT		LL_GPIO_SetPinMode(DATA_PORT,DATA_PIN,INPUT)
#define DATA_PORT_IS_INPUT				LL_GPIO_IsInputPinSet(DATA_PORT,DATA_PIN)

#define CHANGE_DATA_PORT_TO_OUPUT		LL_GPIO_SetPinMode(DATA_PORT,DATA_PIN,OUPUT)
#define SET_DATA_PORT					LL_GPIO_SetOutputPin(DATA_PORT,DATA_PIN)
#define RESET_DATA_PORT					LL_GPIO_ResetOutputPin(DATA_PORT,DATA_PIN)

#define TIME_US_HIGH_IS_LOW				24
#define TIME_US_HIGH_IS_HIGH			70

#define TIME_MS_LOW_START				18

#define TIME_US_LOW_RESPONSE			54
#define TIME_US_HIGH_RESPONSE			80

struct Dht11_t{

	uint8_t temp;
	float humidity;

	uint8_t data[5];
};

void dht11_init_ex(Dht11* dht11);
uint8_t dht11_read_data(Dht11 *dht11);
#endif /* BOARD_STM32F401RCT6_CORE_EXTENSION_DHT11_H_ */
