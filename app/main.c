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
uint32_t check = 1;

#define STM32_PROJECT_UPDATE_1KHZ_ISR_HANDLER  TIM2_IRQHandler(void)
#define SYSTEM_TICK_UPDATE		HAL_IncTick
Project project;

typedef enum
{
	INIT_STATE__0_BEGIN = 0,
	INIT_STATE__1_ISR_OK = 1,
	INIT_STATE__5_COMPLETED = 2
}Init_State_t;
Init_State_t init_state = INIT_STATE__0_BEGIN;

void stm32_project_init(void);
int main(void) {

//	delay_ms(1);
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
	init_state = INIT_STATE__1_ISR_OK;
	__enable_irq();
	init_state = INIT_STATE__5_COMPLETED;
}
void STM32_PROJECT_UPDATE_1KHZ_ISR_HANDLER {

	project_keyboard_code_scan(&project);
	project_update_keyboard_code(&project);
	UPDATE_1KHZ_ISR_CLEAR_FLAG;
}

void UPDATE_EXTI9_5_ISR_IRQ(void) {

	if (UPDATE_EXTI9_5_ISR_FLAG) {
		UPDATE_EXTI9_5_ISR_CLEAR_FLAG;
	}
}

void SYSTEM_TICK_UPDATE(void){

	project_keyboard_code_scan_columns(&project);

}

