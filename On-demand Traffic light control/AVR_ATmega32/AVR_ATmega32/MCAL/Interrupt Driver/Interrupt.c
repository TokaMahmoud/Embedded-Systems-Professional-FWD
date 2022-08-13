/*
 * Interrupt.c
 *
 * Created: 8/9/2022 3:57:57 PM
 *  Author: tokam
 */ 

#include "Interrupt.h"

void interrupt_init(void)
{
	//Enable global interrupt
	SET_BIT(SREG, 7);
	
	//Choose the external interrupt sense
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);	//The rising edge of INT0 generates an interrupt request
	
	//Enable INT0
	SET_BIT(GICR, 6);
}