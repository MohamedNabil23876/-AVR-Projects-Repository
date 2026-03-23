/*
 * timer1.c
 *
 * Created: 10/09/2022 08:23:47 م
 *  Author: nabil
 */ 

#include "Timer1.h"
#include <avr/interrupt.h> /* For Timers ISR */

static volatile void (*gP_Timer0callBackPtr)(void) = NULL;
static volatile void (*gP_Timer1callBackPtr)(void) = NULL;
static volatile void (*gP_Timer2callBackPtr)(void) = NULL;

 u32 localcounter=0;


/******************************************************************************
 * Function Name:  Timer_inti 
 *
 * Description:	initialization required timer  
 *
 * Parameters: PsTimer pointer to struct include  required timer configuration
 *    
 * Return:non
 *
 ******************************************************************************/
u8  Timer_inti(TIMERS_ConfigType *PsTimer)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	// select timer 
	switch(PsTimer->timer_ID)
	{
		
		case TIMER0 : 
		// As we work in non-PWM Phase 
		SET_BIT (TCCR0,TCCR0_FOC0);
		// select mode only over flow and CTC
		
		/* Insert the required initial value in TCNT0 register */
		TCNT0 = PsTimer->timer_intial_value;
		if (PsTimer->timer_mode==CTC_Mode)
		{
			/*Set CTC Mode */
			CLR_BIT(TCCR0,TCCR0_WGM00);
			SET_BIT(TCCR0,TCCR0_WGM01);
			
		    /*set CTC Compare value */
		    OCR0=PsTimer->timer_compare_value;
			/*enable interrupt */
			SET_BIT(TIMSK,TIMSK_OCIE0);
			

			
		}
		else if (PsTimer->timer_mode==OVF_Mode)
		{
			// set O.V Mode
			CLR_BIT(TCCR0,TCCR0_WGM00);
			CLR_BIT(TCCR0,TCCR0_WGM01);
			
			
			/* Enable overflow Mode flag */
			SET_BIT(TIMSK,TIMSK_TOIE0);
		}
		else
		{
			Local_u8ErrorState=STD_TYPES_NOK;
		}
		/*SET *PreScelar  */
		
		TCCR0= (TCCR0 & CLOCK_MASK)|(PsTimer->timer_clock);break;
		
		/*--------------------------- TIMRE1 ---------------------------*/
		case TIMER1 :
		
		// As we work in non-PWM Phase
		SET_BIT (TCCR1A,TCCR1A_FOC1A);
		SET_BIT (TCCR1A,TCCR1A_FOC1B);
		// select mode only over flow and CTC
		
		/* Insert the required initial value in TCNT0 register */
		TCNT1 = PsTimer->timer_intial_value;
		if (PsTimer->timer_mode==OVF_Mode)
		{
			// set O.V Mode
			// by default O.v Mode
			/* Enable overflow Mode flag */
			SET_BIT(TIMSK,TIMSK_TOIE1);
			
		}
		else if (PsTimer->timer_mode==CTC_Mode)
		{
			/*Set CTC Mode */
			
			TCCR1B = (TCCR1B & CTC_MODE_MASK) | ((PsTimer->timer_mode)<<TCCR1B_WGM12);
			
		
			/*CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12)
			CLR_BIT(TCCR1B,TCCR1B_WGM13);*/
			
			 /*set CTC Compare value */
			OCR1A=PsTimer->timer_compare_value;
			/*enable interrupt */
			SET_BIT(TIMSK,TIMSK_OCIE1A);
			
		}
		else
		{
			Local_u8ErrorState=STD_TYPES_NOK;
		}
		/*SET *PreScelar  */
		
		/*SET PreScelar*/
		TCCR1B=(TCCR1B&CLOCK_MASK)|PsTimer->timer_clock;
		/*
		CLR_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);*/
		
		break;
		
		
		
		
		
	}
	
	return Local_u8ErrorState;
	
}
/*********************************************************************************/

/******************************************************************************
 * Function Name:  Timer_setCallBack 
 *
 * Description:	 Save the address of the Call back function in a global variable   
 *
 * Parameters: 1- *a_ptr : pointer to func point to function Work in ISR
 *				2- EN_number enum include timers ID
 * Return:non
 *
 ******************************************************************************/
u8 Timer_setCallBack(void(*a_ptr)(void), TIMER_NUM EN_number)
{
	
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	switch(EN_number)
	{
		
		case TIMER0:
		// check  if the a_ptr not = Null  true include address of FUNC fouls = NULL 
		if (a_ptr != NULL )
		{
			/* Save the address of the Call back function in a global variable */
		gP_Timer0callBackPtr = a_ptr;
		}
		else
		{
			Local_u8ErrorState=NULL_POINTER;	
		}
		
		break;

		
		case TIMER1:
		// check  if the a_ptr not = Null  true include address of FUNC fouls = NULL
		if (a_ptr != NULL )
		{
			/* Save the address of the Call back function in a global variable */
			gP_Timer1callBackPtr = a_ptr;
		}
		else
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		
		break;

		
		case TIMER2:
		// check  if the a_ptr not = Null  true include address of FUNC fouls = NULL
		if (a_ptr != NULL )
		{
			/* Save the address of the Call back function in a global variable */
			gP_Timer2callBackPtr = a_ptr;
		}
		else
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		
		break;
		
		} 
		return Local_u8ErrorState;
	}

/*****************************************************************************************/

ISR(TIMER0_OVF_vect)
{
	if(gP_Timer0callBackPtr != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*gP_Timer0callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*
 * Description :
 * Calls the call back function of timer 0 in case of TIMER_CTC_Mode MATCH interrupt occurs
 */
ISR(TIMER0_COMP_vect)
{
	if(gP_Timer0callBackPtr != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*gP_Timer0callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*
 * Description :
 * Calls the call back function of timer 1 in case of OVERFLOW interrupt occurs
 */
ISR(TIMER1_OVF_vect)
{
	if(gP_Timer1callBackPtr != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*gP_Timer1callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*
 * Description :
 * Calls the call back function of timer 1 in case of TIMER_CTC_Mode MATCH interrupt occurs
 */
ISR(TIMER1_COMPA_vect)
{
	 
	localcounter++;
	if(localcounter==FIVE_SEC)
	{
		
	
	if(gP_Timer1callBackPtr != NULL)
	
	{
		
		/* Call the Call Back function in the application after the edge is detected */
		(*gP_Timer1callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
		TCNT1=0; 
		localcounter=0;
		
	}
	
	}
	else 
	{
		
		
	}
}

/*******************************************************************************************************/

