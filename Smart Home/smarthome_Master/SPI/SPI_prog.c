#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "../ERR_TYPE.h"

#include "SPI_interface.h"
#include "SPI_reg.h"
#include "SPI_cfg.h"
#include "SPI_prv.h"



void SPI_voidInit(void)
{
	#if	SPI_MODE ==  SPI_MASTER_MODE
	/* select MASTER */
	SET_BIT(SPCR,SPCR_MSTR);

	/* CLK rate Select --> f/64 */
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	#elif SPI_MODE	==  SPI_SLAVE_MODE

	/* select SLAVE */
	CLR_BIT(SPCR,SPCR_MSTR);

	#else
		#error "wrong SPI_MODE !!!! "
	#endif



	/* MSB if First Transmit */
	CLR_BIT(SPCR,SPCR_DORD);

	/* CLK polarity : Leading Edge : Falling , Trailing Edge : Rising */
	SET_BIT(SPCR,SPCR_CPOL);

	/* CLK Phase : Leading Edge : Setup  , Trailing Edge : Sample */
	SET_BIT(SPCR,SPCR_CPHA);

	/* Enable SPI */
	SET_BIT(SPCR,SPCR_SPE);

}


u8 SPI_u8TransmReceive(u8 Copy_u8SendData ,u8 *Copy_pu8ReceiveData)
{
	u8 Local_u8ErrorState = OK ;
	if(Copy_pu8ReceiveData != NULL)
	{
		/* Send Data */
		SPDR = Copy_u8SendData ;

		/* Check Flag */
		while(GET_BIT(SPSR,SPSR_SPIF) == 0);

		/* Receive Data*/
		*Copy_pu8ReceiveData = SPDR ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;

}
void SPI_voidSendData(u8 Copy_u8SendData)
{
    /* Send Data */
    SPDR = Copy_u8SendData;

    /* Wait until transmission complete */
    while(GET_BIT(SPSR, SPSR_SPIF) == 0);
}


u8 SPI_voidReceiveData(u8 *Copy_pu8ReceiveData)
{
	u8 Local_u8ErrorState = OK ;
	if(Copy_pu8ReceiveData != NULL)
	{

		/* Wait until transmission complete */
		while(GET_BIT(SPSR, SPSR_SPIF) == 0);

		/* Receive Data*/
		*Copy_pu8ReceiveData = SPDR ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;

}
u8 SPI_SlaveReceive(void)
 {
 /* Wait for reception complete */
 while(!(SPSR & (1<<SPSR_SPIF)))
 ;
 /* Return data register */
 return SPDR;
 }

void SPI_MasterTransmit(u8 cData)
 {
 /* Start transmission */
 SPDR = cData;
 /* Wait for transmission complete */
 while(!(SPSR & (1<<SPSR_SPIF)))
 ;
 }
