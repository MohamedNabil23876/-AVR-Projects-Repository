/******************************************************************************
 *******************************************************************************
 ************************* Module: Dc_Motor ************************************
 ********************** File Name: Dc_Motor.c **********************************
 * ************************Author: Mohamed_Nabil********************************
* ************************Created on: 15/1*****************************
 *******************************************************************************
 *******************************************************************************/
#include "dc_motor.h"
#include "gpio.h"
#include "PWM.h"

/* Description
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver
 * Stop at the DC-Motor at the beginning through the GPIO driver
 * Input :None
 * Output:None
 */
void DcMotor_Init(void)
{	 //SET Direction For PWM pin
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

	//SET Direction For  For The Two Motor Pins
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);

	//Stop  The DC-Motor At First
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
}

//--------------------------------------------------------------------------//

/*Description: The Function responsible for setup the direction for the two
 *motor pins through the GPIO driver
 *input:
 *1-DcMotor_State
 *option:-
 *A-CW
 *B-A_CW
 *C-STOP
 *2- Speed
 *option:-
 * a-DC_MOTOR_NO_SPEED
 * b-DC_MOTOR_25_SPEED
 * c-DC_MOTOR_50_SPEED
 * d-DC_MOTOR_75_SPEED
 * e-DC_MOTOR_100_SPEED
 *Output:None
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	//switch The DC_Motor State
	switch(state){
	case STOP: GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW); GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW); break;

	case CW: GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH); GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW); break;

	case ACW: GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW); GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);break;
	}
	// Send Speed TO PWM
	PWM_Timer0_Init(speed);

}
