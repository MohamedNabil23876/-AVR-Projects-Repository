/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: GANNA TAHER
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"


int main()
{



	DIO_u8SetPortDirection(DIO_u8PORTB,DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_OUTPUT);


	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN5,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN6,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_INPUT);

	DIO_u8SetPortValue(DIO_u8PORTD,DIO_u8PORT_HIGH);
	CLCD_voidInit();
	CLCD_VoidClear();
	CLCD_voidGoToXY(0,0);
	while (1)
	{
		u8 key;
		u32 num1 = 0, num2 = 0;
		u8 op = 0;
		s result = 0;

		CLCD_voidGoToXY(0, 0);

		while (1)
		{
			key = KPD_VoidScan();
			if (key != 0xFF)
			{
				if (key >= 0 && key <= 9)
				{
					num1 = num1 * 10 + (key );

				}
				else if (key == '+' || key == '-' || key == '*' || key == '/')
				{
					op = key;

					break;
				}
			}
		}

		while (1)
		{
			key = KPD_VoidScan();
			if (key != 0xFF)
			{
				if (key >= 0 && key <= 9)
				{
					num2 = num2 * 10 + (key );

				}
				else if (key == '=')
				{

					break;
				}
			}
		}

		switch (op)
		{
			case '+': result = num1 + num2; break;
			case '-': result = num1 - num2; break;
			case '*': result = num1 * num2; break;
			case '/':
				if (num2 != 0)
					result = num1 / num2;
				else
				{
					CLCD_voidSendCommand(0x01);
					CLCD_voidSendString("Div by Zero!");
					while (1);
				}
				break;
		}

		CLCD_VoidSendNumber(result);



	}

	return 0 ;
}


