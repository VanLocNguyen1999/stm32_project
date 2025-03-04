/*
 * key_board.h
 *
 *  Created on: Mar 1, 2025
 *      Author: Admin
 */

#ifndef BOARD_STM32F401RCT6_CORE_EXTENSION_KEY_BOARD_H_
#define BOARD_STM32F401RCT6_CORE_EXTENSION_KEY_BOARD_H_

#include "gpio.h"
#include "delay_hardware.h"
/*______________ROW________________*/
#define ROW_SET(x)       LL_GPIO_SetOutputPin(R##x##_GPIO_Port, R##x##_Pin)
#define ROW_RESET(x)     LL_GPIO_ResetOutputPin(R##x##_GPIO_Port, R##x##_Pin)
/*______________Colums________________*/
#define COLUMN_STATE(x)  LL_GPIO_IsInputPinSet(C##x##_GPIO_Port, C##x##_Pin)

static inline void key_board_set_rows(uint8_t row) {
    for (uint8_t i = 1; i <= 4; i++) {
        if (i == row) {
            ROW_SET(i);
        } else {
            ROW_RESET(i);
        }
    }
}

static inline uint8_t key_board_get_colums(void) {

	uint8_t result = 0;

	return result;
}

#endif /* BOARD_STM32F401RCT6_CORE_EXTENSION_KEY_BOARD_H_ */
