/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>


#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"



int main(void){



	DIO_u8SetPortDirection(DIO_u8PORTA, DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTB, DIO_u8PORT_OUTPUT);


	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_OUTPUT);


	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN4, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN6, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN7, DIO_u8PIN_INPUT);

	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN4, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN5, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN6, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN7, DIO_u8PIN_HIGH);
	CLCD_voidInit();



   while (1){
	u8 Local_u8Key;
	WELCOME_MASSAGE();
	Local_u8Key =KPD_u8GetPreessedKey();
	if (Local_u8Key ==4){
		while(1)

		{   LINE_MASSAGE();
		Local_u8Key =KPD_u8GetPreessedKey();
		if(Local_u8Key ==1){
			clear();
			GAME_VoidLCD(0);
		}else if(Local_u8Key ==2){
			clear();
			GAME_VoidLCD(1);
		}

		}
	}else if (Local_u8Key ==5){
		while (1){
			GAME_Merge_Ball_Paddle();
			GAME_Merge_Ball_Paddle_Reverse();
		}
	}

   }
	return 0 ;
}
