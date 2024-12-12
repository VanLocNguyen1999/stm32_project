#include "stm32_config.h"
#include "pwm_hardware.h"
#include "update_interrupt_hardware.h"
#include "board.h"
#include "delay.h"

uint32_t counter;

#define STM32_PROJECT_UPDATE_1KHZ_ISR_HANDLER  TIM2_IRQHandler

void stm32_project_init(void);
int main(void) {

	delayms(1);
	stm32_project_init();
	while (1) {

	}

}

void stm32_project_init(void) {

	board_hardware_init();
	__disable_irq();
	update_1khz_it_hw_init_ex();
	update_it_hw_change_freq(1000);
	update_1khz_it_hw_enable();
	__enable_irq();
}
void STM32_PROJECT_UPDATE_1KHZ_ISR_HANDLER(void){
	counter ++;
	if(counter > 5000){

		counter = 0;
	}
	UPDATE_1KHZ_ISR_CLEAR_FLAG;
}

