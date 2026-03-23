/*
 * App1.c
 *
 * Created: 12/09/2022 07:50:20 ص
 *  Author: nabil
 */ 
#include "App1.h"
// global var to change Led
u8 g_LEDCount =0;
// global var increment when ISR is occur
extern u32 localcounter ;

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
void start_App (void)
{
	
	// enable interrupt 
	GIE_VoidEnable();
	/* struct hold the LEDS configuration */
	GPIO_PIN_CONFG LEDC1 ={MDIO_u8_PORTA,MDIO_u8_PIN0}; // Green LED normal mode 
	GPIO_PIN_CONFG LEDC2 ={MDIO_u8_PORTA,MDIO_u8_PIN1}; // Yellow LED normal mode 
	GPIO_PIN_CONFG LEDC3 ={MDIO_u8_PORTA,MDIO_u8_PIN2}; // Red LED normal mode 
	GPIO_PIN_CONFG LEDP1 ={MDIO_u8_PORTC,MDIO_u8_PIN0}; // Green LED pedeDstrian mode
	GPIO_PIN_CONFG LEDP2 ={MDIO_u8_PORTC,MDIO_u8_PIN1}; // Yellow LED pedeDstrian mode
	GPIO_PIN_CONFG LEDP3 ={MDIO_u8_PORTC,MDIO_u8_PIN2}; // Red LED pedeDstrian mode 
		
		// initialization LEDS as Output Pins
	HLED_u8inti(&LEDC1);
	HLED_u8inti(&LEDC2);
	HLED_u8inti(&LEDC3);
	HLED_u8inti(&LEDP1);
	HLED_u8inti(&LEDP2);
	HLED_u8inti(&LEDP3);
	  /*  chose the EXTI Mode and Edge and enable interrupt 
	       chose  INTO | Low_LEVEL 
		   Edge come from button */
	MEXTI_VoidInterruptIntPostBuild(LOW_LEVEL,INT0,ENABIL );
	/* SET Timer1 configuration   */
	TIMERS_ConfigType TIM ={TIMER1,CTC_Mode,0,F_CPU_8,50000};
	Timer_inti(&TIM); //initialize Timer1
	Timer_setCallBack(&timer_ISR,TIMER1); // SET Timer1 call Back Function
	MEXTI_u8Int0SetCallBack(&Button_ISR);// SET IINT) call Back Function
}
/******************************************************************************/

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
void timer_ISR (void)
{
	
	switch (g_LEDCount)
	{
		//if Green LED is on
		
		case GREEN_LED : 
		// normal mode
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN2,MDIO_u8_PIN_LOW);    //  RED off
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN0,MDIO_u8_PIN_HIGH);   // Green LED is on
		//pedeDstrian mode
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN2,MDIO_u8_PIN_HIGH);   // Red LED on
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN0,MDIO_u8_PIN_LOW);    // green off
		g_LEDCount++;break;
		case YELLOW_LED : // if yellow is on
		// normal mode 
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN0,MDIO_u8_PIN_LOW);   //green off
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN1,MDIO_u8_PIN_HIGH);  // yellow on 
		//pedeDstrian mode
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN2,MDIO_u8_PIN_LOW);   // RED off
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN1,MDIO_u8_PIN_HIGH);  // yellow on 
		g_LEDCount++;break;
		case RED_LED : // if yellow is on 
		// normal mode
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN1,MDIO_u8_PIN_LOW);   // yellow off
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN2,MDIO_u8_PIN_HIGH);  // Red LED on
		//pedeDstrian mode
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN0,MDIO_u8_PIN_HIGH);  // Green LED is on
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN1,MDIO_u8_PIN_LOW);   // yellow off
		g_LEDCount=0;break;
		                         
	}

}
/***********************************************************************************************/

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
void Button_ISR (void)
{
	
	 // if Green LEd is on 
	if(PINA_REG&(1<<0))
	{
		TCNT1=0; // Timer =0 and start count from zero
		localcounter=0; // =0  To count five seconds from the first
		
		/*
		in normal mode 
		- green Led off 
		- Yellow Led on
		*/
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN0,MDIO_u8_PIN_LOW); 
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN1,MDIO_u8_PIN_HIGH);
		/*
		in pedeDstrian  mode 
		- Red Led off 
		- Yellow Led on
		*/
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN2,MDIO_u8_PIN_LOW);
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN1,MDIO_u8_PIN_HIGH);
		
	}
	else if (PINA_REG&(1<<1)) // if Yellow LEd is on 
	{
		TCNT1=0; // Timer =0 and start count from zero
		localcounter=0;// =0  To count five seconds from the first
        /*
		in normal mode 
		- Yellow Led off 
		- Red Led on
		*/
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN1,MDIO_u8_PIN_LOW);
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN2,MDIO_u8_PIN_HIGH);
		/*
		in pedeDstrian  mode 
		- Yellow Led off  
		- green Led on
		*/
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN1,MDIO_u8_PIN_LOW);
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN0,MDIO_u8_PIN_HIGH);
		
		
		
	}
	else if (PINA_REG&(1<<2)) // if Red LEd is on 
	{
		TCNT1=0; // Timer =0 and start count from zero
		localcounter=0; // =0  To count five seconds from the first
        /*
		in normal mode 
		-  Green on 
		- Red Led off
		*/
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN2,MDIO_u8_PIN_LOW);
		MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN0,MDIO_u8_PIN_HIGH);
		/*
		in pedeDstrian  mode 
		- Red on 
		- green Led off
		*/
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN2,MDIO_u8_PIN_HIGH);
		MDIO_u8SetPinValue(MDIO_u8_PORTC,MDIO_u8_PIN0,MDIO_u8_PIN_LOW);
		
		
	}
}
/**********************************************************************************************/

