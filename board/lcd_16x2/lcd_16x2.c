/*
 * lcd_16x2.c
 *
 *  Created on: Apr 3, 2024
 *      Author: vanlo
 */
#include "lcd_16x2.h"
#include "gpio.h"
#include "string.h"

#include "stm32_config.h"
#include "delay.h"

void LCD_Init()
{
  LCD_Send4Bit(0x00);
  HAL_GPIO_WritePin(GPIOB, LCD_RS_Pin, 0);
  LCD_Send4Bit(0x03);
  LCD_Enable();
  LCD_Enable();
  LCD_Enable();
  LCD_Send4Bit(0x02);
  LCD_Enable();
  LCD_SendCommand(0x28); // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
  LCD_SendCommand(0x0C); // cho phep hien thi man hinh
  LCD_SendCommand(0x06); // tang ID, khong dich khung hinh
  LCD_SendCommand(0x01); // xoa toan bo khung hinh
}


void LCD_Enable(void)
{
	HAL_GPIO_WritePin(GPIOB, LCD_EN_Pin, GPIO_PIN_SET);
    delayms(1);
    HAL_GPIO_WritePin(GPIOB, LCD_EN_Pin, GPIO_PIN_RESET);
    delayms(1);
}

void LCD_Send4Bit(unsigned char Data)
{
  HAL_GPIO_WritePin(GPIOA, LCD_D4_Pin, Data & 0x01);
  HAL_GPIO_WritePin(GPIOA, LCD_D5_Pin, (Data>>1)&1);
  HAL_GPIO_WritePin(GPIOA, LCD_D6_Pin, (Data>>2)&1);
  HAL_GPIO_WritePin(GPIOA, LCD_D7_Pin, (Data>>3)&1);
}

void LCD_SendCommand(unsigned char command)
{
  LCD_Send4Bit(command >> 4);
  LCD_Enable();
  LCD_Send4Bit(command);
  LCD_Enable();

}

void LCD_Clear()
{
  LCD_SendCommand(0x01);
  delayus(10);
}
void LCD_Gotoxy(unsigned char x, unsigned char y) {

	if (y == 0)
		LCD_SendCommand(SET_DDRAM_ADDRESS_LINE_1 + x);
	else if (y == 1)
		LCD_SendCommand(SET_DDRAM_ADDRESS_LINE_2 + x);
}

void LCD_PutChar(unsigned char Data) {

	HAL_GPIO_WritePin(GPIOB, LCD_RS_Pin,GPIO_PIN_SET);
	LCD_SendCommand(Data);
	HAL_GPIO_WritePin(GPIOB, LCD_RS_Pin, GPIO_PIN_RESET);
}

void LCD_Puts(char *s)
{
  while (*s)
  {
    LCD_PutChar(*s);
    s++;
  }
}
