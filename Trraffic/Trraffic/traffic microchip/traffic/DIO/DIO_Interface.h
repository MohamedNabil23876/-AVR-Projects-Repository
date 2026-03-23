
/*
 * DIO_Interface.h
 *
 * Created: 09/09/2022 02:02:55 ص
 *  Author: nabil
 */ 

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_Config.h"

#include "BIT_MATH.h"
#include "STD_TYPES.h"



void MDIO_voidSetPinDirection(u8 A_u8PortNo,u8 A_u8PinNo,u8 A_u8PinDirection);
void MDIO_voidSetPinValue(u8 A_u8PortNo,u8 A_u8PinNo,u8 A_u8PinValue);
u8 MDIO_u8GetPinValue(u8 A_u8PortNo,u8 A_u8PinNo);
void MDIO_voidSetPortDirection(u8 A_u8PortNo, u8 A_u8PortDirection);
void MDIO_voidSetPortValue(u8 A_u8PortNo, u8 A_u8PortValue);

#endif /* DIO_INTERFACE_H_ */
