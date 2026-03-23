/*
 * button.h
 *
 * Created: 09/09/2022 08:25:21 م
 *  Author: nabil
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

// include libraries
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_math.h"

// include DIO Header files
#include "../../MCAL/DIO1/DIO_Interface.h"

// include button Header files
#include "config.h"

// struct to select required Pin
typedef struct {
	u8  GPIO_u8Port_Num;
	u8  GPIO_u8pin_Num;
	u8  GPIO_u8PIN_state;
}GPIO_BUTTON_CONFG;


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
u8  HBUTTON_u8inti(GPIO_BUTTON_CONFG * PS_button);
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
u8  HBUTTON_u8Read(GPIO_BUTTON_CONFG * PS_button,u8 * Copy_u8PINValue);
/*****************************************************************************/





#endif /* BUTTON_H_ */