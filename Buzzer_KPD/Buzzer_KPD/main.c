/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "GIE_Interface.h"
#include "TIMER_interface.h"
#include "EXIT_interface.h"

#include <util/delay.h>

#include "KPD_interface.h"



void main()
{



	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_INPUT);
	DIO_u8SetPortValue(DIO_u8PORTA,DIO_u8PORT_HIGH);

	TIMER0_voidInit();
	u8 Local_u8Key ;
	while(1)
	{
		do {
			Local_u8Key=KPD_u8GetPreessedKey();
		}while(Local_u8Key==0xff);

		if (Local_u8Key==1){
			TIMER0_voidSetCompMatch(62);
			_delay_ms(10000);
		}
		else if (Local_u8Key==2){
			TIMER0_voidSetCompMatch(125);
			_delay_ms(10000);
		}

		else if (Local_u8Key==3){
			TIMER0_voidSetCompMatch(187);
			_delay_ms(10000);
		}
		else if (Local_u8Key==4){
			TIMER0_voidSetCompMatch(250);
			_delay_ms(10000);
		}

	}
}

