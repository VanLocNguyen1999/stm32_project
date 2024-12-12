/*
 * board_config.h
 *
 *  Created on: Apr 2, 2024
 *      Author: vanlo
 */

#ifndef STM32F1_CONFIG_H_
#define STM32F1_CONFIG_H_

#include "stm32f1xx_hal.h"
#include "gpio.h"
void Error_Handler(void);
void SystemClock_Config(void);

#define OPTIMIZE_ATTR  FORCE_INLINE

#define LCD_D4_Pin GPIO_PIN_4
#define LCD_D4_GPIO_Port GPIOA
#define LCD_D5_Pin GPIO_PIN_5
#define LCD_D5_GPIO_Port GPIOA
#define LCD_D6_Pin GPIO_PIN_6
#define LCD_D6_GPIO_Port GPIOA
#define LCD_D7_Pin GPIO_PIN_7
#define LCD_D7_GPIO_Port GPIOA
#define LCD_RS_Pin GPIO_PIN_0
#define LCD_RS_GPIO_Port GPIOB
#define LCD_RW_Pin GPIO_PIN_1
#define LCD_RW_GPIO_Port GPIOB
#define LCD_EN_Pin GPIO_PIN_2
#define LCD_EN_GPIO_Port GPIOB

#define FORCE_INLINE    inline __attribute__((always_inline))

#endif /* BOARD_STM32F1_CONFIG_STM32F1_CONFIG_H_ */
