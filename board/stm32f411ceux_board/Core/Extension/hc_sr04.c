/*
 * hc_sr04.c
 *
 *  Created on: Dec 26, 2024
 *      Author: vanlo
 */

#include "hc_sr04.h"


Hc_sr04* hc_sr04_create(void){

	Hc_sr04* hc_sr = (Hc_sr04*) malloc(sizeof(Hc_sr04));
	while(hc_sr == NULL){};
	hc_sr04_init(hc_sr);
	return hc_sr;
}
void hc_sr04_init(Hc_sr04* hc_sr){

	hc_sr->distance = 0.0f;
	hc_sr->duration = 0;

	hc_sr->time_ctr = 0;

	pluse_in_init(hc_sr->pluse_in, HC_SR_04_ECHO_STATE, HIGH, 500);
}
