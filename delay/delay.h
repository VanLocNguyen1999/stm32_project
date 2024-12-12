/*
 * delay.h
 *
 *  Created on: Apr 4, 2024
 *      Author: vanlo
 */

#ifndef DELAY_DELAY_H_
#define DELAY_DELAY_H_
#include <stdint.h>

void DelayInit(void);
void delayus(uint32_t us);
void delayms(uint32_t ms);

#endif /* DELAY_DELAY_H_ */
