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

uint32_t state_1 ;
uint32_t state_2 ;
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
	project_keyboard_update_columns(&project);
	UPDATE_1KHZ_ISR_CLEAR_FLAG;
}

void UPDATE_EXTI_C1_ISR_IRQ(void) {

	if (UPDATE_EXTI_C1_ISR_FLAG) {
		project_keyboard_set_states_columns(&project,1);
		UPDATE_EXTI_C1_ISR_CLEAR_FLAG;
	}
}

void UPDATE_EXTI_C2_ISR_IRQ(void) {

	if (UPDATE_EXTI_C2_ISR_FLAG) {
		project_keyboard_set_states_columns(&project,2);
		UPDATE_EXTI_C2_ISR_CLEAR_FLAG;
	}
}

void UPDATE_EXTI_C3_ISR_IRQ(void) {

	if (UPDATE_EXTI_C3_ISR_FLAG) {
		project_keyboard_set_states_columns(&project,3);
		UPDATE_EXTI_C3_ISR_CLEAR_FLAG;
	}
}

void UPDATE_EXTI_C4_ISR_IRQ(void) {

	if (UPDATE_EXTI_C4_ISR_FLAG) {
		project_keyboard_set_states_columns(&project,4);
		UPDATE_EXTI_C4_ISR_CLEAR_FLAG;
	}
}


