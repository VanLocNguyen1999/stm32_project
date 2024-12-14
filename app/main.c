#include "stm32_config.h"
#include "pwm_hardware.h"
#include "update_interrupt_hardware.h"
#include "board.h"
#include "delay.h"
#include "exti_hardware.h"
#include "interrupt.h"

uint32_t counter;
bool sate_1;
bool sate_2;
bool sate_3;

#define STM32_PROJECT_UPDATE_1KHZ_ISR_HANDLER  TIM2_IRQHandler(void)

void stm32_project_init(void);
int main(void) {

	delay_ms(1);
	stm32_project_init();
	while (1) {

	}

}

void stm32_project_init(void) {

	board_hardware_init();
	disable_all_interrupt();
	interrupt_hardware_init();
	interrupt_hardware_enable();
	enable_all_interrupt();
}
void STM32_PROJECT_UPDATE_1KHZ_ISR_HANDLER{

	BOARD_TP1_TOGGLEPIN;
	counter ++;
	if(counter > 5000){

		counter = 0;
	}
	UPDATE_1KHZ_ISR_CLEAR_FLAG;
}

void UPDATE_EXTI_ISR_IRQ {

	if (UPDATE_EXTI_ISR_FLAG) {
		counter = 1;
	} else {
		counter = 10;
	}

}
