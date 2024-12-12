/*
 * delay.c
 *
 *  Created on: Apr 4, 2024
 *      Author: vanlo
 */


#include "delay.h"
// SysTick_Handler function will be called every 1 us

void delayus(uint32_t us) {
	for (uint32_t i = 0; i < us; i++) {
		for (uint32_t j = 0; j < 8; j++) {
			// Thực hiện một lệnh nop để tạo ra độ trễ
			__asm("nop");
		}
	}
}

void delayms(uint32_t ms)
{
	// Wait until ms reach zero
	while (ms--)
	{
		// Delay 1ms
		delayus(1000);
	}
}

