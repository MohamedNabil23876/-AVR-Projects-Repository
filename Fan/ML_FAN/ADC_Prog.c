/*
 * ADC_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_ERR.h"


#include "ADC_interface.h"
#include "ADC_cfg.h"
#include "ADC_prv.h"
#include "ADC_reg.h"




void ADC_voidInit(void)
{
	/* AVCC as refrence volatge*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLEAR_BIT(ADMUX,ADMUX_REFS1);

	/* Active left Adjust Result */
	SET_BIT(ADMUX,ADMUX_ADLAR);



	/* SET prescaler to divide by 128 */
	ADCSRA &= ADCSRA_MASK ;
	ADCSRA |= ADC_PRESC_MASK ;

	/* Enable ADC */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8GetChannelRead(u8 Copy_u8Cahannel)
{
	/* set the requist channel */
	ADMUX &= ADMUX_CHANNEL_MASK;
	ADMUX |= Copy_u8Cahannel ;

	/* start Conversion */
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/* Polling (pusy waiting )*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);

	/* clear flag */
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/* return the reading */
	return 	ADCH ;
}

