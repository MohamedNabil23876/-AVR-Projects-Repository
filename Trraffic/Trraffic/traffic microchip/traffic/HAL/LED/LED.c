/*
 * LED.c
 *
 * Created: 09/09/2022 06:36:00 م
 *  Author: nabil
 */ 

#include "LED.h"

/******************************************************************************
 * Function Name:  HLED_u8inti 
 *
 * Description:	the function identification  required led
 *
 * Parameters: 1- Ps_Inti : pointer to struct include required pin & port
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8 HLED_u8inti(GPIO_PIN_CONFG *Ps_Inti)
{
	// local error to return if user select wrong configuration
	u8 Local_u8ErrorState = STD_TYPES_OK;
	// check if pin and port are true
	// -> = *Ps_INTi.GPIO_u8Port_Num
     if(((Ps_Inti->GPIO_u8Port_Num)<=MDIO_u8_PORTD)&& ((Ps_Inti->GPIO_u8pin_Num)<=MDIO_u8_PIN7))
	{
		//identification  required led
		MDIO_u8SetPinDirection(Ps_Inti->GPIO_u8Port_Num,Ps_Inti->GPIO_u8pin_Num,MDIO_u8_PIN_OUTPUT);
	}
	else
	{
		// wrong LED
		Local_u8ErrorState= STD_TYPES_NOK;
		
	}
	
	
	return Local_u8ErrorState;
}
/* ******************************************************************************/

/******************************************************************************
 * Function Name:  HLED_u8On 
 *
 * Description:	the function on the   required led
 *
 * Parameters: 1- Ps_Inti : pointer to struct include required pin & port
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8 HLED_u8On(GPIO_PIN_CONFG *Ps_Inti)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(((Ps_Inti->GPIO_u8Port_Num)<=MDIO_u8_PORTD)&& ((Ps_Inti->GPIO_u8pin_Num)<=MDIO_u8_PIN7))
	{
		//LED on 
		MDIO_u8SetPinValue(Ps_Inti->GPIO_u8Port_Num,Ps_Inti->GPIO_u8pin_Num,MDIO_u8_PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState= STD_TYPES_NOK;
		
	}
	
	
	return Local_u8ErrorState;
}
/******************************************************************************/

/******************************************************************************
 * Function Name:  HLED_u8Off 
 *
 * Description:	the function off the   required led
 *
 * Parameters: 1- Ps_Inti : pointer to struct include required pin & port
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8 HLED_u8Off(GPIO_PIN_CONFG *Ps_Inti)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(((Ps_Inti->GPIO_u8Port_Num)<=MDIO_u8_PORTD)&& ((Ps_Inti->GPIO_u8pin_Num)<=MDIO_u8_PIN7))
	{
		// LED off
		MDIO_u8SetPinValue(Ps_Inti->GPIO_u8Port_Num,Ps_Inti->GPIO_u8pin_Num,MDIO_u8_PIN_LOW);
	}
	else
	{
		Local_u8ErrorState= STD_TYPES_NOK;
		
	}
	
	
	return Local_u8ErrorState;
	
}
/******************************************************************************/

/******************************************************************************
 * Function Name:  HLED_u8Toggle 
 *
 * Description:	the function u8 HLED_u8Toggle(GPIO_PIN_CONFG *Ps_Inti);
 the   required led
 *
 * Parameters: 1- Ps_Inti : pointer to struct include required pin & port
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8 HLED_u8Toggle(GPIO_PIN_CONFG *Ps_Inti)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(((Ps_Inti->GPIO_u8Port_Num)<=MDIO_u8_PORTD)&& ((Ps_Inti->GPIO_u8pin_Num)<=MDIO_u8_PIN7))
	{
		// toggle LED
		MDIO_u8TogglePinValue(Ps_Inti->GPIO_u8Port_Num,Ps_Inti->GPIO_u8pin_Num);
	}
	else
	{
		Local_u8ErrorState= STD_TYPES_NOK;
		
	}
	
	
	return Local_u8ErrorState;
}
/******************************************************************************/