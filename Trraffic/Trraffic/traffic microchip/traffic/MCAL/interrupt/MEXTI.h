/*
 * MEXTI.h
 *
 * Created: 10/09/2022 08:14:49 م
 *  Author: nabil
 */ 


#ifndef MEXTI_H_
#define MEXTI_H_

/* include libraries*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_math.h"

// include EXTI Header files
#include "MEXTI_private.h"
#include "MEXTI_Config.h"
#include "MEXTI_Register.h"


/******************************************************************************
 * Function Name:  GIE_VoidEnable 
 *
 * Description:	the function Enable interrupt
 *
 * Parameters:non
 * Return:no
 *
 ******************************************************************************/
void GIE_VoidEnable(void);
/*****************************************************************************/

/******************************************************************************
 * Function Name:  GIE_VoidDisable 
 *
 * Description:	the function Disable  interrupt
 *
 * Parameters:non
 * Return:no
 *
 ******************************************************************************/
void GIE_VoidDisable(void);
/*****************************************************************************/

/*************************************************************************************************
 * Function Name:  MEXTI_VoidInterruptIntPostBuild
 *
 * Description:	the function initialize the required interrupt   options
 *
 * Parameters:
 * 1- Copy_u8state option :-              | 2-Copy_u8Inte option :- |  Copy_u8Intioalstate |
 *  	   	   	   	   	   	LOW_LEVEL     |                 INT0    |          ENABIL      |
 * 	   	   	   	   	   	    On_CHANGE     |                 INT1    |          DISABLE     |
 * 						    FALLING_ADGE  |                 INT2    |                      |
 *							RISING_ADGE   |                         |                      |
 *
 * Return:	ErrorState , Type:u8
 *
 *************************************************************************************************/
u8 MEXTI_VoidInterruptIntPostBuild(u8 Copy_u8state , u8 Copy_u8Inte ,u8 Copy_u8Intioalstate );

/******************************************************************************
 * Function Name:  MEXTI_u8Int0SetCallBack 
 *
 * Description:	the function Set call back function of INT0 
 *
 * Parameters: pvInt0 : pointer  to function 
 * Return:no
 *
 ******************************************************************************/
 u8 MEXTI_u8Int0SetCallBack(void (*pvInt0)(void));
 /******************************************************************************/
 
 /******************************************************************************
 * Function Name:  MEXTI_u8Int1SetCallBack 
 *
 * Description:	the function Set call back function of INT1 
 *
 * Parameters: pvInt0 : pointer  to function 
 * Return:no
 *
 ******************************************************************************/
 u8 MEXTI_u8Int1SetCallBack(void (*pvInt1)(void));
 /******************************************************************************/
 
 /******************************************************************************
 * Function Name:  MEXTI_u8Int2SetCallBack 
 *
 * Description:	the function Set call back function of INT2
 *
 * Parameters: pvInt0 : pointer  to function 
 * Return:no
 *
 ******************************************************************************/
 u8 MEXTI_u8Int2SetCallBack(void (*pvInt2)(void));
 /******************************************************************************/


#endif /* MEXTI_H_ */