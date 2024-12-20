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
#include "fifo_queue.h"

typedef struct Project_t Project;
static inline void project_keyboard_update_columns(Project* p_project);
static inline uint8_t project_keyboard_get_columns(Project* p_project);

struct Project_t{

	Keyboard keyboard;
	Fifo_queue keyboard_code;

	uint8_t state;
};

void project_init(Project* p_project);

static inline void project_keyboard_update_columns(Project* p_project){

	keyboard_update_columns(&p_project->keyboard);
}

static inline uint8_t project_keyboard_get_columns(Project* p_project){

	return keyboard_get_columns(&p_project->keyboard);
}

static inline void project_keyboard_set_states_columns(Project* p_project, uint8_t columns){

	keyboard_set_states_columns(&p_project->keyboard, columns);
}
#endif /* SERVICES_PROJECT_PROJECT_H_ */
