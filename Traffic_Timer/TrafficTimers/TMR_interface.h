
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidInit(void);

void TIMER0_voidSetPreload(u8 Copy_u8Value);

void TIMER0_voidSetCompare(u8 Copy_u8Value);
u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBack)(void));

u8 TRAFFIC_u8IntSetCallBack(void(*Copy_pvIntFunc)(void));
void Yellow(void);
void Green(void);
void Red(void);


#endif /* TIMER_INTERFACE_H_ */
