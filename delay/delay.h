/*
 * delay.h
 *
 *  Created on: Apr 4, 2024
 *      Author: vanlo
 */

#ifndef DELAY_DELAY_H_
#define DELAY_DELAY_H_
#include "stm32_config.h"

// SysTick_Handler function will be called every 1 us

static inline void delay_us(uint32_t us) {
    // Tính toán số chu kỳ cần thiết
    uint32_t cycles_per_us = HC_LOCK / 1000000; // Số chu kỳ trong 1 microsecond
    uint32_t total_cycles = us * cycles_per_us;

    // Thực hiện vòng lặp với số chu kỳ NOP tương ứng
    while (total_cycles--) {
        __asm("nop");
    }
}

static inline void delay_ms(uint32_t ms)
{
	// Wait until ms reach zero
	while (ms--)
	{
		// Delay 1ms
		delay_us(1000);
	}
}
#endif /* DELAY_DELAY_H_ */
