/*
 * App.c
 *
 * Created: 8/11/2022 3:54:21 PM
 *  Author: tokam
 */ 
#include "App.h"

uint8 state;

void App_init(void)
{
	LED_init(PORT_A, 0); //cars' Green LED
	LED_init(PORT_A, 1); //cars' Yellow LED
	LED_init(PORT_A, 2); //cars' Red LED
	
	LED_init(PORT_B, 0); //pedestrian's Green LED
	LED_init(PORT_B, 1); //pedestrian Yellow LED
	LED_init(PORT_B, 2); //pedestrian Red LED
	
	BUTTON_init(PORT_D, 2); //pedestrian button
	interrupt_init();
}

void  normal_mode(void)
{
	//Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
	state = 1;
	LED_on(PORT_A, 0); //cars' Green LED
	delay_5sec_t2();
	LED_off(PORT_A, 0);
		
	//Yellow LED will blink for five seconds before moving to Green or Red LEDs.
	uint16 overflowCounter = 0;
	timer_init_t2();
	while(overflowCounter < NUMBUR_OF_OVERFLOWS)
	{
		while(READ_BIT(TIFR, 6) == 0)
		LED_toggle(PORT_A,1); //cars' Yellow LED
		//clear the flag
		SET_BIT(TIFR, 6);
		overflowCounter++;
	}
	LED_off(PORT_A,1);
	//Stop timer
	TCCR2 = 0x00;
		
	state=0;
	LED_off(PORT_A, 0); //cars' Green LED
	LED_on(PORT_A, 2); //cars' Red LED
	delay_5sec_t2();
	LED_off(PORT_A, 2);
	
}

void pedestrian_mode(void)
{
	switch(state)
	{
		//---------------------If pressed when the cars' Red LED is on,--------------
		case 0:
		//1. pedestrian's Green LED and the cars' Red LEDs will be on for five seconds
		LED_on(PORT_B, 0); //pedestrian's Green LED
		LED_on(PORT_A, 2); //cars' Red LED
		delay_5sec();
		
		break;
		
		//---------------If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking-----------------
		case 1:
		//1.the pedestrian Red LED will be on
		LED_on(PORT_B, 2); //pedestrian Red LED
		
		//2.both Yellow LEDs start to blink for five seconds
		uint16 overflowCounter = 0;
		timer_init();
		while(overflowCounter < NUMBUR_OF_OVERFLOWS)
		{
			while(READ_BIT(TIFR, 0) == 0)
			{
				LED_toggle(PORT_A,1); //cars' Yellow LED
				LED_toggle(PORT_B, 1); //pedestrian Yellow LED
			}
			
			//clear the flag
			SET_BIT(TIFR, 0);
			overflowCounter++;
		}
		LED_off(PORT_A,1); //cars' Yellow LED
		LED_off(PORT_B, 1); //pedestrian Yellow LED
		//Stop timer
		TCCR0 = 0x00;
		
		LED_off(PORT_B, 2); //pedestrian Red LED
		LED_off(PORT_A, 0); //cars' Green LED
		
		//3. the cars' Red LED and pedestrian Green LEDs are on for five seconds
		LED_on(PORT_A, 2); //cars' Red LED
		LED_on(PORT_B, 0); //pedestrian's Green LED
		delay_5sec();
		
		break;
		
		default:
		//ERORR
		break;
	}
	
	
	//------------------------ At the end of the two states ------------------------------------------
	
	//1. the cars' Red LED will be off
	LED_off(PORT_A, 2); //cars' Red LED
	
	//2.both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
	uint16 overflowCounter = 0;
	timer_init();
	while(overflowCounter < NUMBUR_OF_OVERFLOWS)
	{
		while(READ_BIT(TIFR, 0) == 0)
		{
			LED_toggle(PORT_A,1); //cars' Yellow LED
			LED_toggle(PORT_B, 1); //pedestrian Yellow LED
		}
		
		//clear the flag
		SET_BIT(TIFR, 0);
		overflowCounter++;
	}
	LED_off(PORT_A,1); //cars' Yellow LED
	LED_off(PORT_B, 1); //pedestrian Yellow LED
	//Stop timer
	TCCR0 = 0x00;
	
	//3.After the five seconds the pedestrian Green LED will be off
	LED_off(PORT_B, 0); //pedestrian's Green LED
	
	//4.both the pedestrian Red LED and the cars' Green LED will be on.
	LED_on(PORT_B, 2); //pedestrian Red LED
	LED_on(PORT_A, 0); //cars' Green LED
	
	//5. Traffic lights signals are going to the normal mode again.
	delay_5sec();
	LED_off(PORT_B, 2); //pedestrian Red LED
	if(state == 0) //pressed when the cars' Red LED is on
	{
		LED_off(PORT_A, 0); //cars' Green LED
		LED_on(PORT_A, 2); //cars' Red LED
	}
}

ISR(EXT_INT0)
{
	
	pedestrian_mode();
	
}