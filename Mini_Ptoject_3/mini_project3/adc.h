/*
 * adc.h
 *
 *  Created on: Jun 14, 2024
 *      Author: DELL
 */

#ifndef ADC_H_
#define ADC_H_

#include"std_types.h"

#define ADC_ReferenceVolatge uint8
#define ADC_Prescaler 		 uint8

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5


extern volatile uint16 adcResult;


typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_configType;


//void ADC_init(void);
void ADC_init(ADC_configType* Config_Ptr);
void ADC_readChannel(uint8 channelNum);

#endif /* ADC_H_ */
