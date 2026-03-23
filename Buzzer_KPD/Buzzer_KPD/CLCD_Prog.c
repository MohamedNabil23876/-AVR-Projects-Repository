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

void CLCD_voidSendCommend(u8 Copy_u8Commend){

	/* set RS  == low for send commend*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_u8PIN_LOW);

	/* set RW -> low for writing*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Commend);
	/*enable*/

	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_HIGH);

	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_LOW);
}
void CLCD_voidSendData(u8 Copy_u8Data){

	/* set RS  == high for send commend*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_u8PIN_HIGH);

	/* set RW -> low for writing*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_u8PIN_LOW);

	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Data);

	/*enable*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_LOW);

}
void CLCD_voidInit(void){

	_delay_ms(35);
	CLCD_voidSendCommend(0b00111000);
	_delay_ms(1);
	CLCD_voidSendCommend(0b00001100);
	_delay_ms(1);
	CLCD_voidSendCommend(1);
	_delay_ms(2);

}

void CLCD_voidSendString(const char *Copy_u8Ptr){

	u8 Local_u8Counter = 0;
	while(Copy_u8Ptr[Local_u8Counter] !='\0'){
		CLCD_voidSendData(Copy_u8Ptr[Local_u8Counter]);
		Local_u8Counter++;
	}

}

void CLCD_voidGoToXY(u8 Copy_u8Ypos,u8 Copy_u8Xpos){
	u8 Local_u8Address;

	if(Copy_u8Ypos == 0){
		Local_u8Address = Copy_u8Xpos;
	}
	else if(Copy_u8Ypos == 1){
		Local_u8Address = 0x40 + Copy_u8Xpos;
	}
	SET_BIT(Local_u8Address,7);
	CLCD_voidSendCommend(Local_u8Address);

}

void CLCD_voidLoopXY(u8 Copy_u8Ypos,u8 Copy_u8Xpos){
	u8 Local_u8Counter;
	for(Local_u8Counter=0;Local_u8Counter<15;Local_u8Counter++){
		CLCD_voidSendCommend(0x1C);
		_delay_ms(10);
	}
	for(Local_u8Counter=0;Local_u8Counter<15;Local_u8Counter++){
		CLCD_voidSendCommend(0x18);
		_delay_ms(10);
	}
	CLCD_voidGoToXY( Copy_u8Ypos, Copy_u8Xpos);
}

void CLCD_voidWriteSpectialCharacter(u8 *Copy_pu8Arr ,u8 Copy_u8BlockNo,u8 Copy_u8XPos ,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress ;
	u8 Local_u8Counter ;

	Local_u8CGRAMAddress = Copy_u8BlockNo * 8 ;

	/* CGRAM Address */
	SET_BIT(Local_u8CGRAMAddress,6);
	CLCD_voidSendCommend(Local_u8CGRAMAddress);

	for(Local_u8Counter = 0 ; Local_u8Counter < 8 ;Local_u8Counter++)
	{
		/* Write inside CGRMA*/
		CLCD_voidSendData(Copy_pu8Arr[Local_u8Counter]);
	}

	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);


	CLCD_voidSendData(Copy_u8BlockNo);
}

void CLCD_voidWriteNumber (u32 Copy_u32Number)
{

	u8 Arr[20] ;
	u8 i=0 ;
	while ( Copy_u32Number > 0 )
	{
		Arr[i] = Copy_u32Number % 10 ;
		Copy_u32Number /= 10 ;
		i++;
	}
	i--;
	for( s16 j=i ; j>=0 ; j--)
	{
		CLCD_voidSendData ( Arr[j] + '0' );
	}
}
void CLCD_VoidClear(void){

	CLCD_voidSendCommend(0x01);  // Clear display
	_delay_ms(2);
}

void CLCD_voidSTWA(void){

	u8 Local_u8Second  ;            u8 Local_u8Minute  ;                u8 Local_u8Hours  ;
	u8 Local_u8Srart;              u8 Local_u8Stop=1;                 u8 Local_u8Reset;

	DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN0,&Local_u8Srart);
	if (Local_u8Srart == 0){
		for(Local_u8Second = 1;Local_u8Second <= 24;Local_u8Second++){
			for(Local_u8Minute=1; Local_u8Minute <= 60 ;Local_u8Minute++){
				for(Local_u8Hours =0;Local_u8Hours <=60;Local_u8Hours++){
					CLCD_voidWriteNumber(Local_u8Second);
					_delay_ms(10);
				}
				CLCD_voidWriteNumber(Local_u8Minute);
				_delay_ms(60);
			}
			CLCD_voidWriteNumber(Local_u8Minute);
			_delay_ms(100);
		}
		/*
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8Stop);
		if (Local_u8Srart == 0){
			CLCD_voidWriteSpectialCharacter(Local_u8Second,3,5,0);
			CLCD_voidWriteSpectialCharacter(Local_u8Minute,2,2,0);
			CLCD_voidWriteSpectialCharacter(Local_u8Minute,1,0,0);
		}
		else if(Local_u8Srart == 1){
			return;
		}
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8Reset);
		if (Local_u8Reset == 0){
			return;
		}
	}
	else if (Local_u8Srart == 1){
		Local_u8Second = 0 ; Local_u8Minute = 0 ; Local_u8Hours = 0;
		CLCD_voidWriteSpectialCharacter(Local_u8Second,3,5,0);
		CLCD_voidWriteSpectialCharacter(Local_u8Minute,2,2,0);
		CLCD_voidWriteSpectialCharacter(Local_u8Minute,1,0,0);

	}*/
	}
}
