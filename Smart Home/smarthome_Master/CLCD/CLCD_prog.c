// LIB
#include "../BIT_MATH.h"
#include "../STD_TYPES.h"
#include "../ERR_TYPE.h"
#include <util/delay.h>

//MCAL
#include "../DIO/DIO_interface.h"

//HAL
#include "CLCD_interface.h"
#include "CLCD_cfg.h"
#include "CLCD_prv.h"




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
