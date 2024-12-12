/*
 * adc_sensor.h
 *
 *  Created on: Apr 4, 2024
 *      Author: vanlo
 */

#ifndef COMPONENTS_ADC_SENSOR_ADC_SENSOR_H_
#define COMPONENTS_ADC_SENSOR_ADC_SENSOR_H_
#include "stm32_config.h"


typedef struct ADC_Sensor_t ADC_Sensor;
typedef float (*Get_Result)(const ADC_Sensor* p_ss);
typedef  int32_t (*Get_ADC_Itf)(const ADC_Sensor* p_ss);

struct ADC_Sensor_t {
        int32_t offset;
        float gain;
        Get_ADC_Itf get_adc;
        Get_Result get_result;
};

ADC_Sensor* sensor_create(Get_ADC_Itf impl, const float adc_gain, const int32_t adc_offset);
void sensor_init(ADC_Sensor* p_ss, Get_ADC_Itf impl, const float adc_gain, const int32_t adc_offset);

static OPTIMIZE_ATTR int32_t sensor_get_adc(const ADC_Sensor* p_ss){
	return p_ss->get_adc(p_ss);
}

void sensor_set_offset(ADC_Sensor* p_sensor,const int32_t offset);
void sensor_set_gain(ADC_Sensor* p_sensor,const float gain);
void sensor_set_result_impl(ADC_Sensor* p_ss,Get_Result impl);
void sensor_set_adc_impl(ADC_Sensor* p_ss,Get_ADC_Itf impl);

int32_t sensor_get_offset(const ADC_Sensor* p_sensor);
float sensor_get_gain(const ADC_Sensor* p_sensor);

static inline void sensor_reset_offset(ADC_Sensor* p_sensor){
        p_sensor->offset = 0;
}

static OPTIMIZE_ATTR float sensor_get_result(const ADC_Sensor* p_ss){
	return p_ss->get_result(p_ss);
}
#endif /* COMPONENTS_ADC_SENSOR_ADC_SENSOR_H_ */
