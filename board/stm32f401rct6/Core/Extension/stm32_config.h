/*
 * stm32_config.h
 *
 *  Created on: Feb 21, 2025
 *      Author: Admin
 */

#ifndef CORE_EXTENSION_STM32_CONFIG_H_
#define CORE_EXTENSION_STM32_CONFIG_H_

#include "stm32f4xx_hal.h"

#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_dma.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "stdint.h"

#define SYS_CLOCK		16000000UL
#define ADC_CLOCK		SYS_CLOCK

#define SET				1
#define RESET			0

/* ------------------------------------------------------------*/
#define PWM_Pin LL_GPIO_PIN_6
#define PWM_GPIO_Port GPIOA
#define LCD_D4_Pin LL_GPIO_PIN_8
#define LCD_D4_GPIO_Port GPIOA
#define LCD_D5_Pin LL_GPIO_PIN_9
#define LCD_D5_GPIO_Port GPIOA
#define LCD_D6_Pin LL_GPIO_PIN_10
#define LCD_D6_GPIO_Port GPIOA
#define LCD_D7_Pin LL_GPIO_PIN_11
#define LCD_D7_GPIO_Port GPIOA
#define LCD_RW_Pin LL_GPIO_PIN_3
#define LCD_RW_GPIO_Port GPIOB
#define LCD_EN_Pin LL_GPIO_PIN_4
#define LCD_EN_GPIO_Port GPIOB
#define LCD_RS_Pin LL_GPIO_PIN_5
#define LCD_RS_GPIO_Port GPIOB

static inline void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}
#endif /* CORE_EXTENSION_STM32_CONFIG_H_ */
