/*
 * EXIT_Cfg.h
 *
 *  Created on: ???/???/????
 *      Author: HP
 */

#ifndef EXIT_CFG_H_
#define EXIT_CFG_H_

/*
	Choose option for INT0 ,INT1:
					1- LOW_LEVEL
					2- ON_CHANGE
					3- FALLING_EDGE
					4- RISING_EDGE
*/
#define INT0_SENSE	FALLING_EDGE
#define INT1_SENSE	FALLING_EDGE

/*
	Choose option for INT2:
					1- FALLING_EDGE
					2- RISING_EDGE
*/
#define INT2_SENSE	FALLING_EDGE
/*
	Choose option :
					1- ENABLE
					2- DISABLED
*/

#define  INTO_INITAL_STATE	ENABLE
#define  INT1_INITAL_STATE	ENABLE
#define  INT2_INITAL_STATE  ENABLE


#endif /* EXIT_CFG_H_ */
