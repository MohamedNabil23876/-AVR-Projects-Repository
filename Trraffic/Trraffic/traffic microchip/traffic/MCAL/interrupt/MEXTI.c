/*
 * MEXTI.c
 *
 * Created: 10/09/2022 08:17:03 م
 *  Author: nabil
 */ 


#include "MEXTI.h"

/* global Pointer to function to hold call back Function*/
static volatile void (* G_pvInt0Function)(void)=NULL ;
static volatile void (* G_pvInt1Function)(void)=NULL ;
static volatile void (* G_pvInt2Function)(void)=NULL ;

/******************************************************************************
 * Function Name:  GIE_VoidEnable 
 *
 * Description:	the function Enable interrupt
 *
 * Parameters:non
 * Return:no
 *
 ******************************************************************************/

void GIE_VoidEnable(void)
{
	SET_BIT(SREG,SREG_I);

}
/******************************************************************************/

/******************************************************************************
 * Function Name:  GIE_VoidDisable 
 *
 * Description:	the function Disable  interrupt
 *
 * Parameters:non
 * Return:no
 *
 ******************************************************************************/

void GIE_VoidDisable(void)
{

	CLR_BIT(SREG,SREG_I);
}
/******************************************************************************/


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
u8 MEXTI_VoidInterruptIntPostBuild(u8 Copy_u8state , u8 Copy_u8Inte , u8 Copy_u8Intioalstate )
{
	u8 L_ErrorState=STD_TYPES_OK; // local var to check Error

     // check error 
	if ((Copy_u8state>RISING_ADGE)||(Copy_u8Inte>INT2)||(Copy_u8Intioalstate>DISABLE))
	{
		L_ErrorState=STD_TYPES_NOK;
	}
	else
	{
		if((Copy_u8Inte==INT0)) // if INT0
		{
			switch(Copy_u8state) // select mode 
			{
			case LOW_LEVEL: CLR_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01);break;
			case On_CHANGE: SET_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01);break;
			case FALLING_ADGE: CLR_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);break;
			case RISING_ADGE: SET_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);break;

			} // enable | disable interrupt
			if (Copy_u8Intioalstate==ENABIL)
			{
				SET_BIT(GICR,GICR_INT0);
			}
			else
			{
				CLR_BIT(GICR,GICR_INT0);
			}
		}
		else if ((Copy_u8Inte==INT1))  // case if INT1
		{
			switch(Copy_u8state)// select mode 
			{
			case LOW_LEVEL: CLR_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11);break;
			case On_CHANGE: SET_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11);break;
			case FALLING_ADGE: CLR_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11);break;
			case RISING_ADGE: SET_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11);break;

			}// enable | disable interrupt
			if (Copy_u8Intioalstate==ENABIL)
			{
				SET_BIT(GICR,GICR_INT1);
			}
			else
			{
				CLR_BIT(GICR,GICR_INT1);
			}
		}
		else if (Copy_u8Inte==INT2)
		{
			switch(Copy_u8state) // select mode
			{
			case FALLING_ADGE: CLR_BIT(MCUCSR,MCUCSR_INT2);break;
			case RISING_ADGE:  SET_BIT(MCUCSR,MCUCSR_INT2);break;

			}// enable | disable interrupt
			if (Copy_u8Intioalstate==ENABIL)
			{
				SET_BIT(GICR,GICR_INT2);
			}
			else
			{
				CLR_BIT(GICR,GICR_INT2);
			}
		}
		else
		{
			L_ErrorState=STD_TYPES_NOK;
		}

	}

	return L_ErrorState;
}
/*****************************************************************************/

/******************************************************************************
 * Function Name:  MEXTI_u8Int0SetCallBack 
 *
 * Description:	the function Set call back function of INT0 
 *
 * Parameters: pvInt0 : pointer  to function 
 * Return:no
 *
 ******************************************************************************/
u8 MEXTI_u8Int0SetCallBack(void (*pvInt0)(void))
{
	u8 L_ErrorState=STD_TYPES_OK;

	if(pvInt0!=NULL) // if pointer != Null pointer 
	{
		G_pvInt0Function=pvInt0; // Set Call Back
	}
	else
	{
		L_ErrorState=NULL_POINTER; // if == null Pointer 
	}
	return L_ErrorState;
}
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
u8 MEXTI_u8Int1SetCallBack(void (*pvInt1)(void))
{
	u8 L_ErrorState=STD_TYPES_OK;

		if(pvInt1!=NULL)// if pointer != Null pointer 
		{
			G_pvInt1Function=pvInt1;// Set Call Back
		}
		else
		{
			L_ErrorState=NULL_POINTER;// if == null Pointer
		}
		return L_ErrorState;
	}
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
u8 MEXTI_u8Int2SetCallBack(void (*pvInt2)(void))
{
	u8 L_ErrorState=STD_TYPES_OK;

		if(pvInt2!=NULL)// if pointer != Null pointer 
		{
			G_pvInt2Function=pvInt2;// Set Call Back
		}
		else
		{
			L_ErrorState=NULL_POINTER;// if == null Pointer
		}
		return L_ErrorState;
	}
/******************************************************************************/

/******************************* ISR_INT0 *************************************/

// Calls the call back function of INT0 in case of INT0 interrupt occurs
//  __attribute__ to Linker don't move this function 
void __vector_1(void) __attribute__((signal)); 
void __vector_1(void)
{
	if (G_pvInt0Function!=NULL) // if pointer != Null pointer
	{
		G_pvInt0Function();
	}
	else
	{
		// nothing
	}
}
/******************************************************************************/

/******************************* ISR_INT1 *************************************/

// Calls the call back function of INT1 in case of INT1 interrupt occurs
//  __attribute__ to Linker don't move this function
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (G_pvInt1Function!=NULL)
		{
			G_pvInt1Function(); // if pointer != Null pointer
		}
		else
		{
			// nothing
		}
}
/******************************************************************************/

/******************************* ISR_INT2 *************************************/

// Calls the call back function of INT2 in case of INT2 interrupt occurs
//  __attribute__ to Linker don't move this function
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (G_pvInt2Function!=NULL) // if pointer != Null pointer
		{
			G_pvInt2Function();
		}
		else
		{
			// nothing
		}
}
/******************************************************************************/

