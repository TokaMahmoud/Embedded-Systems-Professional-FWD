/*
 * DIO.c
 *
 * Created: 7/29/2022 5:49:35 PM
 *  Author: tokam
 */ 

//includes
#include "DIO.h"

//global variables

//functions definitions
void DIO_init(uint8 portNumber, uint8 pinNumber, uint8 direction)
{
	switch(portNumber)
	{
		case PORT_A:
			if (direction == IN)
			{
				CLR_BIT(DDRA, pinNumber);
			}
			else if (direction == OUT)
			{
				SET_BIT(DDRA, pinNumber);
			}
			else
			{
				//Error handling
			}
		break;
		
		case PORT_B:
			if (direction == IN)
			{
				CLR_BIT(DDRB, pinNumber);
			}
			else if (direction == OUT)
			{
				SET_BIT(DDRB, pinNumber);
			}
			else
			{
				//Error handling
			}
		break;
		
		case PORT_C:
		if (direction == IN)
		{
			CLR_BIT(DDRC, pinNumber);
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRC, pinNumber);
		}
		else
		{
			//Error handling
		}
		break;
		
		case PORT_D:
		if (direction == IN)
		{
			CLR_BIT(DDRD, pinNumber);
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRD, pinNumber);
		}
		else
		{
			//Error handling
		}
		break;
	}
}

void DIO_write(uint8 portNumber, uint8 pinNumber, uint8 value)
{
	switch(portNumber)
	{
		case PORT_A:
		if (value == LOW)
		{
			CLR_BIT(PORTA, pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTA, pinNumber);
		}
		else
		{
			//Error handling
		}
		break;
		
		case PORT_B:
		if (value == LOW)
		{
			CLR_BIT(PORTB, pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTB, pinNumber);
		}
		else
		{
			//Error handling
		}
		break;
		
		case PORT_C:
		if (value == LOW)
		{
			CLR_BIT(PORTC, pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTC, pinNumber);
		}
		else
		{
			//Error handling
		}
		break;
		
		case PORT_D:
		if (value == LOW)
		{
			CLR_BIT(PORTD, pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTD, pinNumber);
		}
		else
		{
			//Error handling
		}
		break;
	}
}

void DIO_toggle(uint8 portNumber, uint8 pinNumber)
{
	uint8 value;
	
	DIO_read(portNumber, pinNumber, &value);
	if (value == LOW)
	{
		DIO_write(portNumber, pinNumber, HIGH);
	}
	else if (value == HIGH)
	{
		DIO_write(portNumber, pinNumber, LOW);
	}
	else
	{
		//Error handling
	}
}

void DIO_read(uint8 portNumber, uint8 pinNumber, uint8 *value)
{
	switch(portNumber)
	{
		case PORT_A:
		*value = READ_BIT(PINA, pinNumber);
		break;
		
		case PORT_B:
		*value = READ_BIT(PINB, pinNumber);
		break;
		
		case PORT_C:
		*value = READ_BIT(PINC, pinNumber);
		break;
		
		case PORT_D:
		*value = READ_BIT(PIND, pinNumber);
		break;
		
		default:
		////Error handling
		break;
	}
}
