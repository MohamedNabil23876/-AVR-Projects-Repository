#ifndef  KPD_INTERFACE_H_
#define  KPD_INTERFACE_H_



u8 KPD_u8GetPreessedKey(void);
void KPD_voidShiftRight(u8 arr,u8 CopyPos);
void KPD_voidShiftLeft(u8 arr,u8 CopyPos);


void WELCOME_MASSAGE(void);
void LINE_MASSAGE(void);
void paddle_show(void);
void BALL_show(void);
void GAME_Merge_Ball_Paddle(void);
void GAME_Merge_Ball_Paddle_Reverse(void);



#endif
