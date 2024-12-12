/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32_config.h"
#include "lcd_16x2.h"

int main(void) {

	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	LCD_Init();
	LCD_Gotoxy(1, 0);
	LCD_Puts("NGUYEN VAN LOC");
	LCD_Gotoxy(8, 1);
	LCD_Puts("SELEX");
	while (1) {

	};
}

