/*
 * TMR_prog.c
 *
 *  Created on: Jul 27, 2025
 *      Author: lenovo
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/ERR_TYPE.h"

#include "TMR_interface.h"
#include "TMR_cfg.h"
#include "TMR_prv.h"
#include "TMR_reg.h"

void (*TIMER0_pvCallBack)(void)	;

//void (*Traffic_pvCallBack[3])(void);
void (*Traffic_pvCallBack)(void) = NULL;


void TIMER0_voidInit(void)
{

	/* Waveform Generation Mode --> CTC*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/* Waveform Generation Mode -->NORMAL
	CLEAR_BIT(TCCR0,TCCR0_WGM00);
	CLEAR_BIT(TCCR0,TCCR0_WGM01);*/

	/* prescaler --> div_by 64*/
	TCCR0 &= TCCR0_MASK;
	TCCR0 |= TIMER0_PRESC ;

	/*ENABLE INTERRUPT*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

}

void TIMER0_voidSetPreload(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value ;
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


u8 TRAFFIC_u8IntSetCallBack(void(*Copy_pvIntFunc)(void))
{
	u8 Local_u8ErrorState = OK ;

	if(Copy_pvIntFunc != NULL)
	{
		 Traffic_pvCallBack = Copy_pvIntFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;

}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if (Traffic_pvCallBack != NULL)
    {
        Traffic_pvCallBack();
    }
}

