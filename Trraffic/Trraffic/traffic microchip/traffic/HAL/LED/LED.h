/*
 * LED.h
 *
 * Created: 09/09/2022 06:35:42 م
 *  Author: nabil
 */ 


#ifndef LED_H_
#define LED_H_

// include libraries
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_math.h"

// include DIO Header files

#include "../../MCAL/DIO1/DIO_Interface.h"

// struct to select required Pin 
typedef struct {
	u8  GPIO_u8Port_Num;                       
	u8  GPIO_u8pin_Num;                         
}GPIO_PIN_CONFG;

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
u8 HLED_u8inti(GPIO_PIN_CONFG *Ps_Inti);
/******************************************************************************/

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
u8 HLED_u8On(GPIO_PIN_CONFG *Ps_Inti);
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
u8 HLED_u8Off(GPIO_PIN_CONFG *Ps_Inti);
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
u8 HLED_u8Toggle(GPIO_PIN_CONFG *Ps_Inti);
/******************************************************************************/









#endif /* LED_H_ */