#include "main.h"
#include "stm32_config.h"
#include "lcd_16x2.h"
#include "pwm_hardware.h"

int main(void) {

	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	pwm_hardware_init_ex();
	LCD_Init();
	LCD_Gotoxy(1, 0);
	LCD_Puts("NGUYEN VAN LOC");
	LCD_Gotoxy(8, 1);
	LCD_Puts("SELEX");
	while (1) {

	};
}

