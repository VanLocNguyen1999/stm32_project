/*
 * adc_sensor.c
 *
 *  Created on: Apr 4, 2024
 *      Author: vanlo
 */

#include "adc_sensor.h"
#include "stdio.h"
#include "stdlib.h"

static float sensor_get_result_default_impl(const ADC_Sensor* p_ss);

void sensor_init(ADC_Sensor* p_ss, Get_ADC_Itf impl, const float adc_gain, const int32_t adc_offset)
{
	p_ss->get_adc					=	impl;
	p_ss->get_result				=	sensor_get_result_default_impl;
	p_ss->gain						=	adc_gain;
	p_ss->offset					=	adc_offset;
}
ADC_Sensor* sensor_create(Get_ADC_Itf impl, const float adc_gain, const int32_t adc_offset){

        ADC_Sensor* p_ss=(ADC_Sensor*)malloc(sizeof(ADC_Sensor));
        while(p_ss==NULL){

        };
        sensor_init(p_ss, impl, adc_gain, adc_offset);
        return p_ss;
}
static OPTIMIZE_ATTR float sensor_get_result_default_impl(const ADC_Sensor* p_ss){

	int32_t adc = sensor_get_adc(p_ss);
	return (float)((adc - p_ss->offset)) * p_ss->gain;
}
void sensor_set_offset(ADC_Sensor* p_sensor,const int32_t offset){

        p_sensor->offset=offset;
}

void sensor_set_gain(ADC_Sensor* p_sensor,const float gain){

        p_sensor->gain=gain;
}

int32_t sensor_get_offset(const ADC_Sensor* p_sensor){

        return  p_sensor->offset;
}

float sensor_get_gain(const ADC_Sensor* p_sensor){

        return p_sensor->gain;
}
