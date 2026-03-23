/*

 * main.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "main.h"

int main (void)
{
	//CLCD
	DIO_u8SetPortDirection(DIO_u8PORTA, DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTB, DIO_u8PORT_OUTPUT);

	//KPD
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PIN_INPUT);

	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PIN_HIGH);

	// SPI
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN5, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN6, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN4, DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN4, DIO_u8PIN_HIGH);

	// door ADC0
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8PIN_OUTPUT);

	// SPI int
	SPI_voidInit();
	TIMER1_voidInit();
	TIMER1_voidSetICR(20000);

	/* welcome massage */
	Welcome();

	/* login */
	LogIn();

	/* start */
	StartMenue();

	while (1)
	{
		/* scan KPD */
		ScanKPD();
	}

	return 0 ;
}
