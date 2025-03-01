/*
 * lcd.c
 *
 *  Created on: Feb 21, 2025
 *      Author: Admin
 */

#include "lcd.h"

static void lcd_putchar(char data);
static void lcd_enable(void);
static void lcd_send4bit(char data);
static void lcd_command(char command);

void lcd_clear_display(void){

	lcd_command(0x01);
	delay_ms(5);
}
void lcd_init(void) {

	lcd_send4bit(0x00);
	LL_GPIO_ResetOutputPin(LCD_RS_GPIO_Port, LCD_RS_Pin);
	lcd_send4bit(0x02);
	lcd_enable();
	lcd_command(0x28);
	lcd_command(0x0C);
	lcd_command(0x06);
	lcd_command(0x01);
	delay_ms(1);
	lcd_gotoxy(1, 0);
	lcd_puts("NGUYEN VAN LOC");
	lcd_gotoxy(1, 1);
	lcd_puts("SELEX:");
}

void lcd_gotoxy(char x, char y)
{
	char addr = 0;
	if (y == 0)
		addr =0x80 + x;

	if (y == 1)
		addr =0xC0 + x;

	lcd_command(addr);
}

void lcd_puts(char *s) // gửi 1 chỗi kí tự
{
   	while (*s)
		{
      lcd_putchar(*s);
     	s++;
   	}
}

void num_dsp(int number) {
	char str[5];
	sprintf(str, "%d", number); // chuyển từ số sang chuỗi
	lcd_puts(str);
}

static void lcd_putchar(char data) { // gửi 1 kí tự đơn
	LL_GPIO_SetOutputPin(LCD_RS_GPIO_Port, LCD_RS_Pin);
	lcd_command(data);
	LL_GPIO_ResetOutputPin(LCD_RS_GPIO_Port, LCD_RS_Pin);
}
static void lcd_enable(void){

	LL_GPIO_SetOutputPin(LCD_EN_GPIO_Port, LCD_EN_Pin);
	delay_ms(1);
	LL_GPIO_ResetOutputPin(LCD_EN_GPIO_Port, LCD_EN_Pin);
	delay_ms(1);
}

static void lcd_send4bit(char data) { // bit cao gửi trước
    GPIO_TypeDef *ports[] = {LCD_D4_GPIO_Port, LCD_D5_GPIO_Port, LCD_D6_GPIO_Port, LCD_D7_GPIO_Port};
    uint32_t pins[] = {LCD_D4_Pin, LCD_D5_Pin, LCD_D6_Pin, LCD_D7_Pin};

    for (uint8_t i = 0; i < 4; i++) {
        if ((data>>i)&0x01) {
            LL_GPIO_SetOutputPin(ports[i], pins[i]);
        } else {
            LL_GPIO_ResetOutputPin(ports[i], pins[i]);
        }
    }
}

static void lcd_command(char command){

	lcd_send4bit(command >> 4);
	lcd_enable();
	lcd_send4bit(command);
	lcd_enable();
}
