/*
 * CLCD_interface.h
 *
 *  Created on: ???/???/????
 *      Author: HP
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommend(u8 Copy_u8Commend);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidInit(void);
void CLCD_voidSendString(const char *Copy_u8Ptr);
void CLCD_voidGoToXY(u8 Copy_u8Ypos,u8 Copy_u8Xpos);
void CLCD_voidLoopXY(u8 Copy_u8Ypos,u8 Copy_u8Xpos);
void CLCD_voidWriteSpectialCharacter(u8 *Copy_pu8Arr ,u8 Copy_u8BlockNo,u8 Copy_u8XPos ,u8 Copy_u8YPos);
void CLCD_VoidClear(void);
void CLCD_voidSTWA(void);
void CLCD_voidWriteNumber (u32 Copy_u32Number);

#endif /* CLCD_INTERFACE_H_ */
