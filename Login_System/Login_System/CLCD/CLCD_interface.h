/*
 * CLCD_interface.h
 *
 *  Created on: Jul 20, 2025
 *      Author: lenovo
 */

#ifndef CLCD_CLCD_INTERFACE_H_
#define CLCD_CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidInit(void);

void CLCD_voidSendString(const char* Copy_pcString);
void CLCD_voidGoToXY(u8 Copy_u8Ypos,u8 Copy_u8Xpos);
void CLCD_voidWriteSpectialCharacter(u8 *Copy_pu8Arr ,u8 Copy_u8BlockNo,u8 Copy_u8XPos ,u8 Copy_u8YPos);
void CLCD_voidWriteNumber (u32 Copy_u32Number);
void clear(void);
void CLCD_VoidClear(void);

void WELCOME_MASSAGE(void);


#endif /* CLCD_CLCD_INTERFACE_H_ */
