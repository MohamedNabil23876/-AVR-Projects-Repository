 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Nabil
 *
 * Created on:2/3/2020
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */

extern volatile uint8 Global_ADC_Value;


/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);



typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ADC_Clock;


typedef enum
{
	ref_volt =0 , AVCC = 1 , internal = 3
}ADC_ReferanceVoltage;


typedef enum
{
	INTERRUPT,POLLING
}ADC_Mode;

typedef enum
{
	CHANNAL_1,CHANNAL_2,CHANNAL_3,CHANNAL_4,CHANNAL_5
}ADC_Channal;


typedef struct{
	ADC_Clock clock;
	ADC_ReferanceVoltage Referance ;
	ADC_Mode Mode;
}ADC_ConfigType;


void ADC_init(const ADC_ConfigType *Config_ptr);

#endif /* ADC_H_ */
