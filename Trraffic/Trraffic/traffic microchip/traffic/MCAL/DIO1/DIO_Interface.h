/*
 * DIO_Interface.h
 *
 * Created: 09/09/2022 02:13:48 ص
 *  Author: nabil
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

// include libraries
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_math.h"

// include DIO Header files
#include "DIO_Register.h"
#include "DIO_Config.h"


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
u8 MDIO_u8SetPinDirection(u8 Copy_u8PortName, u8 Copy_u8Pin , u8 Copy_u8PinDirection );
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
u8 MDIO_u8SetPinValue(u8 Copy_u8PortName, u8 Copy_u8Pin , u8  Copy_u8PinValue);
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
u8 MDIO_u8SetPortDirection(u8 Copy_u8PortName,  u8 Copy_u8PortDirection );
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
u8 MDIO_u8SetPortValue(u8 Copy_u8PortName,  u8  Copy_u8PortValue);
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
u8 MDIO_u8TogglePinValue(u8 Copy_u8PortName, u8 Copy_u8Pin );
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
u8  MDIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8Pin, u8 * Copy_pu8ReturnedValue );
/**********************************************************************************************/







#endif /* DIO_INTERFACE_H_ */