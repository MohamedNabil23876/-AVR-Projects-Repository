/*
 * TMR_reg.h
 *
 *  Created on: Jul 27, 2025
 *      Author: lenovo
 */

#ifndef TMR_REG_H_
#define TMR_REG_H_

#define TCCR0	*((volatile u8*)0x53)
#define	TCCR0_WGM00	6
#define	TCCR0_WGM01	3
#define TCCR0_CS02	2
#define TCCR0_CS01	1


#define TCNT0	*((volatile u8*)0x52)

#define OCR0 	*((volatile u8*)0x5C)

#define TIMSK	*((volatile u8*)0x59)
#define TIMSK_TOIE0	0
#define TIMSK_OCIE0	1






#endif /* TMR_REG_H_ */
