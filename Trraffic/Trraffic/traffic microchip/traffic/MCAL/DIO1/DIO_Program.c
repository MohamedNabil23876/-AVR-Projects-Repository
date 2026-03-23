/*
 * DIO_Program.c
 *
 * Created: 09/09/2022 02:13:26 ص
 *  Author: nabil
 */ 
#include "DIO_Interface.h"


/******************************************************************************
 * Function Name:  MDIO_u8SetPinDirection 
 *
 * Description:	the function Set the required pin Direction
 *
 * Parameters: 1- Copy_u8PortName 2- Copy_u8Pin 3- Copy_u8PinDirection
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8 MDIO_u8SetPinDirection(u8 Copy_u8PortName, u8 Copy_u8Pin , u8 Copy_u8PinDirection )
{
	// local error to return if user select wrong configuration
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	// check if pin and port are true
	if(( Copy_u8PortName <= MDIO_u8_PORTD)  && (Copy_u8Pin <= MDIO_u8_PIN7))
	{
		// check direction state 
		
		// if pin output
		if( Copy_u8PinDirection == MDIO_u8_PIN_OUTPUT)
		{
			// select port 
			switch( Copy_u8PortName)
			{
				case MDIO_u8_PORTA : SET_BIT(DDRA_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTB : SET_BIT(DDRB_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTC : SET_BIT(DDRC_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTD : SET_BIT(DDRD_REG,Copy_u8Pin); break;
			}

		}// if pin input
		else if ( Copy_u8PinDirection == MDIO_u8_PIN_INPUT)
		{
			// select port 
			switch( Copy_u8PortName)
			{
				case MDIO_u8_PORTA : CLR_BIT(DDRA_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTB : CLR_BIT(DDRB_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTC : CLR_BIT(DDRC_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTD : CLR_BIT(DDRD_REG,Copy_u8Pin); break;
			}
		}
		else  
		{
			// wrong Direction 
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		// wrong pin|port
		 Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
/**********************************************************************************************/

/******************************************************************************
 * Function Name:  MDIO_u8SetPinValue 
 *
 * Description:	the function Set the required pin Value 
 *
 * Parameters: 1- Copy_u8PortName 2- Copy_u8Pin 3- Copy_u8PinValue
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8 MDIO_u8SetPinValue(u8 Copy_u8PortName, u8 Copy_u8Pin , u8  Copy_u8PinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(( Copy_u8PortName <= MDIO_u8_PORTD)  && (Copy_u8Pin <= MDIO_u8_PIN7))
	{
		if( Copy_u8PinValue == MDIO_u8_PIN_HIGH)
		{
			switch( Copy_u8PortName)
			{
				case MDIO_u8_PORTA : SET_BIT(PORTA_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTB : SET_BIT(PORTB_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTC : SET_BIT(PORTC_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTD : SET_BIT(PORTD_REG,Copy_u8Pin); break;
			}
		}
		else if (  Copy_u8PinValue == MDIO_u8_PIN_LOW)
		{
			switch( Copy_u8PortName)
			{
				case MDIO_u8_PORTA : CLR_BIT(PORTA_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTB : CLR_BIT(PORTB_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTC : CLR_BIT(PORTC_REG,Copy_u8Pin); break;
				case MDIO_u8_PORTD : CLR_BIT(PORTD_REG,Copy_u8Pin); break;
			}
		}
		else 
		{
			 Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else 
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
/**********************************************************************************************/

/******************************************************************************
 * Function Name:  MDIO_u8SetPortDirection 
 *
 * Description:	the function Set the required port Direction
 *
 * Parameters: 1- Copy_u8PortName 2- Copy_u8PortDirection
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8 MDIO_u8SetPortDirection(u8 Copy_u8PortName,  u8 Copy_u8PortDirection )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_u8PortName<=MDIO_u8_PORTD)                                                    
	{
		switch(Copy_u8PortName)
		{
			case MDIO_u8_PORTA: DDRA_REG= Copy_u8PortDirection; break;
			case MDIO_u8_PORTB: DDRB_REG= Copy_u8PortDirection; break;
			case MDIO_u8_PORTC: DDRC_REG= Copy_u8PortDirection; break;
			case MDIO_u8_PORTD: DDRD_REG= Copy_u8PortDirection; break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
/**********************************************************************************************/


/******************************************************************************
 * Function Name:  MDIO_u8SetPortValue 
 *
 * Description:	the function Set the required pin Value 
 *
 * Parameters: 1- Copy_u8PortName 2- Copy_u8PortValue
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/

u8 MDIO_u8SetPortValue(u8 Copy_u8PortName,  u8  Copy_u8PortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_u8PortName<=MDIO_u8_PORTD)                                                   
	{
		switch(Copy_u8PortName)
		{
			case MDIO_u8_PORTA: PORTA_REG= Copy_u8PortValue; break;
			case MDIO_u8_PORTB: PORTB_REG= Copy_u8PortValue; break;
			case MDIO_u8_PORTC: PORTC_REG= Copy_u8PortValue; break;
			case MDIO_u8_PORTD: PORTD_REG= Copy_u8PortValue; break;
		}
	}
	else
	{
            Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
/**********************************************************************************************/

/******************************************************************************
 * Function Name:  MDIO_u8GetPinValue 
 *
 * Description:	the function GET the required pin value
 *
 * Parameters: 1- Copy_u8PortName 2- Copy_u8Pin 3- MDIO_u8GetPinValue->pointer to u8
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8  MDIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8Pin, u8 * Copy_pu8ReturnedValue )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(( Copy_u8PortName <= MDIO_u8_PORTD)  && (Copy_u8Pin <= MDIO_u8_PIN7))
	{

		switch( Copy_u8PortName)
		{
			case MDIO_u8_PORTA :
			{
				*Copy_pu8ReturnedValue = ((PINA_REG & (1<<Copy_u8Pin))>>Copy_u8Pin);
			}
			break;
			case MDIO_u8_PORTB :
			{
				*Copy_pu8ReturnedValue = ((PINB_REG & (1<<Copy_u8Pin))>>Copy_u8Pin);
			}
			break;
			case MDIO_u8_PORTC :
			{
				*Copy_pu8ReturnedValue = ((PINC_REG & (1<<Copy_u8Pin))>>Copy_u8Pin);
			}
			break;
			case MDIO_u8_PORTD :
			{
				*Copy_pu8ReturnedValue = ((PIND_REG & (1<<Copy_u8Pin))>>Copy_u8Pin);
			}
			break;
		}
	}
	else
	{
		 Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
/**********************************************************************************************/


/******************************************************************************
 * Function Name:  MDIO_u8TogglePinValue 
 *
 * Description:	the function toggle the required pin 
 *
 * Parameters: 1- Copy_u8PortName 2- Copy_u8Pin 
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/

u8 MDIO_u8TogglePinValue(u8 Copy_u8PortName, u8 Copy_u8Pin )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8PortName <=MDIO_u8_PORTD)&&( Copy_u8Pin <=MDIO_u8_PIN7))
	{
		switch (Copy_u8PortName)
		{
			case MDIO_u8_PORTA :TOGGLE_BIT(PORTA_REG,Copy_u8Pin); break;
			case MDIO_u8_PORTB :TOGGLE_BIT(DDRB_REG,Copy_u8Pin); break;
			case MDIO_u8_PORTC :TOGGLE_BIT(PORTC_REG,Copy_u8Pin); break;
			case MDIO_u8_PORTD :TOGGLE_BIT(PORTD_REG,Copy_u8Pin); break;
		}
	}
	else 
	{
		Local_u8ErrorState = STD_TYPES_NOK;
		
	}
	
	return Local_u8ErrorState;

}
/**********************************************************************************************/