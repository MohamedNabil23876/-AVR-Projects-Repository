/*
 *************************************************************************
 Name      : Stop Watch  Mini Project
 Author    : Mohamed nabil
 Diploma   : 63
 *************************************************************************
 */
#include"stop_watch.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
unsigned char seconds_ones =  0,  seconds_tens =  0;
unsigned char minutes_ones =  0,  minutes_tens =  0;
unsigned char hours_ones   =  0,  hours_tens   =  0;
int main(void) {
	/*Configure PD2 as a input pin */
	CLR_BIT(DDRD,PD2);
	SET_BIT(PORTD,PD2);

	/*Configure PD3 as a input pin /Pause*/
	CLR_BIT(DDRD,PD3);
	/*Configure PB2 as a input pin /Resume*/
	CLR_BIT(DDRB,PB2);
	SET_BIT(PORTB,PB2);


	DDRC = 0X0F;    // Configure first 4 pin as a output (input for the decoder)

	DDRA = 0X3F;     // Configure first 6 pin as a output (control of 7-segment)
	PORTA = 0;         //Clear PORTA

	STOP_WATCH_Timer1CtcInti();    //Call Timer_CTC function
	STOP_WATCH_InterruptInti();


	while(1){

		PORTC = (PORTC & 0xF0) | (seconds_ones & 0x0F);
		PORTA = 0x01;
		_delay_ms(2);
		PORTA=0;

		PORTC = (PORTC & 0xF0) | (seconds_tens & 0x0F);
		PORTA = 0x02;
		_delay_ms(2);
		PORTA=0;

		PORTC = (PORTC & 0xF0) | (minutes_ones & 0x0F);
		PORTA |=0X04;
		_delay_ms(2);
		PORTA=0;

		PORTC = (PORTC & 0xF0) | (minutes_tens & 0x0F);
		PORTA = 0x08;
		/*Active CLOCK SOURCE  ( /1024) */		_delay_ms(2);
		PORTA=0;

		PORTC = (PORTC & 0xF0) | (hours_ones & 0x0F);
		PORTA = 0x10;
		_delay_ms(2);
		PORTA=0;

		PORTC = (PORTC & 0xF0) | (hours_tens & 0x0F);
		PORTA = 0x20;
		_delay_ms(2);
		PORTA=0;

	}
}
