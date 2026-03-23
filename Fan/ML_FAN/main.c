/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: HP
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <util/delay.h>

#include"DIO_Interface.h"
#include"ADC_interface.h"
#include"CLCD_interface.h"


void main(void){

	u8 Local_u8Reading ;
	u16 Millivolt ;
	u32 temp ;
	/* LEDS --> OUTPUT (PORTC) */
	DIO_u8SetPortDirection(DIO_u8PORTC,DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTD,DIO_u8PORT_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_OUTPUT);

	/*ADC0 --> PINA0 (INPUT) */
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_INPUT);

	ADC_voidInit();
	CLCD_voidInit();


	while(1)
	{
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("temp=");
		Local_u8Reading = ADC_u8GetChannelRead(ADC0);
		Millivolt = ((u32)Local_u8Reading * 5000UL)/(256UL);
		temp = Millivolt / 10 ;
		CLCD_voidGoToXY(0,7);
		CLCD_voidWriteNumber(temp);
		CLCD_voidSendData('C');
		_delay_ms(300);
		CLCD_voidSendCommend(1);
		if (temp >= 37 ){
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
		else if (temp < 37){
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
		}

	}
}
