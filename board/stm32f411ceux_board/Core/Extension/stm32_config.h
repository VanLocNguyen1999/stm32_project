/*
 * board_config.h
 *
 *  Created on: Apr 2, 2024
 *      Author: vanlo
 */

#ifndef STM32F1_CONFIG_H_
#define STM32F1_CONFIG_H_

#include "stm32f4xx_hal.h"

#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_dma.h"

#include "stm32f4xx_ll_exti.h"

#include "stdlib.h"
#include <stdint.h>
#include <stdbool.h>

#include "user.h"
//#include "delay.h"
#define INTERRUPT_GPIO		1UL
#define INTERRUPT_TIMER		0UL

#define ENABLE 	1			//xoa
#define DISABLE	0			//xoa

#define HIGH 	1
#define LOW		0

#define TRUE 	1
#define FLASE	0

#define SYS_STOP			PWM_DISABLE_OUTPUT
#define SYS_TICK			48000000UL
#define SYS_CLOCK			96000000UL
#define HC_LOCK				48000000UL

#define R1_Pin LL_GPIO_PIN_1
#define R1_GPIO_Port GPIOA
#define R2_Pin LL_GPIO_PIN_2
#define R2_GPIO_Port GPIOA
#define R3_Pin LL_GPIO_PIN_3
#define R3_GPIO_Port GPIOA
#define R4_Pin LL_GPIO_PIN_4
#define R4_GPIO_Port GPIOA
#define EXTI5_Pin LL_GPIO_PIN_5
#define EXTI5_GPIO_Port GPIOA
#define EXTI5_EXTI_IRQn EXTI9_5_IRQn
#define HC_TRIG_Pin LL_GPIO_PIN_1
#define HC_TRIG_GPIO_Port GPIOB
#define HC_ECHO_Pin LL_GPIO_PIN_2
#define HC_ECHO_GPIO_Port GPIOB
#define Rs_Pin LL_GPIO_PIN_12
#define Rs_GPIO_Port GPIOB
#define Rw_Pin LL_GPIO_PIN_13
#define Rw_GPIO_Port GPIOB
#define En_Pin LL_GPIO_PIN_14
#define En_GPIO_Port GPIOB
#define C1_Pin LL_GPIO_PIN_9
#define C1_GPIO_Port GPIOA
#define C2_Pin LL_GPIO_PIN_10
#define C2_GPIO_Port GPIOA
#define C3_Pin LL_GPIO_PIN_11
#define C3_GPIO_Port GPIOA
#define C4_Pin LL_GPIO_PIN_12
#define C4_GPIO_Port GPIOA
#define D4_Pin LL_GPIO_PIN_3
#define D4_GPIO_Port GPIOB
#define D5_Pin LL_GPIO_PIN_4
#define D5_GPIO_Port GPIOB
#define D6_Pin LL_GPIO_PIN_5
#define D6_GPIO_Port GPIOB
#define D7_Pin LL_GPIO_PIN_6
#define D7_GPIO_Port GPIOB
#define BOARD_TP_Pin LL_GPIO_PIN_9
#define BOARD_TP_GPIO_Port GPIOB

static inline void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#define OPTIMIZE_ATTR  FORCE_INLINE


#define FORCE_INLINE    inline __attribute__((always_inline))


#endif /* BOARD_STM32F1_CONFIG_STM32F1_CONFIG_H_ */
