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
#include "keyboard_code.h"

typedef struct Project_t Project;


void project_update_keyboard_code(Project* p_project);
static inline void project_keyboard_code_scan_columns(Project* p_project);

struct Project_t{

	Keyboard_code keyboard_code;
	uint8_t state;
};

void project_init(Project* p_project);

static inline void project_keyboard_code_scan_columns(Project* p_project){

	keyboard_code_scan(&p_project->keyboard_code);
}

static inline void project_keyboard_code_scan(Project* p_project){

	keyboard_code_scan(&p_project->keyboard_code);
}
#endif /* SERVICES_PROJECT_PROJECT_H_ */
