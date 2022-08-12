/*
 * LED.c
 *
 * Created: 7/31/2022 1:55:36 PM
 *  Author: tokam
 */ 

//includes
#include "LED.h"

//global variables

//functions definitions
void LED_init(uint8 ledPort, uint8 ledPin)
{
	DIO_init(ledPort, ledPin, OUT);
}

void LED_on(uint8 ledPort, uint8 ledPin)
{
	DIO_write(ledPort,ledPin, HIGH);
}

void LED_off(uint8 ledPort, uint8 ledPin)
{
	DIO_write(ledPort,ledPin, LOW);
}

void LED_toggle(uint8 ledPort, uint8 ledPin)
{
	DIO_toggle(ledPort,ledPin);
}
