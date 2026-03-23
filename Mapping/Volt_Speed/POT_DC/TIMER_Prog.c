/*
 * TIMER_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_ERR.h"
#include "DIO_Interface.h"

#include <util/delay.h>
#include "TIMER_interface.h"
#include "TIMER_Cfg.h"
#include "TIMER_Prv.h"
#include "TIMER_Reg.h"
#include "ADC_interface.h"

void (*TIMER0_pvCallBack)(void)	;

void (*Traffic_pvCallBack[])(void) = {NULL};

void TIMER0_voidInit(void)
{

	/* Waveform Generation Mode --> PWM FAST*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/* Waveform Generation Mode -->NORMAL*/
	CLEAR_BIT(TCCR0,TCCR0_WGM00);
	CLEAR_BIT(TCCR0,TCCR0_WGM01);


	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	/* prescaler --> div_by 64*/
	TCCR0 &= TCCR0_MASK;
	TCCR0 |= TIMER0_PRESC ;

	/*ENABLE INTERRUPT*/
	//SET_BIT(TIMSK,TIMSK_OCIE0);

}


void TIMER1_voidInit(void)
{
	/*  non inverting  */
	CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

	/* FAST PWM -->*/
	CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/* prescaler --> divid by 8 */
	CLEAR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLEAR_BIT(TCCR1B,TCCR1B_CS12);

}


void TIMER0_voidSetPreload(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value ;
}

void TIMER1_voidSetICR(u16 Copy_u16Top)
{
	ICR1 = Copy_u16Top ;
}

void TIMER1_voidSetCompMatch(u16 Copy_u16Value)
{
	OCR1A = Copy_u16Value ;
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

void TIMER0_voidSetCompare(u16 Copy_u8Value){
	OCR0 = Copy_u8Value;
}

void TIMER1_voidsetAngle(u16 angle){

	OCR1A = ((angle * 1750UL) / 180UL) + 750UL;

}


void __vector_10 (void)	__attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBack != NULL)
	{
		TIMER0_pvCallBack();
	}

}

void __vector_11 (void)	__attribute__((signal));
void __vector_11 (void)
{
	if(TIMER0_pvCallBack != NULL)
	{
		TIMER0_pvCallBack();
	}

}


u8 TRAFFIC_u8IntSetCallBack(void(*Copy_pvIntFunc[])(void))
{
	u8 Local_u8ErrorState = OK;

	if (Copy_pvIntFunc != NULL)
	{
		for (u8 i = 0; i < 3; i++)
		{
			Traffic_pvCallBack[i] = Copy_pvIntFunc[i];
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

