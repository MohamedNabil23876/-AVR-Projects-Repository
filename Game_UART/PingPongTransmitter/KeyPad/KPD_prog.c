//LIB
#include "../lib/BIT_MATH.h"
#include "../lib/STD_TYPES.h"
#include "../lib/ERR_TYPE.h"
#include "util/delay.h"

//MCAL
#include "../DIO/DIO_Interface.h"
#include "../CLCD/CLCD_interface.h"

//HAL
#include "KPD_interface.h"
#include "KPD_CFG.h"
#include "KPD_prv.h"


u8 KPD_u8GetPreessedKey(void)
{
	u8 Local_u8PreesedKey  = KPD_u8PRESSEDKEY ;
	u8 Local_u8PinStatus;
	u8 Local_u8CounterColumn ;
	u8 Local_u8CounterRow ;

	u8 LOcal_u8ColumnArr[SIZE_COL] ={KPD_u8COLUMN0_PIN,KPD_u8COLUMN1_PIN,KPD_u8COLUMN2_PIN,KPD_u8COLUMN3_PIN,};
	u8 LOcal_u8RowArr[SIZE_ROW] = {KPD_u8ROW0_PIN,KPD_u8ROW1_PIN,KPD_u8ROW2_PIN,KPD_u8ROW3_PIN};
	u8 Local_u8KPDArr[SIZE_ROW][SIZE_COL] = KPD_u8ARR ;

	for(Local_u8CounterColumn = 0 ;Local_u8CounterColumn < SIZE_COL ;Local_u8CounterColumn++)
	{
		/* Active current Column */
		DIO_u8SetPinValue(KPD_u8PORT,LOcal_u8ColumnArr[Local_u8CounterColumn],DIO_u8PIN_LOW);

		for(Local_u8CounterRow = 0 ;Local_u8CounterRow < SIZE_ROW ;Local_u8CounterRow++)
		{
			/* read Current Row */
			DIO_u8ReadPinValue(KPD_u8PORT,LOcal_u8RowArr[Local_u8CounterRow] ,&Local_u8PinStatus );

			if(Local_u8PinStatus == DIO_u8PIN_LOW)
			{

				Local_u8PreesedKey = Local_u8KPDArr[Local_u8CounterRow][Local_u8CounterColumn] ;

				while(Local_u8PinStatus == DIO_u8PIN_LOW)
				{
					DIO_u8ReadPinValue(KPD_u8PORT,LOcal_u8RowArr[Local_u8CounterRow] ,&Local_u8PinStatus );

				}

				return  Local_u8PreesedKey ;
			}

		}
		DIO_u8SetPinValue(KPD_u8PORT,LOcal_u8ColumnArr[Local_u8CounterColumn],DIO_u8PIN_HIGH); //DEACTIVATTE


	}
	return Local_u8PreesedKey;
}

void KPD_voidShiftRight(u8 arr,u8 CopyPos)
{
	CLCD_voidGoToXY(0,CopyPos);
	CLCD_voidSendData(' ');
	CopyPos++;
	CLCD_voidGoToXY(0,CopyPos);
	CLCD_voidWriteSpectialCharacter(arr,2,0,CopyPos);
	_delay_ms(150);

}

void KPD_voidShiftLeft(u8 arr,u8 CopyPos){

	CLCD_voidGoToXY(0,CopyPos);
	CLCD_voidSendData(' ');
	CopyPos--;
	CLCD_voidGoToXY(0,CopyPos);
	CLCD_voidWriteSpectialCharacter(arr,2,0,CopyPos);
	_delay_ms(150);
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
		CLCD_voidWriteNumber(value);
		break;
	}
	return value ;
}

void GAME_VoidLCD(u8 y ){
	u8 k;
	u8 arr[8] = {
			0b00000,  // Row 0 - Top
			0b00100,  // Row 1
			0b01110,  // Row 2
			0b11111,  // Row 3
			0b11111,  // Row 4
			0b01110,  // Row 5
			0b00100,  // Row 6
			0b00000   // Row 7 - Bottom
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

	CLCD_voidWriteSpectialCharacter(paddle,1,y,0);
	CLCD_voidWriteSpectialCharacter(paddle,2,y,15);
	CLCD_voidWriteSpectialCharacter(arr,3,y,1);
	do
	{
		k = KPD_u8GetPreessedKey();

	}while(k == 0xff);
	if (k=='+')
	{
		for(u8 i =1 ;i<=14 ;i++)
		{
			CLCD_voidWriteSpectialCharacter(arr,3,y,i);
			_delay_ms(500);
			CLCD_voidGoToXY(y,i);
			CLCD_voidSendData(' ');
			if(i==14)
			{
				CLCD_voidWriteSpectialCharacter(arr,3,y,i);
				u32 time=0;
				do
				{
					k = KPD_u8GetPreessedKey();
					time++;
					//_delay_ms(2);
				}while((k!='-')&&(time<2500));
				if( k !='-')
				{
					clear();
					CLCD_voidGoToXY(0,5);
					CLCD_voidSendString(" lose ");
					_delay_ms(1000);
					clear();
					return;
				}
				if (k=='-')
				{
					for(u8 i =14 ;i>0 ;i--)
					{
						CLCD_voidWriteSpectialCharacter(arr,3,y,i);
						_delay_ms(500);
						CLCD_voidGoToXY(y,i);
						CLCD_voidSendData(' ');
						if(i==1)
						{
							CLCD_voidWriteSpectialCharacter(arr,3,y,i);
							u32 time1=0;
							do
							{
								k = KPD_u8GetPreessedKey();
								time1++;
								//_delay_ms(2);
							}while((k!='+')&&(time1<2500));
							if (k !='+')
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
	u8 z; // mode 2 paddle
	u8 y;
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
	// Ball movement
	u8 arr[8] = {
			0b00000,  // Row 0 - Top
			0b00100,  // Row 1
			0b01110,  // Row 2
			0b11111,  // Row 3
			0b11111,  // Row 4
			0b01110,  // Row 5
			0b00100,  // Row 6
			0b00000   // Row 7 - Bottom
	};
	for(u8 i =1 ;i<=14 ;i++)
	{
		CLCD_voidWriteSpectialCharacter(arr,3,0,i);
		_delay_ms(500);
		CLCD_voidGoToXY(0,i);
		CLCD_voidSendData(' ');

		CLCD_voidWriteSpectialCharacter(arr,3,1,i);
		_delay_ms(500);
		CLCD_voidGoToXY(1,i);
		CLCD_voidSendData(' ');
	}
}

void GAME_Merge_Ball_Paddle(void){
	u8 key, paddle_row = 0, ball_row = 0;  // paddle_row: Ù…ÙˆÙ‚Ø¹ Ø§Ù„Ù…Ø¶Ø±Ø¨ØŒ ball_row: ÙŠØªØ¨Ø¯Ù„ Ø¨ÙŠÙ† 0 Ùˆ 1
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

	for(u8 i = 1; i <= 14; i++) {
		u16 steps = 30; // 30 Ã— 10ms = 300ms delay Ø¨ÙŠÙ† ÙƒÙ„ Ø­Ø±ÙƒØ© Ù„Ù„ÙƒØ±Ø©

		while(steps--) {
			// ØªØ­Ø¯ÙŠØ« Ø§Ù„Ù…Ø¶Ø±Ø¨ Ø¨Ø³Ø±Ø¹Ø© Ù…Ù† Ø§Ù„ÙƒÙŠØ¨Ø§Ø¯
			key = KPD_u8GetPreessedKey();
			if(key == 8){
				paddle_row = 0;
			} else if(key == 5){
				paddle_row = 1;
			}

			// Ù…Ø³Ø­ Ø§Ù„Ø´Ø§Ø´Ø©
			clear();

			// Ø±Ø³Ù… Ø§Ù„Ù…Ø¶Ø±Ø¨ Ù�ÙŠ paddle_row
			CLCD_voidWriteSpectialCharacter(paddle, 1, paddle_row, 0);
			CLCD_voidWriteSpectialCharacter(paddle, 2, paddle_row, 15);

			// Ø±Ø³Ù… Ø§Ù„ÙƒØ±Ø© Ù�ÙŠ ball_row
			CLCD_voidWriteSpectialCharacter(arr, 3, ball_row, i);

			_delay_ms(10);
		}

		// Ù…Ø³Ø­ Ø§Ù„ÙƒØ±Ø© Ø§Ù„Ù‚Ø¯ÙŠÙ…Ø©
		CLCD_voidGoToXY(ball_row, i);
		CLCD_voidSendData(' ');

		// ØªØ¨Ø¯ÙŠÙ„ ØµÙ� Ø§Ù„ÙƒØ±Ø© (0 -> 1 Ø£Ùˆ 1 -> 0)
		ball_row = !ball_row;

		u32 time=0;
		if (i==14){
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
	u8 key, paddle_row = 0, ball_row = 0;
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

	for(s8 i = 14; i >= 1; i--) {  // Ø­Ø±ÙƒØ© Ø¹ÙƒØ³ÙŠØ© Ù…Ù† 14 Ù„Ù€ 1
		u16 steps = 30;

		while(steps--) {
			// Ù‚Ø±Ø§Ø¡Ø© Ø§Ù„ÙƒÙŠØ¨Ø§Ø¯ Ù„ØªØ­Ø±ÙŠÙƒ Ø§Ù„Ù…Ø¶Ø±Ø¨
			key = KPD_u8GetPreessedKey();
			if(key == 8){
				paddle_row = 0;
			} else if(key == 5){
				paddle_row = 1;
			}

			// Ù…Ø³Ø­ Ø§Ù„Ø´Ø§Ø´Ø©
			clear();

			// Ø±Ø³Ù… Ø§Ù„Ù…Ø¶Ø±Ø¨
			CLCD_voidWriteSpectialCharacter(paddle, 1, paddle_row, 0);
			CLCD_voidWriteSpectialCharacter(paddle, 2, paddle_row, 15);
			// Ø±Ø³Ù… Ø§Ù„ÙƒØ±Ø©
			CLCD_voidWriteSpectialCharacter(arr, 3, ball_row, i);

			_delay_ms(10);
		}

		// Ù…Ø³Ø­ Ø§Ù„ÙƒØ±Ø© Ø§Ù„Ù‚Ø¯ÙŠÙ…Ø©
		CLCD_voidGoToXY(ball_row, i);
		CLCD_voidSendData(' ');

		// ØªØ¨Ø¯ÙŠÙ„ Ø§Ù„ØµÙ�
		ball_row = !ball_row;

		// Ù�Ø­Øµ Ø§Ù„Ø®Ø³Ø§Ø±Ø© Ø¹Ù†Ø¯ Ø£ÙˆÙ„ Ø§Ù„Ø¹Ù…ÙˆØ¯ (0 Ø£Ùˆ 1 Ø­Ø³Ø¨ Ø§Ù„Ø§ØªØ¬Ø§Ù‡)
		if (i == 1) {
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

