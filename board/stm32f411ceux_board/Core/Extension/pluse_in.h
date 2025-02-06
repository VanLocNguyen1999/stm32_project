/*
 * pluse_in.h
 *
 *  Created on: Jan 17, 2025
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_PLUSE_IN_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_PLUSE_IN_H_

#include "stm32_config.h"
#include "gpio.h"
#include "delay_hardware.h"

typedef uint8_t (*Pluse_State)(LL_GPIO_InitTypeDef *, uint32_t);
typedef struct Pluse_In_t Pluse_In;
struct Pluse_In_t{

	uint32_t time;
	uint32_t time_out;

	uint8_t init_state;
	uint8_t state;
};
void pluse_in_init(Pluse_In *pluse, uint8_t pluse_state, uint8_t init_state, uint32_t time_out);

static inline uint32_t pluse_get_time(Pluse_In *pluse) {

	LL_TIM_SetCounter(TIM4, 0); // Reset counter to 0
	uint32_t check_time = LL_TIM_GetCounter(TIM4);  //us

	// Chờ tín hiệu rời khỏi trạng thái ban đầu
	while (pluse->state == pluse->init_state) {
		if (LL_TIM_GetCounter(TIM4) - check_time > pluse->time_out) {
			return 0; // Hết thời gian chờ, trả về 0
		}
	}
	// Chờ tín hiệu đạt đến trạng thái chỉ định
	while (pluse->state != pluse->init_state) {
		if (LL_TIM_GetCounter(TIM4) - check_time > pluse->time_out) {
			return 0; // Hết thời gian chờ, trả về 0
		}
	}

	// Đo thời gian xung
	uint32_t start_time = LL_TIM_GetCounter(TIM4);  //us
	while (pluse->state == pluse->init_state) {
		if (LL_TIM_GetCounter(TIM4) - start_time > timeout) {
			return 0; // Hết thời gian chờ, trả về 0
		}
	}
	uint32_t end_time = LL_TIM_GetCounter(TIM4);  //us

	// Tính thời gian xung (theo micro giây)
	return (end_time - start_time);
}
#endif /* BOARD_STM32F411CEUX_BOARD_CORE_PLUSE_IN_H_ */
