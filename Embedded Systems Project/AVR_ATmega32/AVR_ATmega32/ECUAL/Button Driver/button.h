/*
 * button.h
 *
 * Created: 7/31/2022 2:45:28 PM
 *  Author: tokam
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

//includes
#include "../../MCAL/DIO Driver/DIO.h"
#include "../../MCAL/Timer Driver/timer.h"
#include "../../MCAL/Interrupt Driver/Interrupt.h"

//Typedefs

//Macros

//Prototypes
void BUTTON_init(uint8 buttonPort, uint8 buttonPin);
void BUTTON_read(uint8 buttonPort, uint8 buttonPin, uint8 *state);

#endif /* BUTTON_H_ */