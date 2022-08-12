/*
 * button.c
 *
 * Created: 7/31/2022 2:45:11 PM
 *  Author: tokam
 */ 

//includes
#include "button.h"

//global variables

//functions definitions
void BUTTON_init(uint8 buttonPort, uint8 buttonPin)
{
	DIO_init(buttonPort, buttonPin, IN);
}

void BUTTON_read(uint8 buttonPort, uint8 buttonPin, uint8 *state)
{
	DIO_read(buttonPort, buttonPin, state);
}
