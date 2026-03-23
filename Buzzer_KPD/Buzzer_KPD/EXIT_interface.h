/*
 * EXIT_interface.h
 *
 *  Created on: ???/???/????
 *      Author: HP
 */

#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_

#define EXTI_u8INT0		0
#define EXTI_u8INT1		1
#define EXTI_u8INT2		2

void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);


u8 EXTI_u8IntSetCallBack(u8 Copy_u8Int, void(*Copy_pvIntFunc)(void));


#endif /* EXIT_INTERFACE_H_ */

