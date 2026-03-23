/*
 * DIO_Config.h
 *
 * Created: 09/09/2022 02:14:08 
 *  Author: nabil
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_


/* Pin Direction  macros  */
#define	 MDIO_u8_PIN_INPUT       0     /*pin Input */
#define	 MDIO_u8_PIN_OUTPUT	     1	  /*pin  Output */
#define  MDIO_u8_PIN_PULLUP	     1    /*internal pull up*/



/*  Port Direction Macros  */
#define  MDIO_u8_PORT_INPUT     0           /*port state Input */
#define MDIO_u8_PORT_OUTPUT   	0xff        /*port state output  */





/*  Pin Value Macros */
#define	MDIO_u8_PIN_LOW	      0	   /* pin state Low  */
#define	MDIO_u8_PIN_HIGH	  1   /*pin state High  */






/*  Port Value Macros  */
#define	MDIO_u8_PORT_LOW       0      /*port state low  */
#define	MDIO_u8_PORT_HIGH	   0xFF   /*port state high */







/************************* MDIO PINS MACROS   ************************/
#define	MDIO_u8_PIN0        0   		/*If  Pin 0*/
#define	MDIO_u8_PIN1		1			/*If  Pin 1*/
#define	MDIO_u8_PIN2		2			/*If  Pin 2*/
#define	MDIO_u8_PIN3		3			/*If  Pin 3*/
#define	MDIO_u8_PIN4		4			/*If  Pin 4*/
#define	MDIO_u8_PIN5		5			/*If  Pin 5*/
#define	MDIO_u8_PIN6		6			/*If  Pin 6*/
#define	MDIO_u8_PIN7		7			/*If  Pin 7*/
/*********************************************************************/




/************************* MDIO PORT MACROS   ************************/
#define MDIO_u8_PORTA  		0
#define MDIO_u8_PORTB  		1
#define MDIO_u8_PORTC  		2
#define MDIO_u8_PORTD 		3
/*********************************************************************/



#endif /* DIO_CONFIG_H_ */