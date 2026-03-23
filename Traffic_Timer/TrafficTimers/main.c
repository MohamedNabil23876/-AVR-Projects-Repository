/*
 * main.c
 *
 *  Created on: Jul 28, 2025
 *      Author: lenovo
 */


/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: HP
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "DIO/DIO_interface.h"
#include "GIE/GIE_Interface.h"
#include "TMR_interface.h"
#include "EXTI/EXTI_interface.h"


void LED_GREEN(void);
void LED_YELLOW(void);
void LED_RED(void);
//void LED_OFF(void);
void TRAFFIC_Handler(void);


void main()
{

	/* PA0 --> output */
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_OUTPUT);

	// Switches
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_INPUT);

	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);



	TIMER0_voidInit();
	TRAFFIC_u8IntSetCallBack(&LED_YELLOW);
	TRAFFIC_u8IntSetCallBack(&LED_RED);
	TIMER0_voidSetPreload(192);
	TIMER0_voidSetCompare(250);
	TRAFFIC_u8IntSetCallBack(&TRAFFIC_Handler);


	GIE_voidEnable();
	EXTI_u8IntEnable(EXTI_u8INT0);
	EXTI_u8IntEnable(EXTI_u8INT1);
	EXTI_u8IntEnable(EXTI_u8INT2);



	EXTI_voidInt0Init();
	EXTI_voidInt1Init();
	EXTI_voidInt2Init();
	u8 Local_INT0SW,Local_INT1SW,Local_INT2SW;

	while(1)
	{
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_INT0SW);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_INT1SW);
		DIO_u8ReadPinValue(DIO_u8PORTB,DIO_u8PIN2,&Local_INT2SW);


		if(Local_INT0SW == 0)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);  // Green on
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_LOW);   // Yellow off
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_LOW);   // Red off
		}
		else if(Local_INT1SW == 0)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_LOW);
		}
		else if(Local_INT2SW == 0)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
		}
	}
}


void TRAFFIC_Handler(void)
{
	static 	long long Local_LLCounter = 0;
	static u8 Local_u8State = 0;
	if(Local_LLCounter == 0 && Local_u8State == 0)
	{
		LED_GREEN();
	}

	Local_LLCounter++;

	if(Local_LLCounter == 120000)
	{
		Local_u8State = 1;
		LED_YELLOW();

	}
	else if (Local_LLCounter == 240000)
	{
		Local_u8State = 2;
		LED_RED();
	}
	else if (Local_LLCounter == 360000)
	{
		Local_u8State = 0;
		Local_LLCounter = 0;
		LED_GREEN();

	}

}

void LED_GREEN(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);  // Green on
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_LOW);   // Yellow off
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_LOW);   // Red off
}

void LED_YELLOW(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_LOW);
}

void LED_RED(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
}
//void LED_OFF(void)
//{
//	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_LOW);
//
//}
