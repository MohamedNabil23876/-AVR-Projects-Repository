//LIB
#include "lib/BIT_MATH.h"
#include "lib/STD_TYPES.h"
#include "lib/ERR_TYPE.h"
#include <util/delay.h>

//MCAL
#include "../DIO/DIO_Interface.h"

//HAll
#include "../CLCD/CLCD_interface.h"
#include "KeyPad/KPD_interface.h"
#include "UART_interface.h"

u8 paddle[8] = {
		0b00000,
		0b11111,
		0b11111,
		0b11111,
		0b11111,
		0b00100,
		0b00100,
		0b00100
};


u8 arr[8] = {
		0b00000,
		0b00100,
		0b01110,
		0b11111,
		0b11111,
		0b01110,
		0b00100,
		0b00000
};

void main(void)
{
	// CLCD
	DIO_u8SetPortDirection(DIO_u8PORTA, DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTB, DIO_u8PORT_OUTPUT);

	//  KeyPad(PD0-PD3) Output
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_OUTPUT);

	// KeyPad (PD4-PD7) Input + Pull-up
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PIN_INPUT);

	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PIN_HIGH);

	/* TX(PD1) ,RX(PD0)*/
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_INPUT);

	UART_voidInit();
	CLCD_voidInt();

	CLCD_voidWriteSpectialCharacter(arr,3,0,1);

	u8 Local_u8Ball;

	while (1)
	{
		CLCD_voidWriteSpectialCharacter(paddle,1,0,0);

		u8 y = 0 ;
		u8 PressedKey ;
		u8 Local_u8Counter;

		do
		{
			PressedKey = KPD_u8GetPreessedKey();

		}while(PressedKey == 0xff);

		if (PressedKey=='+')
		{
			for(Local_u8Counter =1 ;Local_u8Counter<=15 ;Local_u8Counter++)
			{
				CLCD_voidWriteSpectialCharacter(arr,3,y,Local_u8Counter);
				_delay_ms(500);
				CLCD_voidGoToXY(y,Local_u8Counter);
				CLCD_voidSendData(' ');
				if(Local_u8Counter==15)
				{
					UART_voidSendData('a');
				}
			}
		}

		UART_u8ReveiveData(&Local_u8Ball);

		if(Local_u8Ball == 'b')
		{
			for(Local_u8Counter = 14 ; Local_u8Counter > 0 ;Local_u8Counter--)
			{
				CLCD_voidWriteSpectialCharacter(arr,3,0,Local_u8Counter);
				_delay_ms(500);
				CLCD_voidGoToXY(0,Local_u8Counter);
				CLCD_voidSendData(' ');
				if(Local_u8Counter==1)
				{
					CLCD_voidWriteSpectialCharacter(arr,3,y,Local_u8Counter);
					u32 time1=0;
					do
					{
						PressedKey = KPD_u8GetPreessedKey();
						time1++;
					}while((PressedKey!='+')&&(time1<2500));
					if (PressedKey !='+')
					{
						clear();
						CLCD_voidGoToXY(0,5);
						CLCD_voidSendString(" lose ");
						_delay_ms(1000);
						clear();
						return ;
					}
				}
			}
		}
	}
}
