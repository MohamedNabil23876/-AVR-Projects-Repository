/*
 * ADC_interface.h
 *
 *  Created on: ???/???/????
 *      Author: HP
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7



void ADC_voidInit(void);
u8 ADC_u8GetChannelRead(u8 Copy_u8Cahannel);



#endif /* ADC_INTERFACE_H_ */
