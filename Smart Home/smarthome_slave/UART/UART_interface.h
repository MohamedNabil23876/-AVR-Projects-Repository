/*
 * UART_interface.h
 *
 *  Created on: Jul 30, 2025
 *      Author: Eng Abd Elrhman
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_voidInit(void);

void UART_voidSendData(u8 Copy_u8Data);

u8 UART_u8ReveiveData(u8 *Copy_pu8Data);

u8 UART_u8AsyncRecieveData(u8 *Copy_pu8Data);
void UART_voidAsyncSendData(u8 Copy_u8Data);

#endif /* UART_INTERFACE_H_ */
