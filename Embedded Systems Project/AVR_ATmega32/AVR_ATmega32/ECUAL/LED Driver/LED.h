/*
 * LED.h
 *
 * Created: 7/31/2022 1:55:18 PM
 *  Author: tokam
 */ 


#ifndef LED_H_
#define LED_H_

//includes
#include "../../MCAL/DIO Driver/DIO.h"
#include "../../MCAL/Timer Driver/timer.h"
#include "../../MCAL/Interrupt Driver/Interrupt.h"

//Typedefs

//Macros

//Prototypes
void LED_init(uint8 ledPort, uint8 ledPin);
void LED_on(uint8 ledPort, uint8 ledPin);
void LED_off(uint8 ledPort, uint8 ledPin);
void LED_toggle(uint8 ledPort, uint8 ledPin);

#endif /* LED_H_ */