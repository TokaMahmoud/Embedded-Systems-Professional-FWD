/*
 * timer.c
 *
 * Created: 8/8/2022 7:48:57 PM
 *  Author: tokam
 */ 

#include "timer.h"

void timer_init(void)
{
	//Timer initial value
	TCNT0 = 12;
	//Timer mode
	TCCR0 = 0x05; //Normal mode & clk/1024 (From prescaler)
}

void delay_5sec(void)
{
	uint16 overflowCounter = 0;
	
	timer_init();
	while(overflowCounter < NUMBUR_OF_OVERFLOWS)
	{
		while(READ_BIT(TIFR, 0) == 0);
		
		//clear the flag
		SET_BIT(TIFR, 0);
		overflowCounter++;
	}
	
	//Stop timer
	TCCR0 = 0x00;
}

void timer_init_t2(void)
{
	//Timer initial value
	TCNT2 = 12;
	//Timer mode
	TCCR2 = 0x07; //Normal mode & clk/1024 (From prescaler)
}

void delay_5sec_t2(void)
{
	uint16 overflowCounter = 0;
	
	timer_init_t2();
	while(overflowCounter < NUMBUR_OF_OVERFLOWS)
	{
		while(READ_BIT(TIFR, 6) == 0);
		
		//clear the flag
		SET_BIT(TIFR, 6);
		overflowCounter++;
	}
	
	//Stop timer
	TCCR2 = 0x00;
}

