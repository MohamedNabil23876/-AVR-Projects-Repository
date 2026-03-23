 /******************************************************************************
 *
 * Module: stop_watch
 *
 * File Name: Common_Macros.h
 *
 * Description: Common Macros
 *
 * Author: Mohamed nabil
 *
 *******************************************************************************/
#ifndef BIT_MATH_h_
#define BIT_MATH_h_



#define SET_BIT(VAR,BIT_NO) VAR|=(1<<BIT_NO)
#define CLR_BIT(VAR,BIT_NO) VAR&=~(1<<BIT_NO)
#define TOGGLE_BIT(VAR,BIT_NO) VAR^=(1<<BIT_NO)
#define GET_BIT(VAR,BIT_NO) (VAR>>BIT_NO)&1


#endif
