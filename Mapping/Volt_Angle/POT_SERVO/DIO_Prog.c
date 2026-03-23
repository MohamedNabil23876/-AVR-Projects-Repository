#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_ERR.h"

#include "DIO_interface.h"
#include "DIO_prv.h"
#include "DIO_cfg.h"
#include "DIO_reg.h"



u8 DIO_u8SetPinDirection(u8 Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = OK ;
	if  ( Copy_u8Direction == DIO_u8PIN_INPUT)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : CLEAR_BIT(DDRA,Copy_u8Pin) ;break;
		case DIO_u8PORTB : CLEAR_BIT(DDRB,Copy_u8Pin) ;break;
		case DIO_u8PORTC : CLEAR_BIT(DDRC,Copy_u8Pin) ;break;
		case DIO_u8PORTD : CLEAR_BIT(DDRD,Copy_u8Pin) ;break;
		default : Local_u8ErrorState = NOK ;
		}
	}
	else if ( Copy_u8Direction == DIO_u8PIN_OUTPUT)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : SET_BIT(DDRA,Copy_u8Pin) ;break;
		case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8Pin) ;break;
		case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8Pin) ;break;
		case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8Pin) ;break;

		default : Local_u8ErrorState =NOK;
		}
	}
	else
	{
		Local_u8ErrorState =NOK;
	}


	return Local_u8ErrorState;
}
u8 DIO_u8SetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = OK ;

	if  ( Copy_u8Value == DIO_u8PIN_LOW)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : CLEAR_BIT(PORTA,Copy_u8Pin) ;break;
		case DIO_u8PORTB : CLEAR_BIT(PORTB,Copy_u8Pin) ;break;
		case DIO_u8PORTC : CLEAR_BIT(PORTC,Copy_u8Pin) ;break;
		case DIO_u8PORTD : CLEAR_BIT(PORTD,Copy_u8Pin) ;break;

		default : Local_u8ErrorState =NOK;break;


		}

	}
	else if (  Copy_u8Value == DIO_u8PIN_HIGH)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin) ;break;
		case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin) ;break;
		case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin) ;break;
		case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin) ;break;

		default : Local_u8ErrorState =NOK;break;
		}

	}
	else
	{
		Local_u8ErrorState =NOK;
	}


	return Local_u8ErrorState;
}


u8 DIO_u8SetPortDirection(u8 Copy_u8Port  , u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = OK ;

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA :	DDRA = Copy_u8Direction ; break ;
	case DIO_u8PORTB :	DDRB = Copy_u8Direction ; break ;
	case DIO_u8PORTC :  DDRC = Copy_u8Direction ; break ;
	case DIO_u8PORTD :  DDRD = Copy_u8Direction ; break ;
	default : Local_u8ErrorState = NOK ;
	}

	return Local_u8ErrorState ;
}


u8 DIO_u8SetPortValue(u8 Copy_u8Port  , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = OK ;

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA :	PORTA = Copy_u8Value ; break ;
	case DIO_u8PORTB :	PORTB = Copy_u8Value ; break ;
	case DIO_u8PORTC :  PORTC = Copy_u8Value ; break ;
	case DIO_u8PORTD :  PORTD = Copy_u8Value ; break ;
	default : Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState ;
}


u8 DIO_u8ReadPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin , u8 *Copy_Pu8Value)
{

	u8 Local_u8ErrorState = OK;

	if((Copy_Pu8Value != NULL) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA :	*Copy_Pu8Value = GET_BIT(PINA,Copy_u8Pin); break ;
		case DIO_u8PORTB :	*Copy_Pu8Value = GET_BIT(PINB,Copy_u8Pin); break ;
		case DIO_u8PORTC :	*Copy_Pu8Value = GET_BIT(PINC,Copy_u8Pin); break ;
		case DIO_u8PORTD :	*Copy_Pu8Value = GET_BIT(PIND,Copy_u8Pin); break ;
		default : Local_u8ErrorState = NOK;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}

u8 DIO_u8TogglePinvalue(u8 Copy_u8Port ,u8 Copy_u8Pin ){

	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Port)
	{
	case  DIO_u8PORTA : TOGGLE_BIT(PINA,Copy_u8Pin);break;
	case  DIO_u8PORTB : TOGGLE_BIT(PINB,Copy_u8Pin);break;
	case  DIO_u8PORTC : TOGGLE_BIT(PINC,Copy_u8Pin);break;
	case  DIO_u8PORTD : TOGGLE_BIT(PIND,Copy_u8Pin);break;
	default : Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState ;
}

