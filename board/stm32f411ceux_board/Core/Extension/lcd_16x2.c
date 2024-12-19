/*
 * lcd_16x2.c
 *
 *  Created on: Dec 17, 2024
 *      Author: vanlo
 */


#include "lcd_16x2.h"
#include "string.h"

#include "stm32_config.h"
#include "delay.h"

void LCD_Init()
{
  LCD_Send4Bit(0x00);
  LL_GPIO_ResetOutputPin(Rs_GPIO_Port,Rs_Pin);
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
	LL_GPIO_SetOutputPin(En_GPIO_Port, En_Pin);
    delay_ms(1);
    LL_GPIO_ResetOutputPin(En_GPIO_Port, En_Pin);
    delay_ms(1);
}

void LCD_Send4Bit_LL(unsigned char Data)
{
    if (Data & 0x01)
        LL_GPIO_SetOutputPin(D4_GPIO_Port, D4_Pin);
    else
        LL_GPIO_ResetOutputPin(D4_GPIO_Port, D4_Pin);

    if ((Data >> 1) & 0x01)
        LL_GPIO_SetOutputPin(D5_GPIO_Port, D5_Pin);
    else
        LL_GPIO_ResetOutputPin(D5_GPIO_Port, D5_Pin);

    if ((Data >> 2) & 0x01)
        LL_GPIO_SetOutputPin(D6_GPIO_Port, D6_Pin);
    else
        LL_GPIO_ResetOutputPin(D6_GPIO_Port, D6_Pin);

    if ((Data >> 3) & 0x01)
        LL_GPIO_SetOutputPin(D7_GPIO_Port,D7_Pin);
    else
        LL_GPIO_ResetOutputPin(D7_GPIO_Port,D7_Pin);
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
  delay_us(10);
}
void LCD_Gotoxy(unsigned char x, unsigned char y) {

	if (y == 0)
		LCD_SendCommand(SET_DDRAM_ADDRESS_LINE_1 + x);
	else if (y == 1)
		LCD_SendCommand(SET_DDRAM_ADDRESS_LINE_2 + x);
}

void LCD_PutChar(unsigned char Data) {

	LL_GPIO_SetOutputPin(Rs_GPIO_Port,Rs_Pin);
	LCD_SendCommand(Data);
	LL_GPIO_ResetOutputPin(Rs_GPIO_Port,Rs_Pin);
}

void LCD_Puts(char *s)
{
  while (*s)
  {
    LCD_PutChar(*s);
    s++;
  }
}
