/*
 * SPI_interface.h
 *
 *  Created on: Jul 31, 2025
 *      Author: Eng Abd Elrhman
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_voidInit(void);


u8 SPI_u8TransmReceive(u8 Copy_u8SendData ,u8 *Copy_pu8ReceiveData);


void SPI_voidSendData(u8 Copy_u8SendData);

u8 SPI_voidReceiveData(u8 *Copy_pu8ReceiveData);
u8 SPI_SlaveReceive(void);

void SPI_MasterTransmit(u8 cData);


#endif /* SPI_INTERFACE_H_ */
