/*
 * GIE_Prog.c
 *
 *  Created on: Jun 22, 2025
 *      Author: HP
 */
#include "../STD_TYPES.h"
#include "../BIT_MATH.h"

#include "GIE_Interface.h"
#include "GIE_Reg.h"

void GIE_VoidEnable(void)
{
	//SET_BIT(SREG,SREG_I);

	__asm volatile ("SEI");
}
void GIE_VoidDisable(void)
{
   //CLR_BIT(SREG,SREG_I);
	__asm volatile ("CLI");

}
