
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidInit(void);
void TIMER1_voidInit(void);

void TIMER1_voidSetICR(u16 Copy_u16Top);

void TIMER0_voidSetPreload(u8 Copy_u8Value);
void TIMER0_voidSetCompMatch(u8 Copy_u8Value);
void TIMER1_voidSetCompMatch(u16 Copy_u16Value);

u16 TIMER1_voidGetReading(void);
void TIMER1_voidSetTimerValue(u16 Copy_u16Value);


u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBack)(void));

#endif /* TIMER_INTERFACE_H_ */
