/*
 * main.c
 *
 *  Created on: Jul 28, 2025
 *      Author: lenovo
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include <util/delay.h>

#include "DIO/DIO_interface.h"
#include "Timer/TMR_interface.h"
#include "KeyPad/KPD_interface.h"
#include "CLCD/CLCD_interface.h"

# define PASSWORd 2532

void main(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_OUTPUT);

	/* KEY PAD	*/
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_INPUT);
	DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);

	/* CLCD */
	DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTB,DIO_u8PORT_OUTPUT);

	/*	BUZZER	*/
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_OUTPUT);

	CLCD_voidInit();
	TIMER0_voidInit();

	u8 Local_u8Counter = 0;
	u32 Local_u32PasVal;

	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("Enter password");
	_delay_ms(500);
	CLCD_VoidClear();

	while(1)
	{

		do
		{
			Local_u32PasVal = EnterNum();
			_delay_ms(300);
			if(Local_u32PasVal != PASSWORd && (Local_u8Counter < 4) )
			{
				CLCD_VoidClear();
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendString("Enter pass again");
				_delay_ms(1000);
			}
			CLCD_VoidClear();
			Local_u8Counter++;
		}while( (Local_u8Counter < 5) && (Local_u32PasVal != PASSWORd));

		if (Local_u32PasVal == PASSWORd)
		{
			WELCOME_MASSAGE();

		}

		if(Local_u32PasVal != PASSWORd)
		{
			CLCD_VoidClear();
			CLCD_voidGoToXY(0,0);
			CLCD_voidSendString("Failed");
			_delay_ms(1000);
			DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_HIGH);
		}
	}
}





