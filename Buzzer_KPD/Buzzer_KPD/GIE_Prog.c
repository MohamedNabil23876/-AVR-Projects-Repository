/*
 * GIE_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: HP
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GIE_interface.h"
#include"GIE_Reg.h"


void GIE_voidEnable(void){

	SET_BIT(SREG,SREG_I);
	//__asm volatile ("SEI");
}
void GIE_voidDisable(void){

	CLEAR_BIT(SREG,SREG_I);
	//__asm volatile ("CLI");
}

