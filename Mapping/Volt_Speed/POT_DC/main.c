/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: GANNA TAHER
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"

void main(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8PIN_OUTPUT); // PD5 --> DC
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_INPUT);  // PA0 --> POT

	ADC_voidInit();
	TIMER1_voidInit();

	u16 Local_u16ADCvalue;
	u16 Local_u16PWMvalue;

	while(1)
	{
		Local_u16ADCvalue = ADC_u8GetChannelRead(ADC0);

		Local_u16PWMvalue = ((u32)Local_u16ADCvalue * 20000) / 1023UL;

		TIMER1_voidSetCompMatch(Local_u16PWMvalue);

		_delay_ms(100);
	}
}
