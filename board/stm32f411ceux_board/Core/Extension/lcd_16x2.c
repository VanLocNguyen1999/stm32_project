/*
 * lcd_16x2.c
 *
 *  Created on: Dec 17, 2024
 *      Author: vanlo
 */


#include "lcd_16x2.h"
#include "string.h"

#include "stm32_config.h"
#include "delay_hardware.h"

void lcd_init()
{
  lcd_send4bit(0x00);
  ENABLE_LCD;
  lcd_send4bit(0x03);
  lcd_enable();
  lcd_enable();
  lcd_enable();
  lcd_send4bit(0x02);
  lcd_enable();
  lcd_sendcommand(FOR_BIT); // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
  lcd_sendcommand(TURN_ON); // cho phep hien thi man hinh
  lcd_sendcommand(NEXT_ID); // tang ID, khong dich khung hinh
  lcd_sendcommand(CLEAR_DISPLAY); // xoa toan bo khung hinh
}


void lcd_enable(void)
{
	ENABLE_LCD;
    delay_ms(1);
    DISABLE_LCD;
    delay_ms(1);
}

void lcd_send4bit(unsigned char Data)
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

void lcd_sendcommand(unsigned char command)
{
  lcd_send4bit(command >> 4);
  lcd_enable();
  lcd_send4bit(command);
  lcd_enable();

}

void lcd_clear()
{
  lcd_sendcommand(0x01);
  delay_us(10);
}
void lcd_gotoxy(unsigned char x, unsigned char y) {

	if (y == 0)
		lcd_sendcommand(SET_DDRAM_ADDRESS_LINE_1 + x);
	else if (y == 1)
		lcd_sendcommand(SET_DDRAM_ADDRESS_LINE_2 + x);
}

void lcd_putchar(unsigned char Data) {

	ENABLE_LCD;
	lcd_sendcommand(Data);
	DISABLE_LCD;
}

void lcd_puts(char *s)
{
  while (*s)
  {
    lcd_putchar(*s);
    s++;
  }
}
