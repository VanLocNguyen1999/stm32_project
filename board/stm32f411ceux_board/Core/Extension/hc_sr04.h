/*
 * hc_sr04.h
 *
 *  Created on: Dec 26, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_HC_SR04_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_HC_SR04_H_

#include "stm32_config.h"
#include "delay_hardware.h"

#define HC_SR_04_TRIG_SET			LL_GPIO_SetOutputPin(HC_TRIG_GPIO_Port, HC_TRIG_Pin)
#define HC_SR_04_TRIG_RESET			LL_GPIO_ResetOutputPin(HC_TRIG_GPIO_Port, HC_TRIG_Pin)

#define HC_SR_04_ECHO_STATE			LL_GPIO_IsInputPinSet(HC_ECHO_GPIO_Port, HC_ECHO_Pin)

#define TIME_TO_D				(29.412f*0.5f)

typedef struct Hc_sr04_t Hc_sr04;

struct Hc_sr04_t{

	Pluse_In* pluse_in;

	uint32_t time_ctr;

	uint32_t duration;
	float distance;
};

Hc_sr04* hc_sr04_create(void);
void hc_sr04_init(Hc_sr04* hc_sr);

static inline float hc_sr04_get_distance(Hc_sr04* hc_sr){

	hc_sr04_set_trig(hc_sr);
	hc_sr04_update_echo(hc_sr);
	hc_sr->distance = hc_sr->duration/TIME_TO_D;
	return hc_sr->distance;
}

static inline void hc_sr04_set_trig(Hc_sr04* hc_sr){

	HC_SR_04_TRIG_RESET;
	HC_SR_04_TRIG_SET;
	delay_us(5);
	HC_SR_04_TRIG_RESET;
}
static inline void hc_sr04_update_echo(Hc_sr04* hc_sr){

	hc_sr->duration = pluse_get_time(hc_sr->pluse_in);
}
#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_HC_SR04_H_ */
