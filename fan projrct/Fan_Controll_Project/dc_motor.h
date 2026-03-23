 /******************************************************************************
 *******************************************************************************
 ************************* Module: Dc_Motor ************************************
 ********************** File Name: Dc_Motor.h **********************************
 * ************************Author: Mohamed_Nabil********************************
 *******************************************************************************
 *******************************************************************************/

#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

typedef enum{
	STOP,CW,ACW
}DcMotor_State;

#define DC_MOTOR_NO_SPEED 0
#define DC_MOTOR_25_SPEED 64
#define DC_MOTOR_50_SPEED 128
#define DC_MOTOR_75_SPEED 192
#define DC_MOTOR_100_SPEED 255

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/* Description
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver
 * Stop at the DC-Motor at the beginning through the GPIO driver
 * Input :None
 * Output:None
*/
 void DcMotor_Init(void);
 

 /*----------------------------------------------------------------------------*/


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
 * d-DC_MOTOR_50_SPEED
 * e-DC_MOTOR_50_SPEED
 *Output:None
 */
 void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H */
