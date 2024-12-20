/*
 * project.h
 *
 *  Created on: Dec 19, 2024
 *      Author: vanlo
 */

#ifndef SERVICES_PROJECT_PROJECT_H_
#define SERVICES_PROJECT_PROJECT_H_

#include "stm32_config.h"
#include "pwm_hardware.h"
#include "update_interrupt_hardware.h"
#include "board.h"
#include "delay.h"
#include "exti_hardware.h"
#include "interrupt.h"
#include "keyboard_hardware.h"

typedef struct Project_t Project;
static inline void project_keyboard_columns_set(Project* p_project, const uint8_t columns);
struct Project_t{

	Keyboard* keyboard;

	uint8_t state;
};

void project_init(Project* p_project);

static inline void project_keyboard_columns_set(Project* p_project, uint8_t columns){

	keyboard_columns_set(p_project->keyboard, columns);
}
#endif /* SERVICES_PROJECT_PROJECT_H_ */
