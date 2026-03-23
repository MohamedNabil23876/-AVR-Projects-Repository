/*
 * CLCD_Cfg.h
 *
 *  Created on: ???/???/????
 *      Author: HP
 */

#ifndef CLCD_CFG_H_
#define CLCD_CFG_H_

/*  options :
 DIO_u8PORTA
 DIO_u8PORTB
 DIO_u8PORTC
 DIO_u8PORTD

 * */
#define CLCD_u8CTRL_PORT  DIO_u8PORTB
#define CLCD_u8DATA_PORT  DIO_u8PORTA
/*
 *  DIO_u8PIN0
 *  DIO_u8PIN1
 *  DIO_u8PIN2
 *  DIO_u8PIN3
 *  DIO_u8PIN4
 *  DIO_u8PIN5
 *  DIO_u8PIN6
 *  DIO_u8PIN7
 */
#define CLCD_u8RS_PIN     DIO_u8PIN0
#define CLCD_u8RW_PIN     DIO_u8PIN1
#define CLCD_u8E_PIN      DIO_u8PIN2


#endif /* CLCD_CFG_H_ */
