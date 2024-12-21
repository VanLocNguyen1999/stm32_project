/*
 * project.c
 *
 *  Created on: Dec 19, 2024
 *      Author: vanlo
 */
#include "project.h"

void project_init(Project* p_project){

	keyboard_code_init(&p_project->keyboard_code);
	p_project->state = 0;
}

void project_update_keyboard_code(Project* p_project){

	keyboard_code_update_code(&p_project->keyboard_code);
}
