/*
 * CLCD_prog.c
 *
 *  Created on: Jul 20, 2025
 *      Author: lenovo
 */

//LIB
#include "../lib/BIT_MATH.h"
#include "../lib/STD_TYPES.h"
#include "../lib/ERR_TYPE.h"
#include <util/delay.h>

//MCAL
#include "../DIO/DIO_Interface.h"


//HAll
#include "../CLCD/CLCD_cfg.h"
#include "../CLCD/CLCD_interface.h"
#include "../CLCD/CLCD_prv.h"

void clear(void)
{
	CLCD_voidSendCommand(0x01);
	_delay_ms(2);
}

void CLCD_VoidClear(void)
{
	CLCD_voidSendCommand(0x01);
	_delay_ms(2);
}


void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
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

void CLCD_voidGoToXY(u8 Copy_u8Ypos,u8 Copy_u8Xpos)
{
	u8 Local_u8Address;
	if(Copy_u8Ypos == 0)
	{
		Local_u8Address = Copy_u8Xpos;
	}
	else if(Copy_u8Ypos == 1)
	{
		Local_u8Address = 0x40 + Copy_u8Xpos;
	}
	SET_BIT(Local_u8Address,7);

	CLCD_voidSendCommand(Local_u8Address);
}

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/* SET RS = 0 TO SEND COMMAND */
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_u8PIN_LOW);

	/* SET RW = 0 TO WrITE */
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_u8PIN_LOW);

	/* SET PORT VALUE */
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Command);

	/* SET ENABLE */
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_LOW);

}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/* SET RS = 1 TO SEND DATA */
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_u8PIN_HIGH);

	/* SET RW = 0 TO WrITE */
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_u8PIN_LOW);

	/* SET PORT VALUE */
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Data);

	/* SET ENABLE */
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_LOW);

}

void CLCD_voidInt(void)
{
	_delay_ms(40);

	CLCD_voidSendCommand(0b00111000);
	CLCD_voidSendCommand(0b00001100);
	CLCD_voidSendCommand(0b00000001);
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

