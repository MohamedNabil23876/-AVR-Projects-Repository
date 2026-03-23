/*
 * UART_prog.c
 *
 *  Created on: Jul 30, 2025
 *      Author: lenovo
 */
#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "lib/ERR_TYPE.h"


#include "UART_interface.h"
#include "UART_reg.h"
#include "UART_prv.h"
#include "UART_cfg.h"


void UART_voidInit(void)
{
	u8 Local_u8UCSRCValue = 0b10000000;

	u16 Local_u16BaudRate = 51 ;
	UBRRL = (u8)Local_u16BaudRate ;
	UBRRH = (u8)(Local_u16BaudRate >> 8);

	/*normal Speed*/
	CLR_BIT(UCSRA,UCSRA_U2X);

	/* Data Size --> b bit*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);


	/* Enable Asyncronus */
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);

	/* no parity bit */
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);

	/* Enable 2 stop bit */
	SET_BIT(Local_u8UCSRCValue,UCSRC_USBS);


	/* update UCSRC */
	UCSRC = Local_u8UCSRCValue ;



	/* Enable TX ,RX*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

}

void UART_voidSendData(u8 Copy_u8Data)
{
	/* wait until the  UDR empty */
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);

	/* Send Data */
	UDR =Copy_u8Data ;

	while(GET_BIT(UCSRA,UCSRA_TXC) == 0);
}

u8  UART_u8ReveiveData(u8 *Copy_pu8Data)
{
	u8 Local_u8ErrorSate = OK ;

	if(Copy_pu8Data != NULL)
	{
		/* wait until the   receive register is complete  */
		while(GET_BIT(UCSRA,UCSRA_RXC) == 0);

		*Copy_pu8Data = UDR ;

	}
	else
	{
		Local_u8ErrorSate = NULL_POINTER ;
	}

	return Local_u8ErrorSate ;
}
