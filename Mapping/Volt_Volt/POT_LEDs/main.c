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
#include "ADC_interface.h"

void main(void)
{
	DIO_u8SetPortDirection(DIO_u8PORTD, DIO_u8PORT_OUTPUT);    // LEDs
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_INPUT);// PA0 --> POT
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);

	ADC_voidInit();

	u32 Local_u32MillVolt;

	while (1)
	{
		Local_u32MillVolt = ((u32)ADC_u8GetChannelRead(ADC0) * 5000UL) / 256UL;
		if (Local_u32MillVolt < 75 )
			DIO_u8SetPortValue(DIO_u8PORTD, 0b00000000);
		else if (Local_u32MillVolt < 625)
			DIO_u8SetPortValue(DIO_u8PORTD, 0b00000001);
		else if (Local_u32MillVolt < 1250)
			DIO_u8SetPortValue(DIO_u8PORTD, 0b00000011);
		else if (Local_u32MillVolt < 1875)
			DIO_u8SetPortValue(DIO_u8PORTD, 0b00000111);
		else if (Local_u32MillVolt < 2500)
			DIO_u8SetPortValue(DIO_u8PORTD, 0b00001111);
		else if (Local_u32MillVolt < 3125)
			DIO_u8SetPortValue(DIO_u8PORTD, 0b00011111);
		else if (Local_u32MillVolt < 3750)
			DIO_u8SetPortValue(DIO_u8PORTD, 0b00111111);
		else if (Local_u32MillVolt < 4375)
			DIO_u8SetPortValue(DIO_u8PORTD, 0b01111111);
		else
			DIO_u8SetPortValue(DIO_u8PORTD, 0b11111111);
	}
}

