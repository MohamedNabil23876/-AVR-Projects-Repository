/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: HP
 */
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"

void main(void) {
	DIO_u8SetPortDirection(DIO_u8PORTA, DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTB, DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTC, DIO_u8PORT_INPUT);
	DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_HIGH);

	CLCD_voidInit();



	while (1) {
		STOP_WATCH();
	}

}

