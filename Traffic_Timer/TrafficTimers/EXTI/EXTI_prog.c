/*
 * EXTI_prog.c
 *
 *  Created on: Jul 23, 2025
 *      Author: lenovo
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/ERR_TYPE.h"

#include "EXTI_interface.h"
#include "EXTI_cfg.h"
#include "EXTI_prv.h"
#include "EXTI_reg.h"

/* Global pointer to function  */
void (*EXTI_pvIntFunc[3])(void) = {NULL} ;


//void (*EXTI_pvInt0Func)(void) = NULL ;
//void (*EXTI_pvInt1Func)(void) = NULL ;
//void (*EXTI_pvInt2Func)(void) = NULL ;

void EXTI_voidInt0Init(void)
{
	/*Check Sense Control */

	#if	 INT0_SENSE == LOW_LEVEL
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
	#elif INT0_SENSE ==	ON_CHANGE
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
	#elif INT0_SENSE ==	FALLING_EDGE
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
	#elif INT0_SENSE ==	RISING_EDGE
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
	#else
		#error "Warning INT0_SENSE configuration option "
	#endif

	/* Check peripheal intrrupt enable */
	#if	  INTO_INITAL_STATE	==	ENABLE
			SET_BIT(GICR,GICR_INT0);
	#elif INTO_INITAL_STATE	== DISABLED
			CLR_BIT(GICR,GICR_INT0);
	#else
		#error "Warning INTO_INITAL_STATE configuration option "
	#endif

}

void EXTI_voidInt1Init(void)
{
	/*Check Sense Control */
	#if	  INT1_SENSE	== LOW_LEVEL
			CLR_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
	#elif INT1_SENSE ==	ON_CHANGE
			SET_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
	#elif INT1_SENSE ==	FALLING_EDGE
			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
	#elif INT1_SENSE ==	RISING_EDGE
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
	#else
		#error "Warning INT1_SENSE configuration option "
	#endif

	/* Check peripheal intrrupt enable */
	#if	  INT1_INITAL_STATE	==	ENABLE
			SET_BIT(GICR,GICR_INT1);
	#elif INT1_INITAL_STATE	==	DISABLED
			CLR_BIT(GICR,GICR_INT1);
	#else
		#error "Warning INT1_INITAL_STATE configuration option "
	#endif
}

void EXTI_voidInt2Init(void)
{
	/*Check Sense Control */
	#if	  INT2_SENSE ==	FALLING_EDGE
			CLR_BIT(MCUCSR,MCUCSR_ISC2);
	#elif INT2_SENSE ==	RISING_EDGE
			SET_BIT(MCUCSR,MCUCSR_ISC2);
//	#else
//		#error "Warning INT2_SENSE configuration option "
	#endif

	/* Check peripheal intrrupt enable */
	#if	  INT2_INITAL_STATE	==	ENABLE
			SET_BIT(GICR,GICR_INT2);
	#elif INT2_INITAL_STATE	==	DISABLED
			CLR_BIT(GICR,GICR_INT2);
	#else
		#error "Warning INT2_INITAL_STATE configuration option "
	#endif
}

u8 EXTI_u8SenseControl(u8 Copy_u8Int, u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;

	if(Copy_u8Int == EXTI_u8INT0)
	{
		switch(Copy_u8Sense)
		{
			case LOW_LEVEL		:	CLR_BIT(MCUCR,MCUCR_ISC00);
									CLR_BIT(MCUCR,MCUCR_ISC01);	break;
			case ON_CHANGE		:	SET_BIT(MCUCR,MCUCR_ISC00);
									CLR_BIT(MCUCR,MCUCR_ISC01);	break;
			case FALLING_EDGE	:	CLR_BIT(MCUCR,MCUCR_ISC00);
									SET_BIT(MCUCR,MCUCR_ISC01);	break;
			case RISING_EDGE	:	SET_BIT(MCUCR,MCUCR_ISC00);
									SET_BIT(MCUCR,MCUCR_ISC01);	break;
			default				:	Local_u8ErrorState = NOK;
		}
	}
	else if(Copy_u8Int == EXTI_u8INT1)
	{
		switch(Copy_u8Sense)
		{
			case LOW_LEVEL		:	CLR_BIT(MCUCR,MCUCR_ISC10);
									CLR_BIT(MCUCR,MCUCR_ISC11);	break;
			case ON_CHANGE		:	SET_BIT(MCUCR,MCUCR_ISC10);
									CLR_BIT(MCUCR,MCUCR_ISC11);	break;
			case FALLING_EDGE	:	CLR_BIT(MCUCR,MCUCR_ISC10);
									SET_BIT(MCUCR,MCUCR_ISC11);	break;
			case RISING_EDGE	:	SET_BIT(MCUCR,MCUCR_ISC10);
									SET_BIT(MCUCR,MCUCR_ISC11);	break;
			default				:	Local_u8ErrorState = NOK;
		}
	}
	else if(Copy_u8Int == EXTI_u8INT2)
	{
		switch(Copy_u8Sense)
		{
			case FALLING_EDGE	:	CLR_BIT(MCUCSR,MCUCSR_ISC2)	;break;
			case RISING_EDGE	:	SET_BIT(MCUCSR,MCUCSR_ISC2)	;break;
			default				:	Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Int)
	{
		case EXTI_u8INT0:	SET_BIT(GICR,GICR_INT0);	break;
		case EXTI_u8INT1:	SET_BIT(GICR,GICR_INT1);	break;
		case EXTI_u8INT2:	SET_BIT(GICR,GICR_INT2);	break;
		default			:	Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;

}

u8 EXTI_u8IntDisable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Int)
	{
		case EXTI_u8INT0:	CLR_BIT(GICR,GICR_INT0);	break;
		case EXTI_u8INT1:	CLR_BIT(GICR,GICR_INT1);	break;
		case EXTI_u8INT2:	CLR_BIT(GICR,GICR_INT2);	break;
		default			:	Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntSetCallBack(u8 Copy_u8Int, void(*Copy_pvIntFunc)(void))
{
	u8 Local_u8ErrorState = OK ;

	if(Copy_pvIntFunc != NULL)
	{
		switch(Copy_u8Int)
		{
			case EXTI_u8INT0 :  EXTI_pvIntFunc[0] = Copy_pvIntFunc; break ;
			case EXTI_u8INT1 :  EXTI_pvIntFunc[1] = Copy_pvIntFunc; break ;
			case EXTI_u8INT2 :  EXTI_pvIntFunc[2] = Copy_pvIntFunc; break ;
			default 	   : Local_u8ErrorState = NOK ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}



/* ISR INT0*/
void __vector_1	(void)	__attribute__((signal));
void __vector_1	(void)
{
	EXTI_pvIntFunc[0]();
}


/* ISR INT1 */
void __vector_2	(void)	__attribute__((signal));
void __vector_2	(void)
{
	EXTI_pvIntFunc[1]();
}

/* ISR INT2 */
void __vector_3	(void)	__attribute__((signal));
void __vector_3	(void)
{
	EXTI_pvIntFunc[2]();
}
