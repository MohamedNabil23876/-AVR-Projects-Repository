/*
 * Timer_Register.h
 *
 * Created: 11/09/2022 06:09:39 م
 *  Author: nabil
 */ 


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_
/********************** TIMER0 **********************/
#define  TCCR0   *((volatile u8*)0x53)   /* Timer0 Control  Register*/

#define TCCR0_WGM01 3					/*Set Mod Bit ( o.V/ CTC)3*/
#define TCCR0_WGM00 6					/*Set Mod Bit ( o.V/ CTC)6*/
#define TCCR0_CS02  2                   /*PreScelar Bit 2*/
#define TCCR0_CS01  1					/*PreScelar Bit 1*/
#define TCCR0_CS00  0					/*PreScelar Bit 0*/
#define TCCR0_FOC0  7                   //Force Output Compare

#define TIMSK    *((volatile u8*)0x59)  /*SET COMP Interrupt Enable*/
#define TIMSK_OCIE0 1                   //Timer/Counter0 Output Compare Match Interrupt Enable
#define TIMSK_TOIE0 0                   //Timer/Counter0 Overflow Interrupt Enable


#define  TCNT0  *((volatile u8*)0x52)  /* TIST Value REG*/
#define  OCR0   *((volatile u8*)0x5C) /* COMP Value REG*/


/********************** TIMER1 **********************/

#define TCCR1A *((volatile u8*)0x4F)   //Counter1 Control Register A
#define TCCR1A_FOC1A       2                    //Force Output Compare for Channel A
#define TCCR1A_FOC1B       3
// Waveform Generation Mode
#define TCCR1A_WGM10       0
#define TCCR1A_WGM11       1

#define TCCR1B *((volatile u8*)0x4E)  // Timer1 control Register B
                  //Force Output Compare for Channel B
#define TCCR1B_CS12        2                   /*PreScelar Bit 2*/
#define TCCR1B_CS11        1					/*PreScelar Bit 1*/
#define TCCR1B_CS10        0					/*PreScelar Bit 0*/
// Waveform Generation Mode
#define TCCR1B_WGM12       3
#define TCCR1B_WGM13       4

#define  TCNT1 *((volatile u16*)0x4C) // timer counter1 register u16 for to register L/H

#define OCR1A *((volatile u16*)0x4A) // COMP Value REG u16 for to register L/H

#define TIMSK_OCIE1A 4 //Timer/Counter1, Output Compare A Match Interrupt Enable
#define TIMSK_TOIE1 2 //Timer/Counter1, Overflow Interrupt Enable






#endif /* TIMER_REGISTER_H_ */