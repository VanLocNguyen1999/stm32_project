#include "stm32_config.h"
#include "pwm_hardware.h"
#include "update_interrupt_hardware.h"
#include "board.h"
#include "delay.h"
#include "exti_hardware.h"
#include "interrupt.h"
#include "keyboard_hardware.h"
#include "project.h"

uint32_t counter;
uint32_t test;
#define STM32_PROJECT_UPDATE_1KHZ_ISR_HANDLER  TIM2_IRQHandler(void)


Project project;

void stm32_project_init(void);
int main(void) {

	delay_ms(1);
	stm32_project_init();
	while (1) {

	}

}

void stm32_project_init(void) {

	__disable_irq();
	board_hardware_init();
	project_init(&project);
	exti_hardware_init_ex();
	update_1khz_it_hw_init_ex();
	update_1khz_it_hw_enable();
	exti_hardware_enable_interrupt();
	__enable_irq();
}
void STM32_PROJECT_UPDATE_1KHZ_ISR_HANDLER {

		UPDATE_1KHZ_ISR_CLEAR_FLAG;
}

