/*
 * EXTI_interface.h
 *
 *  Created on: Jul 23, 2025
 *      Author: lenovo
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_u8INT0		0
#define EXTI_u8INT1		1
#define EXTI_u8INT2		2

#define 	LOW_LEVEL		1
#define 	ON_CHANGE		2
#define 	FALLING_EDGE	3
#define 	RISING_EDGE		4


void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);


u8 EXTI_u8SenseControl(u8 Copy_u8Int, u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8Int);
u8 EXTI_u8IntDisable(u8 Copy_u8Int);

u8 EXTI_u8IntSetCallBack(u8 Copy_u8Int, void(*Copy_pvIntFunc)(void));

#endif /* EXTI_INTERFACE_H_ */
