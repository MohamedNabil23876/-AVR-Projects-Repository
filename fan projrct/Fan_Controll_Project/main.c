/*
 * main.c
 *
 ?
 *      Author: nabil
 */
#include <util/delay.h>
#include "adc.h"
#include "dc_motor.h"
#include "lcd.h"
#include "PWM.h"
#include "lm35_sensor.h"



void main(void)
{
	ADC_ConfigType ADC_Config={internal,F_CPU_CLOCK};
	uint8 temp;


	ADC_init(&ADC_Config);
	LCD_init();
	DcMotor_Init();
	LCD_displayStringRowColumn(1,0,"Temp =    C");

	while(1)
	{
		temp=LM35_getTemperature()	;

		if(temp<30)
		{
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			DcMotor_Rotate(STOP,DC_MOTOR_NO_SPEED);
			LCD_displayStringRowColumn(0,0,"Fan Is Off");
			LCD_displayCharacter(' ');

		}
		else if((temp>=30)&&(temp<60))
		{
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW,DC_MOTOR_25_SPEED);
			LCD_displayStringRowColumn(0,0,"Fan Is On ");
			LCD_displayCharacter(' ');
		}
		else if ((temp>=60)&&(temp<90))
		{
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW,DC_MOTOR_50_SPEED);
			LCD_displayStringRowColumn(0,0,"Fan Is On ");
			LCD_displayCharacter(' ');
		}
		else if ((temp>=90)&&(temp<120))
		{
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW,DC_MOTOR_75_SPEED);
			LCD_displayStringRowColumn(0,0,"Fan Is On ");
			LCD_displayCharacter(' ');
		}
		else if (temp>120)
		{
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW,DC_MOTOR_100_SPEED);
			LCD_displayStringRowColumn(0,0,"Fan Is On ");
			LCD_displayCharacter(' ');

		}

		/*DcMotor_Rotate(CW,128);
		temp = LM35_getTemperature();

				/* Display the temperature value every time at same position
				LCD_moveCursor(0,7);
				if(temp >= 100)
				{

					LCD_intgerToString(temp);
				}
				else
				{
					LCD_intgerToString(temp);
					/* In case the digital value is two or one digits print space in the next digit place
					LCD_displayCharacter(' ');
				}
		 */


		/*if(temp<30)
		{


			DcMotor_Rotate(STOP,DC_MOTOR_NO_SPEED);
			LCD_Set_Temp(temp);


		}*/

	}


}

