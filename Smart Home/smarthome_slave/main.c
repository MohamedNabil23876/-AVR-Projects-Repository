/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "main.h"



int main (void)
{
	// SPI
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN5, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN6, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_INPUT);

	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN4, DIO_u8PIN_INPUT);

	// ADC0 temp

	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_INPUT);
	// ADC1 LDR
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_INPUT);

	// LED
	DIO_u8SetPortDirection(DIO_u8PORTC, DIO_u8PORT_OUTPUT);

	// BUZZER
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_OUTPUT);

	//fan
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8PIN_OUTPUT);

	// SPI int
	SPI_voidInit();

	ADC_voidInit();

	TIMER1_voidInit();
	TIMER1_voidSetICR(5000);

	while (1)
	{
		System();
	}

	return 0 ;
}
