

#ifndef CLCD_INTERFCAE_H_
#define CLCD_INTERFCAE_H_




void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);


void CLCD_voidInit(void);
void CLCD_voidSendString(const char *Copy_pcString);
void CLCD_voidGoToXY(u8 Copy_u8XPos ,u8 Copy_u8YPos);
void CLCD_voidWriteSpectialCharacter(u8 *Copy_pu8Arr ,u8 Copy_u8BlockNo,u8 Copy_u8XPos ,u8 Copy_u8YPos);
void CLCD_VoidSendNumber(u32 Copy_u32Number);
void CLCD_VoidClear(void);

#endif
