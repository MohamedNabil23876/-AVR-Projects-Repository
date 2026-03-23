/*
 * TMR_prog.c
 *
 *  Created on: Jul 27, 2025
 *      Author: lenovo
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/ERR_TYPE.h"

#include "TMR_interface.h"
#include "TMR_cfg.h"
#include "TMR_prv.h"
#include "TMR_reg.h"

void (*TIMER0_pvCallBack)(void)	;

void TIMER0_voidInit(void)
{
	/* Waveform Generation Mode --> fast pwm mode */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	//OCR0 = 64 ;

	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	/* prescaler --> div_by 64 */
	TCCR0 &= TCCR0_MASK;
	TCCR0 |= TIMER_PRESC ;



	/*ENABLE INTERRUPT*/
	//	SET_BIT(TIMSK,TIMSK_OCIE0);
}

void TIMER1_voidInit(void)
{

	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

}

u16 TIMER1_voidGetReading(void)
{
	return	TCNT1 ;
}

u16 TIMER0_voidGetReading(void)
{
	return	TCNT0 ;
}

void TIMER0_voidSetPreload(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value ;
}


void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1  = Copy_u16Value ;
}


void TIMER1_voidSetICR(u16 Copy_u16Top)
{
	ICR1 = Copy_u16Top ;
}


void TIMER1_voidSetCompMatch(u16 Copy_u16Value)
{
	OCR1A = Copy_u16Value ;
}

void TIMER0_voidSetCompMatch(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value ;
}
u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBack)(void))
{
	u8 Local_u8ErrorState = OK ;

	if(Copy_pvCallBack != NULL)
	{
		TIMER0_pvCallBack = Copy_pvCallBack ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}

void TIMER0_voidSetCompare(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}




