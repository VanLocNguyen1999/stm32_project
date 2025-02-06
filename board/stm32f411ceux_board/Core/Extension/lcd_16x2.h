/*
 * lcd_16x2.h
 *
 *  Created on: Dec 17, 2024
 *      Author: vanlo
 */

#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_LCD_16X2_H_
#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_LCD_16X2_H_


#define SET_DDRAM_ADDRESS_LINE_1	 	     	0x80 // đia chỉ cua vị tri đầu tiên dong 1
#define SET_DDRAM_ADDRESS_LINE_2	 	     	0xC0 // đia chỉ cua vị tri đầu tiên dong 2

/************************************** Command register **************************************/
#define CLEAR_DISPLAY					0x01 //xoa toan bọ noi dung tren LCD
#define RETURN_HOME						0x02 // di chuyển về đầu màn hình
#define NEXT_ID	            			0x06 //tự dong di chuyen den vị trí tiếp theo mỗi khi LCD xuất ra 1 kí tự

#define FOR_BIT	    					0x28 // giao thuc 4 bit
#define TURN_ON	                  	    0x0C // Turn on display và pointer
#define TURN_OFF	                  	0x0E // Turn on display và tin off pointer

#define ENABLE_LCD						LL_GPIO_ResetOutputPin(Rs_GPIO_Port,Rs_Pin)
#define DISABLE_LCD						LL_GPIO_SetOutputPin(Rs_GPIO_Port,Rs_Pin)

void lcd_enable(void);
void lcd_send4bit(unsigned char Data);
void lcd_sendcommand(unsigned char command);
void lcd_clear();
void lcd_init();
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_putchar(unsigned char Data);
void lcd_puts(char *s);
#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_LCD_16X2_H_ */
