/*
 * ISR.c
 *
 *  Created on: Dec 19, 2024
 *      Author: vanlo
 */


#include "exti_hardware.h"
#include "main.h"

extern Project project;

//void UPDATE_EXTI_C1_ISR_IRQ {
//
//	project.state = UPDATE_EXTI_C1_ISR_FLAG;
//	if (UPDATE_EXTI_C1_ISR_FLAG) {
//
//		project.keyboard->columns = 1;
//		UPDATE_EXTI_C1_ISR_CLEAR_FLAG;
//	} else {
//		project.keyboard->columns = 0;
//	}
//}
//
//void UPDATE_EXTI_C2_ISR_IRQ {
//
//	if (UPDATE_EXTI_C2_ISR_FLAG) {
//		project.keyboard->columns = 2;
//		UPDATE_EXTI_C2_ISR_CLEAR_FLAG;
//	} else {
//		project.keyboard->columns = 0;
//	}
//}
//
//void UPDATE_EXTI_C3_ISR_IRQ {
//
//	if (UPDATE_EXTI_C3_ISR_FLAG) {
//		project.keyboard->columns = 3;
//		UPDATE_EXTI_C3_ISR_CLEAR_FLAG;
//	} else {
//		project.keyboard->columns = 0;
//	}
//}
//
//void UPDATE_EXTI_C4_ISR_IRQ {
//
//	if (UPDATE_EXTI_C4_ISR_FLAG) {
//		project.keyboard->columns = 4;
//		UPDATE_EXTI_C4_ISR_CLEAR_FLAG;
//	} else {
//		project.keyboard->columns = 0;
//	}
//}
