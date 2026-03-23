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

void System(void);

u8 melody[] =
{
		95, 95, 0, 95, 0, 75, 95, 0, 0, 60, 0, 50, 0, 65,
		0, 0, 75, 0, 0, 60, 0, 50, 0, 65
};

u16 duration[] =
{
		150, 150, 100, 150, 100, 150, 150, 100, 100, 150, 100, 150, 100, 150,
		200, 100, 150, 100, 100, 150, 100, 150, 100, 200
};

u8 key ;
u8 pass;
u8 Local_u8ReadingLDR;


void System(void)
{
	key = SPI_SlaveReceive();

	if ( key == 1 )
	{

		Local_u8ReadingLDR = ADC_u8GetChannelRead(ADC1);

		if((Local_u8ReadingLDR >= 0) && (Local_u8ReadingLDR <= 32))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);

		}
		else if((Local_u8ReadingLDR > 32) && (Local_u8ReadingLDR <= 64))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);

		}
		else if((Local_u8ReadingLDR > 64) && (Local_u8ReadingLDR <= 96))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);

		}
		else if((Local_u8ReadingLDR > 96) && (Local_u8ReadingLDR <= 128))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);

		}
		else if((Local_u8ReadingLDR > 128) && (Local_u8ReadingLDR <= 160))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_HIGH);

		}
		else if((Local_u8ReadingLDR > 160) && (Local_u8ReadingLDR <= 192))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);

		}
		else if((Local_u8ReadingLDR > 192) && (Local_u8ReadingLDR <= 224))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_HIGH);
		}
		else if((Local_u8ReadingLDR > 224) && (Local_u8ReadingLDR <= 255))
		{
			DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_HIGH);

		}
	}
	else if (key == 2)
	{
		DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_LOW);
	}
	else if (key == 5)
	{

		u8 Local_u8Reading ;
		u16 millivolt;
		u16 temp;
		Local_u8Reading = ADC_u8GetChannelRead(ADC0);
		millivolt = ((u32)Local_u8Reading * 5000UL)/(256UL);
		temp = millivolt / 10 ;

		if (temp<25)
		{
			TIMER1_voidSetCompMatch(0);
		}else if (temp>40)
		{
			TIMER1_voidSetCompMatch(4000);
		}
		else if (temp > 25 && temp<30)
		{
			TIMER1_voidSetCompMatch(2000);
		}
		else if (temp > 30 && temp<35)
		{
			TIMER1_voidSetCompMatch(2500);
		}
		else if (temp > 35 && temp<40)
		{
			TIMER1_voidSetCompMatch(3000);
		}
	}
	else if (key == 6)
	{
		TIMER1_voidSetCompMatch(0);
	}
	else if (key==7)
	{
		TIMER0_voidInit();

		for (u8 i = 0; i < 24; i++)
		{
			if (melody[i] == 0)
			{
				TIMER0_voidSetCompMatch(0);
			}
			else
			{
				TIMER0_voidSetCompMatch(melody[i]);
			}
			_delay_ms(duration[i]);

		}
	}
	else if (key==8)
	{
		TIMER0_voidSetCompMatch(0);
		_delay_ms(1000);
	}
}


#endif /* MAIN_H_ */
