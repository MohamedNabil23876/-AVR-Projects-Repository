/*
 * CLCD_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: HP
 */
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_ERR.h"

#include "DIO_Interface.h"

#include "CLCD_interface.h"
#include "CLCD_Cfg.h"
#include "CLCD_Prv.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/* RS --> 0 ( Send command )*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_u8PIN_LOW);

	/* RW --> 0 (Write)*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_u8PIN_LOW);

	/* Send Command */

	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Command);

	/* Enable Puls */
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_HIGH);
//	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_LOW);

}


void CLCD_voidSendData(u8 Copy_u8Data)
{
	/* RS --> 1 ( Send Data )*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_u8PIN_HIGH);

	/* RW --> 0 (Write)*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_u8PIN_LOW);

	/* Send Command */

	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Data);

	/* Enable Puls */
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_HIGH);
//	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_LOW);

}


void CLCD_voidInit(void)
{

	/*wait for more than 30 ms*/
	_delay_ms(35);

	/* N --> number of line (2 line ) , F --> Font Size (5*8) */
	CLCD_voidSendCommand(0b00111000);
    _delay_ms(1);

	/* D --> Display Enable , C --> Cursor disable , B --> Blink Cursor */
	CLCD_voidSendCommand(0b00001100);
    _delay_ms(1);


	/* Display Clear  */
	CLCD_voidSendCommand(1);
    _delay_ms(2);


}


void CLCD_voidSendString(const char *Copy_pcString)
{
	u8 Local_u8Counter = 0 ;

	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}

}


void CLCD_voidGoToXY(u8 Copy_u8XPos ,u8 Copy_u8YPos)
{
	u8 Local_u8Address ;


	if(Copy_u8XPos == 0)
	{
		Local_u8Address = Copy_u8YPos ;
	}
	else if(Copy_u8XPos == 1)
	{
		Local_u8Address = Copy_u8YPos + 0x40 ;
	}

	Local_u8Address += 128 ;

	CLCD_voidSendCommand(Local_u8Address);

}



void CLCD_voidWriteSpectialCharacter(u8 *Copy_pu8Arr ,u8 Copy_u8BlockNo,u8 Copy_u8XPos ,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress ;
	u8 Local_u8Counter ;

	Local_u8CGRAMAddress = Copy_u8BlockNo * 8 ;

	/* CGRAM Address */
	SET_BIT(Local_u8CGRAMAddress,6);
	CLCD_voidSendCommand(Local_u8CGRAMAddress);

	for(Local_u8Counter = 0 ; Local_u8Counter < 8 ;Local_u8Counter++)
	{
		/* Write inside CGRMA*/
		CLCD_voidSendData(Copy_pu8Arr[Local_u8Counter]);
	}

	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);


	CLCD_voidSendData(Copy_u8BlockNo);
}


void CLCD_VoidSendNumber(u32 Copy_u32Number)
{
	s8 i = 0;
	u32 Local_u32Number;
	u8 Local_u8arr[40];
	do
	{
		if(i == 0)
		{
			Local_u32Number = Copy_u32Number;
			Local_u32Number %= 10;
			Local_u8arr[i] = Local_u32Number;
		}
		else
		{
			Copy_u32Number /= 10;
			Local_u32Number = Copy_u32Number;
			Local_u32Number %= 10;
			if(Copy_u32Number == 0)
				break;
			else
			Local_u8arr[i] = Local_u32Number;
		}
		i++;
	} while(Copy_u32Number != 0);
	for (i = --i ; i >= 0 ; i--)
		CLCD_voidSendData(Local_u8arr[i] + '0');
}
void CLCD_VoidClear(void){

	CLCD_voidSendCommand(0x01);  // Clear display
	_delay_ms(2);
}


void STOP_WATCH(void){
	 u16 i = 0;
		u32 digit1 = 0, digit2 = 0, digit3 = 0, digit4 = 0, digit5 = 0, digit6 = 0;
	u8 value1,value2;
	while(1){
	DIO_u8ReadPinValue(DIO_u8PORTC, DIO_u8PIN1, &value2);
			if (value2 !=0){
			u16 number = i;
			digit5 = number / 10;
			digit6 = number % 10;

			CLCD_voidGoToXY(0, 1); CLCD_VoidSendNumber(digit1);
			CLCD_voidGoToXY(0, 2); CLCD_VoidSendNumber(digit2);
			CLCD_voidGoToXY(0, 4); CLCD_VoidSendNumber(digit3);
			CLCD_voidGoToXY(0, 5); CLCD_VoidSendNumber(digit4);
			CLCD_voidGoToXY(0, 7); CLCD_VoidSendNumber(digit5);
			CLCD_voidGoToXY(0, 8); CLCD_VoidSendNumber(digit6);

			_delay_ms(100);
			i++;

			if (i == 60) {
				i = 0;
				digit4++;
				if (digit4 == 10) {
					digit4 = 0;
					digit3++;
					if (digit3 == 6) {
						digit3 = 0;
						digit2++;
						if (digit2 == 10) {
							digit2 = 0;
							digit1++;
							if (digit1 == 10) {
								digit1 = 0;
							}
						}
					}
				}
			}

			DIO_u8ReadPinValue(DIO_u8PORTC, DIO_u8PIN0, &value1);
			if (value1 == 0) {
				digit1=0;
				digit2=0;
				digit3=0;
				digit4=0;
				digit5=0;
				digit6=0;
				i=0;
			}
		}
}
}
