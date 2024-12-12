#include "main.h"
#include "stm32_config.h"
#include "pwm_hardware.h"


int main(void)
{
  HAL_Init();

  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM4_Init();
  pwm_hardware_init_ex();
  while (1)
  {

  }

}

