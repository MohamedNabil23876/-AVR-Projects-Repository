/*
 * App.h
 *
 * Created: 12/09/2022 07:50:05 ص
 *  Author: nabil
 */ 


#ifndef APP_H_
#define APP_H_

// include header files 
//MCAL
#include "../MCAL/DIO1/DIO_Interface.h" 
#include "../MCAL/interrupt/MEXTI.h"
#include "../MCAL/Timers/Timer1.h"
//HAL
#include "../HAL/button/button.h"
#include "../HAL/LED/LED.h"
// app header file 
#include "App_config.h"


/******************************************************************************
 * Function Name:  timer_ISR 
 *
 * Description:this function hold ISR for Timer1 and set what 
 *              What is happening when call ISR 
 *
 * Parameters: non
 *    
 * Return:non
 *
 ******************************************************************************/
void timer_ISR(void);
/******************************************************************************/

/******************************************************************************
 * Function Name:  Button_ISR 
 *
 * Description:	this function hold ISR for button  and set what
 *              What is happening when call ISR  
 *
 * Parameters: non
 *    
 * Return:non
 *
 ******************************************************************************/
void Button_ISR (void);
/*****************************************************************************/

/******************************************************************************
 * Function Name:  start_App 
 *
 * Description:	this function   initialize and start the program 
 *
 * Parameters: non
 *    
 * Return:non
 *
 ******************************************************************************/
void start_App (void);
/******************************************************************************/


#endif /* APP_H_ */