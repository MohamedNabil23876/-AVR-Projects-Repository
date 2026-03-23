/*
 * Timer1.h
 *
 * Created: 10/09/2022 08:24:05 م
 *  Author: nabil
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
/* include libraries*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_math.h"

// include Timer1 Header files
#include "TIMER_CONFIG.h"
#include "Timer_Register.h"
#include "Timer_Private.h"
/******************************************************TIMERS****************************************************************/

// enum to define timer/n
typedef enum
{
	TIMER0,TIMER1, TIMER2
}TIMER_NUM;

typedef enum
{
	OVF_Mode, CTC_Mode  // define mode 
}TIMER_Mode;

typedef enum
{
	NO_CLOCK, F_CPU_CLOCK, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024  // preSclear
}TIMER_Clock;

/* struct include timer configuration*/
typedef struct
{
	TIMER_NUM timer_ID;
	TIMER_Mode timer_mode;
	u32 timer_intial_value;
	TIMER_Clock timer_clock;
	u32 timer_compare_value;
}TIMERS_ConfigType;

/**************************************  Functions Prototypes  **************************************/ 


/******************************************************************************
 * Function Name:  Timer_inti 
 *
 * Description:	initialization required timer  
 *
 * Parameters: PsTimer pointer to struct include  required timer configuration
 * 
 * Return:non
 *
 ******************************************************************************/
u8 Timer_inti(TIMERS_ConfigType *PsTimer);
/******************************************************************************/

/******************************************************************************
 * Function Name:  Timer_setCallBack 
 *
 * Description:	 Save the address of the Call back function in a global variable   
 *
 * Parameters: 1- *a_ptr : pointer to func point to function Work in ISR
 *				2- EN_number enum include timers ID
 * Return:non
 *
 ******************************************************************************/
u8 Timer_setCallBack(void(*a_ptr)(void), TIMER_NUM EN_number);
/******************************************************************************/





#endif /* TIMER1_H_ */