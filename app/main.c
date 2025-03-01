/*
 * main.c
 *
 *  Created on: Mar 1, 2025
 *      Author: Admin
 */

#include "board.h"

uint16_t AD_RES = 0;

int main(void) {

	board_hardware_init_ex();

	while (1) {

		delay_ms(1);
		if (AD_RES > 2040) {
			lcd_gotoxy(8, 1);
			lcd_puts("volt > 2.5");
		} else {
			lcd_gotoxy(8, 1);
			lcd_puts("volt < 2.5");
		}
	}
}

void HAL_IncTick(void){

	uwTick += uwTickFreq;

}
