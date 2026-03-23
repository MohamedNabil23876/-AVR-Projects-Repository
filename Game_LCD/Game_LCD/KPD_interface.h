/*
 * KPD_interface.h
 *
 *  Created on: ???/???/????
 *      Author: HP
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

u8 KPD_u8GetPreessedKey(void);

void GAME_VoidLCD(u8 y );
void WELCOME_MASSAGE(void);
void LINE_MASSAGE(void);
void paddle_show(void);
void BALL_show(void);
void GAME_Merge_Ball_Paddle(void);
void GAME_Merge_Ball_Paddle_Reverse(void);
void clear(void);


#endif /* KPD_INTERFACE_H_ */
