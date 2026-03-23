
#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "../ERR_TYPE.h"

#include "TIMER_interface.h"
#include "TIMER_reg.h"
#include "TIMER_prv.h"
#include "TIMER_cfg.h"

void (*TIMER0_pvCallBack)(void)	= NULL ;

void TIMER0_voidInit(void)
{
	/* Waveform Generation Mode --> fast pwm mode */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);



	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

	/* prescaler --> div_by 64 */
	TCCR0 &= TCCR0_MASK;
	TCCR0 |= TIMER_PRESC ;



	/*ENABLE INTERRUPT*/
//	SET_BIT(TIMSK,TIMSK_OCIE0);
}

void TIMER1_voidInit(void)
{
	/*  non inverting  */
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

	/* FAST PWM -->*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/* prescaler --> divid by 8 */
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);


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
//void TIMER1_voidSetCompMatch(u16 Copy_u16Value)
//{
//	OCR1B = Copy_u16Value ;
//}



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

}


//void __vector_11 (void)	__attribute__((signal));
//void __vector_11 (void)
//{
//	if(TIMER0_pvCallBack != NULL)
//	{
//		TIMER0_pvCallBack();
//	}
//
//}

void __vector_10 (void)	__attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBack != NULL)
	{
		TIMER0_pvCallBack();
	}
}
