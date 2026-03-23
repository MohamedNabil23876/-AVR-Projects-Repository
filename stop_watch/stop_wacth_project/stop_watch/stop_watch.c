/******************************************************************************
 *
 * Module: stop_watch
 *
 * File Name: stop_watch.c
 *
 * Description: stop_watch.c for stop watch Driver
 *
 * Author: Mohamed nabil
 *
 *******************************************************************************/
#include "comman_macros.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

extern unsigned char  seconds_ones;
extern unsigned char   seconds_tens ;
extern unsigned char   minutes_ones ;
extern unsigned char   minutes_tens;
extern unsigned char   hours_ones;
extern  unsigned char hours_tens;

/*unsigned char seconds_ones =  0,  seconds_tens =  0;
unsigned char minutes_ones =  0,  minutes_tens =  0;
unsigned char hours_ones   =  0,  hours_tens   =  0; */

ISR (TIMER1_COMPA_vect) {
	seconds_ones++;
	if (seconds_ones > 9 )  {seconds_tens++ ; seconds_ones = 0;  }
	if (seconds_tens > 5 )  {minutes_ones++ ; seconds_tens = 0;  }
	if (minutes_ones > 9 )  {minutes_tens++ ; minutes_ones = 0;  }
	if (minutes_tens > 5 )  {hours_ones++   ; minutes_tens = 0;  }
	if (hours_ones   > 9 )  {hours_tens++   ; hours_ones =   0;  }
	if (hours_tens == 9 && hours_ones == 9){hours_ones = 0; hours_tens = 0;}
}

ISR(INT0_vect) {          /*reset stop watch by adding all the variables = 0 */
	seconds_ones =  0,  seconds_tens =  0;
	minutes_ones =  0,  minutes_tens =  0;
	hours_ones   =  0,  hours_tens   =  0;
}

ISR(INT1_vect) {                             /*NO CLOCK SOURCE - Stop */
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
}

ISR(INT2_vect) {                           /*Active CLOCK SOURCE  ( /1024) */
	SET_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS10);
}

/*Function to installation Timer1 CTC Mode */
void STOP_WATCH_Timer1CtcInti(void)
{
	TCNT1 = 0;		          /*Set timer1 initial count to zero*/
	OCR1A = 1000;             /*Set the Compare value to 1000 (one SEC)*/
	SET_BIT(TIMSK,OCIE1A);
	// Enable Timer1 Compare A Interrupt

	/* Configure timer control register TCCR1A
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM10=0  WGM11=0  WGM12=1 WGM13=0 (Mode Number 4)
	 * 3. Pre-scaler = F_CPU/1024 CS10=1 CS11=0 CS12=1
	 */
	SET_BIT(TCCR1A,FOC1A);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS12);


}
/*Function to installation INT0 INT1 INT2 */
void STOP_WATCH_InterruptInti(void)
{
	cli();                    /*SERG&=~(1<<7); disable I-bit.*/
	/*Falling edge (INT0) - Rising edge (INT1)*/
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC01);

	SET_BIT(MCUCSR,ISC2);/*Falling edge (INT2)*/

	/*activate PB2 as a interrupt pin INT2- activate PB2 as a interrupt pin INT2.*/
	SET_BIT(GICR,INT0);
	SET_BIT(GICR,INT1);
	SET_BIT(GICR,INT2);

	sei();             // SERG|=(1<<7); enable I-bit.
}
