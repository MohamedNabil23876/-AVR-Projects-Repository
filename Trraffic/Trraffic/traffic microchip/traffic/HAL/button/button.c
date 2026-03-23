/*
 * button.c
 *
 * Created: 09/09/2022 08:25:08 م
 *  Author: nabil
 */ 

#include "button.h"

/******************************************************************************
 * Function Name:  buton_u8inti 
 *
 * Description:	the function identification  required button 
 *
 * Parameters: 1- PS_button : pointer to struct include required pin & port
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8 HBUTTON_u8inti(GPIO_BUTTON_CONFG * PS_button)
{
	// local error to return if user select wrong configuration
	u8 Local_u8ErrorState = STD_TYPES_OK;
	// check if pin and port are true
	// -> = *PS_button.GPIO_u8Port_Num
	if(((PS_button->GPIO_u8Port_Num)<=MDIO_u8_PORTD)&& ((PS_button->GPIO_u8pin_Num)<=MDIO_u8_PIN7))
	{
		// check pin state 1- pull up 2- pull down
		switch (PS_button->GPIO_u8PIN_state)
		{
			
			case  NORMAL_STATE : // normal state DDR = 0 for i/p | port = 0 inti
			MDIO_u8SetPinDirection(PS_button->GPIO_u8Port_Num,PS_button->GPIO_u8pin_Num,MDIO_u8_PIN_INPUT);
			MDIO_u8SetPinValue(PS_button->GPIO_u8Port_Num,PS_button->GPIO_u8pin_Num,MDIO_u8_PIN_LOW);break;
			
			case  INTRNAL_PULL_UP :// Pull up  state DDR = 1 for i/p | port = 1 for active internal pull up
			MDIO_u8SetPinDirection(PS_button->GPIO_u8Port_Num,PS_button->GPIO_u8pin_Num,MDIO_u8_PIN_INPUT);
			MDIO_u8SetPinValue(PS_button->GPIO_u8Port_Num,PS_button->GPIO_u8pin_Num,MDIO_u8_PIN_HIGH);break;
			
		}
	}
	else
	{
		// wrong port|pin
		Local_u8ErrorState= STD_TYPES_NOK;
		
	}
	
	
	return Local_u8ErrorState;
	
}
/*****************************************************************************/

/******************************************************************************
 * Function Name:  buton_u8Read 
 *
 * Description:	the function identification  required button 
 *
 * Parameters: 1- PS_button : pointer to struct include required pin & port
 *             2- Copy_u8PINValue :pointer to char to read button pin 
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8  HBUTTON_u8Read(GPIO_BUTTON_CONFG * PS_button,u8 * Copy_u8PINValue)
{
	// local error to return if user select wrong configuration
	u8 Local_u8ErrorState = STD_TYPES_OK;
	// check if pin and port are true
	// -> = *PS_button.GPIO_u8Port_Num
	if(((PS_button->GPIO_u8Port_Num)<=MDIO_u8_PORTD)&& ((PS_button->GPIO_u8pin_Num)<=MDIO_u8_PIN7))
	{
		 //get pin value and storage it by address
		 MDIO_u8GetPinValue(PS_button->GPIO_u8Port_Num,PS_button->GPIO_u8pin_Num,Copy_u8PINValue);
	}
	else
	{
		// wrong port|pin
		Local_u8ErrorState= STD_TYPES_NOK;
		
	}
	
	
	return Local_u8ErrorState;
	
	
}
/*****************************************************************************/