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
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN5, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
	TIMER1_voidInit();
	TIMER1_voidSetICR(20000);
	ADC_voidInit();
	u8 Local_u8Angle;
	u32 Local_u32OutAngle;

	while (1)
	{
		Local_u8Angle = ADC_u8GetChannelRead(ADC0);
		Local_u32OutAngle =(((u32)Local_u8Angle * 1750UL) / 255UL) + 750;

		TIMER1_voidSetCompMatch(Local_u32OutAngle);
	}
}
