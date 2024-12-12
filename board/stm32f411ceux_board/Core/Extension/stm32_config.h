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

#include "tim.h"
#include "gpio.h"
#include "stdlib.h"

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

#define SYS_STOP			PWM_DISABLE_OUTPUT
#define SYS_CLK				48000000UL

#endif /* BOARD_STM32F1_CONFIG_STM32F1_CONFIG_H_ */
