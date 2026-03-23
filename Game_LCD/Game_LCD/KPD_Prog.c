/*
 * KEP_prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


//LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

//MCAL
#include "DIO_interface.h"
//HAL
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "KPD_cfg.h"
#include "KPD_Prv.h"

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

u8 KPD_u8GetPreessedKey(void)
{
	u8 Local_u8PreesedKey  = KPD_u8No_PREESEDkAY ;
	u8 Local_u8PinStatus;
	u8 Local_u8CounterColumn ;
	u8 Local_u8CounterRow ;

	u8 LOcal_u8ColumnArr[SIZE_COL] ={KPD_u8COLUMN0_PIN,KPD_u8COLUMN1_PIN,KPD_u8COLUMN2_PIN,KPD_u8COLUMN3_PIN};
	u8 LOcal_u8RowArr[SIZE_ROW] = {KPD_u8ROW0_PIN,KPD_u8ROW1_PIN,KPD_u8ROW2_PIN,KPD_u8ROW3_PIN};
	u8 Local_u8KPDArr[SIZE_ROW][SIZE_COL] = KPD_u8ARR ;

	for(Local_u8CounterColumn = 0 ;Local_u8CounterColumn < SIZE_COL ;Local_u8CounterColumn++)
	{
		/* Active current Column */
		DIO_u8SetPinValue(KPD_8uPORT,LOcal_u8ColumnArr[Local_u8CounterColumn],DIO_u8PIN_LOW);

		for(Local_u8CounterRow = 0 ;Local_u8CounterRow < SIZE_ROW ;Local_u8CounterRow++)
		{
			/* read Current Row */
			DIO_u8ReadPinValue(KPD_8uPORT,LOcal_u8RowArr[Local_u8CounterRow] ,&Local_u8PinStatus );

			if(Local_u8PinStatus == DIO_u8PIN_LOW)
			{

				Local_u8PreesedKey = Local_u8KPDArr[Local_u8CounterRow][Local_u8CounterColumn] ;

				while(Local_u8PinStatus == DIO_u8PIN_LOW)
				{
					DIO_u8ReadPinValue(KPD_8uPORT,LOcal_u8RowArr[Local_u8CounterRow] ,&Local_u8PinStatus );

				}




				return  Local_u8PreesedKey ;
			}

		}
		// Deactivate current column
		DIO_u8SetPinValue(KPD_8uPORT,LOcal_u8ColumnArr[Local_u8CounterColumn],DIO_u8PIN_HIGH);
	}


	return Local_u8PreesedKey;
}

void clear(void)
{
	CLCD_voidSendCommand(0x01);
	_delay_ms(2);
}

u32 KPD_VoidScan( ){
	u32 value,temp;
	do
	{

		value= KPD_u8GetPreessedKey();
	}while(value == 0xff);
	switch (value){
	case'+':
		CLCD_voidSendData('+');
		break;
	case'-':
		CLCD_voidSendData('-');
		break;
	case'*':
		CLCD_voidSendData('*');
		break;
	case'=':
		CLCD_voidSendData('=');
		break;
	case'c':
		CLCD_VoidClear();
		temp=KPD_VoidScan( );
		return temp;
		break;
	case'/':
		CLCD_voidSendData('/');
		break;
	default :
		CLCD_VoidSendNumber(value);
		break;
	}
	return value ;
}


void GAME_VoidLCD(u8 y ){

	u8 Local_u8key,Local_u8Counter;

	CLCD_voidWriteSpectialCharacter(paddle,1,y,0);
	CLCD_voidWriteSpectialCharacter(paddle,2,y,15);
	CLCD_voidWriteSpectialCharacter(arr,3,y,1);
	do
	{
		Local_u8key = KPD_u8GetPreessedKey();

	}while(Local_u8key == 0xff);
	if (Local_u8key=='+')
	{
		for(Local_u8Counter =1 ;Local_u8Counter<=14 ;Local_u8Counter++)
		{
			CLCD_voidWriteSpectialCharacter(arr,3,y,Local_u8Counter);
			_delay_ms(500);
			CLCD_voidGoToXY(y,Local_u8Counter);
			CLCD_voidSendData(' ');
			if(Local_u8Counter==14)
			{
				CLCD_voidWriteSpectialCharacter(arr,3,y,Local_u8Counter);
				u32 time=0;
				do
				{

					Local_u8key = KPD_u8GetPreessedKey();


					time++;
					//_delay_ms(2);
				}while((Local_u8key!='-')&&(time<2500));
				if( Local_u8key !='-')
				{
					clear();
					CLCD_voidGoToXY(0,5);
					CLCD_voidSendString(" lose ");
					_delay_ms(1000);
					clear();
					return;

				}
				if (Local_u8key=='-')
				{
					for(Local_u8Counter =14 ;Local_u8Counter>0 ;Local_u8Counter--)
					{
						CLCD_voidWriteSpectialCharacter(arr,3,y,Local_u8Counter);
						_delay_ms(500);
						CLCD_voidGoToXY(y,Local_u8Counter);
						CLCD_voidSendData(' ');
						if(Local_u8Counter==1)
						{
							CLCD_voidWriteSpectialCharacter(arr,3,y,Local_u8Counter);
							u32 time1=0;
							do
							{


								Local_u8key = KPD_u8GetPreessedKey();


								time1++;
								//_delay_ms(2);
							}while((Local_u8key!='+')&&(time1<2500));
							if (Local_u8key !='+')
							{
								clear();
								CLCD_voidGoToXY(0,5);
								CLCD_voidSendString(" lose ");
								_delay_ms(1000);
								clear();

								return;
							}


						}


					}

				}
			}

		}
	}

}

void WELCOME_MASSAGE(void){


	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("mode1 enter 4 ");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("mode2 enter 5 ");



}
void LINE_MASSAGE(void){


	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("LINE1 enter 1 ");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("LINE2 enter 2 ");



}
void paddle_show(void) {
	u8 z; // mode 2
	u8 y;

	z=KPD_u8GetPreessedKey();
	if (z==8){
		y=0;
		clear() ;
		CLCD_voidWriteSpectialCharacter(paddle,1,y,0);
		CLCD_voidWriteSpectialCharacter(paddle,2,y,15);
	}else if (z==5){
		y=1;
		clear() ;
		CLCD_voidWriteSpectialCharacter(paddle,1,y,0);
		CLCD_voidWriteSpectialCharacter(paddle,2,y,15);
	}
}

void BALL_show(void){

	u8 Local_u8Counter;

	for(Local_u8Counter =1 ;Local_u8Counter<=14 ;Local_u8Counter++)
	{
		CLCD_voidWriteSpectialCharacter(arr,3,0,Local_u8Counter);
		_delay_ms(500);
		CLCD_voidGoToXY(0,Local_u8Counter);
		CLCD_voidSendData(' ');

		CLCD_voidWriteSpectialCharacter(arr,3,1,Local_u8Counter);
		_delay_ms(500);
		CLCD_voidGoToXY(1,Local_u8Counter);
		CLCD_voidSendData(' ');

	}
}

void GAME_Merge_Ball_Paddle(void){
	u8 Local_u8key, paddle_row = 0, ball_row = 0;
	u8 Local_u8Counter;

	for(Local_u8Counter = 1; Local_u8Counter <= 14; Local_u8Counter++) {
		u16 steps = 30;

		while(steps--) {
			Local_u8key = KPD_u8GetPreessedKey();
			if(Local_u8key == 8){
				paddle_row = 0;
			} else if(Local_u8key == 5){
				paddle_row = 1;
			}


			clear();
			CLCD_voidWriteSpectialCharacter(paddle, 1, paddle_row, 0);
			CLCD_voidWriteSpectialCharacter(paddle, 2, paddle_row, 15);
			CLCD_voidWriteSpectialCharacter(arr, 3, ball_row, Local_u8Counter);

			_delay_ms(10);
		}

		CLCD_voidGoToXY(ball_row, Local_u8Counter);
		CLCD_voidSendData(' ');

		ball_row = !ball_row;

		u32 time=0;
		if (Local_u8Counter==14){
			if (paddle_row == ball_row){
				clear ();
				CLCD_voidGoToXY(0,5);
				CLCD_voidSendString(" lose ");
				_delay_ms(1000);
				clear();
			}
		}
	}
}

void GAME_Merge_Ball_Paddle_Reverse(void){
	u8 Local_u8key, paddle_row = 0, ball_row = 0;


	for(s8 Local_u8Counter = 14; Local_u8Counter >= 1; Local_u8Counter--) {
		u16 steps = 30;

		while(steps--) {
			Local_u8key = KPD_u8GetPreessedKey();
			if(Local_u8key == 8){
				paddle_row = 0;
			} else if(Local_u8key == 5){
				paddle_row = 1;
			}

			clear();

			CLCD_voidWriteSpectialCharacter(paddle, 1, paddle_row, 0);
			CLCD_voidWriteSpectialCharacter(paddle, 2, paddle_row, 15);

			CLCD_voidWriteSpectialCharacter(arr, 3, ball_row, Local_u8Counter);

			_delay_ms(10);
		}

		CLCD_voidGoToXY(ball_row, Local_u8Counter);
		CLCD_voidSendData(' ');

		ball_row = !ball_row;

		if (Local_u8Counter == 1) {
			if (paddle_row == ball_row) {
				clear();
				CLCD_voidGoToXY(0, 5);
				CLCD_voidSendString(" LOSE ");
				_delay_ms(1000);
				clear();
			}
		}
	}
}
