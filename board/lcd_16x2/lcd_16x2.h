/*
 * lcd_16x2.h
 *
 *  Created on: Apr 3, 2024
 *      Author: vanlo
 */

#ifndef BOARD_LCD_16X2_LCD_16X2_H_
#define BOARD_LCD_16X2_LCD_16X2_H_

#define SET_DDRAM_ADDRESS_LINE_1	 	     	0x80 // đia chỉ cua vị tri đầu tiên dong 1
#define SET_DDRAM_ADDRESS_LINE_2	 	     	0xC0 // đia chỉ cua vị tri đầu tiên dong 2

/************************************** Command register **************************************/
#define CLEAR_DISPLAY					0x01 //xoa toan bọ noi dung tren LCD
#define RETURN_HOME						0x02 // di chuyển về đầu màn hình
#define NEXT_ID	            			0x06 //tự dong di chuyen den vị trí tiếp theo mỗi khi LCD xuất ra 1 kí tự

#define DISPLAY_ON_FOR_BIT	    		0x28 // giao thuc 4 bit
#define TURN_ON	                  	    0x0C // Turn on display và pointer
#define TURN_OFF	                  	0x0E // Turn on display và tin off pointer

void LCD_Enable(void);
void LCD_Send4Bit(unsigned char Data);
void LCD_SendCommand(unsigned char command);
void LCD_Clear();
void LCD_Init();
void LCD_Gotoxy(unsigned char x, unsigned char y);
void LCD_PutChar(unsigned char Data);
void LCD_Puts(char *s);

#endif /* BOARD_LCD_16X2_LCD_16X2_H_ */
