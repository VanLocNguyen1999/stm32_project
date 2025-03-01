/*
 * lcd.h
 *
 *  Created on: Feb 21, 2025
 *      Author: Admin
 */

#ifndef CORE_INC_LCD_H_
#define CORE_INC_LCD_H_

#include "delay_hardware.h"
#include "gpio.h"
#include "main.h"


void lcd_init(void);

void lcd_clear_display(void);
void lcd_gotoxy(char x, char y);
void lcd_puts(char *s);
void num_dsp(int number);



#endif /* CORE_INC_LCD_H_ */

//Mã lệnh (Hex)					Mô tả
	//0x38			Chế độ 8-bit, 2 dòng, font 5x8
	//0x28			Chế độ 4-bit, 2 dòng, font 5x8
	//0x30			Chế độ 8-bit, 1 dòng, font 5x8
	//0x20			Chế độ 4-bit, 1 dòng, font 5x8

	//0x0C			Bật màn hình, tắt con trỏ
	//0x0E			Bật màn hình, hiện con trỏ
	//0x0F			Bật màn hình, hiện con trỏ, con trỏ nhấp nháy
	//0x08			Tắt màn hình
	//0x01			Xóa toàn bộ màn hình, đưa con trỏ về (0,0)
	//0x02			Đưa con trỏ về (0,0) nhưng không xóa màn hình
	//0x06			Nhập dữ liệu từ trái sang phải, con trỏ tự di chuyển
	//0x04			Nhập dữ liệu từ phải sang trái, con trỏ tự di chuyển
	//0x05			Nhập dữ liệu từ phải sang trái, nhưng dịch màn hình
	//0x07			Nhập dữ liệu từ trái sang phải, nhưng dịch màn hình
	//0x10			Dịch con trỏ trái, không ảnh hưởng đến chữ
	//0x14			Dịch con trỏ phải, không ảnh hưởng đến chữ
	//0x18			Cuộn màn hình trái
	//0x1C			Cuộn màn hình phải
//0x80 + addr		Đưa con trỏ đến vị trí DDRAM
