/*
 * project.c
 *
 *  Created on: Dec 19, 2024
 *      Author: vanlo
 */
#include "project.h"

void project_init(Project* p_project){

	keyboard_init(&p_project->keyboard);
	fifo_queue_init(&p_project->keyboard_code);

	p_project->state = 0;
}
