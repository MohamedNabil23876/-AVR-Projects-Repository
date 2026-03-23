/*
 * GIE_prog.c
 *
 *  Created on: Jul 23, 2025
 *      Author: lenovo
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_reg.h"


void GIE_voidEnable(void)
{
	// SET_BIT(SREG,SREG_I);
	__asm volatile ("SEI");
}

void GIE_voidDisable(void)
{
	// CLR_BIT(SREG,SREG_I);
	__asm volatile ("CLI");
}
