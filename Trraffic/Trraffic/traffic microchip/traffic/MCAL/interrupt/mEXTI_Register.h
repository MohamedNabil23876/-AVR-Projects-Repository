/*
 * EXTI_Register.h
 *
 * Created: 10/09/2022 08:15:51 م
 *  Author: nabil
 */ 


#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


/******************define_REGISTER************************/

/*define_GICR_Regisre_And_pins*/
#define GICR       *((volatile u8*)0x5B)
#define GICR_INT1  7
#define GICR_INT0  6
#define GICR_INT2  5
/*******************/

#define GIFR       *((volatile u8*)0x5A)
/*******************/

/*define_MCUCR_Regisre_And_pins*/
#define MCUCR       *((volatile u8*)0x55)
#define MCUCR_ISC11 3
#define MCUCR_ISC10 2
#define MCUCR_ISC01	1
#define MCUCR_ISC00	0
/*******************/

/*define_MCUCSR_Regisre_And_pin*/
#define MCUCSR        *((volatile u8*)0x54)
#define MCUCSR_INT2   6

/*******************************/
#define SREG          *((volatile u8*)0x5F)
#define SREG_I       7




#endif /* EXTI_REGISTER_H_ */