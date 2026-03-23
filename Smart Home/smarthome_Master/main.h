/*
 * main.h
 *
 *  Created on: Aug 2, 2025
 *      Author: lenovo
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO/DIO_interface.h"
#include "CLCD/CLCD_interface.h"
#include "KPD/KPD_interface.h"
#include "TIMER/TIMER_interface.h"
#include "ADC/ADC_interface.h"
#include "SPI/SPI_interface.h"

int LogIn(void);
void Welcome (void);
void StartMenue (void);
void ScanKPD(void);


u8 pass_count = 0 ;
u32 ID ;
u32 pass ;
u8 Pressedkey ;

void Welcome (void)
{
	CLCD_voidInit();
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("WELCOME TO MY ");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("SMART HOME");
	_delay_ms(1000);
	CLCD_VoidClear();
}

int LogIn(void)
{
	//ID
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("ENTER ID :  ");
	CLCD_voidGoToXY(1,0);

	ID = EnterNum();
	pass= reverseNumber(ID);
	_delay_ms(100);
	CLCD_VoidClear();

	while (pass_count<3)
	{
		pass_count++;

		//PASSWARED
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("ENTER PASSWORD :  ");
		CLCD_voidGoToXY(1,0);
		u32 USER_PASSWORD ;
		USER_PASSWORD  = EnterNum_pass();
		_delay_ms(300);

		if ( USER_PASSWORD != pass )
		{
			CLCD_VoidClear();
			if (pass_count==3)
			{
				return -1 ;
			}
			else
			{
				CLCD_voidSendString("TRY AGAIN");
				_delay_ms(500);
				CLCD_VoidClear();
			}
		}
		else
		{
			CLCD_VoidClear();
			break;
		}
	}
}

void StartMenue (void)
{
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("1_2_LED");
	CLCD_voidGoToXY(0,8);
	CLCD_voidSendString("3_4_DOOR");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("5_6_FAN ");
	CLCD_voidGoToXY(1,8);
	CLCD_voidSendString("7_8_MUSC ");

}

void ScanKPD(void)
{
	do
	{
		Pressedkey = KPD_u8GetPreessedKey();
	}while (Pressedkey == 0xff);

	//door
	if (Pressedkey == 3)
	{
		TIMER1_voidSetCompMatch(2500);
	}
	else if (Pressedkey == 4)
	{
		TIMER1_voidSetCompMatch(750);
	}
	else
	{
		SPI_MasterTransmit(Pressedkey);
	}
}

#endif /* MAIN_H_ */
