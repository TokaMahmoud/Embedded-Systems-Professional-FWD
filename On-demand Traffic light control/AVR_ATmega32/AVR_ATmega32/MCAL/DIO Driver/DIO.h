/*
 * DIO.h
 *
 * Created: 7/29/2022 5:49:55 PM
 *  Author: tokam
 */ 


#ifndef DIO_H_
#define DIO_H_

//includes
#include "../../Utilities/registers.h"

//Typedefs

//Macros
#define PORT_A 'A' 
#define PORT_B 'B' 
#define PORT_C 'C' 
#define PORT_D 'D' 
//Direction defines
#define IN 0
#define OUT 1
//Value defines
#define LOW 0
#define HIGH 1

//Prototypes
void DIO_init(uint8 portNumber, uint8 pinNumber, uint8 direction);  //direction
void DIO_write(uint8 portNumber, uint8 pinNumber, uint8 value); 
void DIO_toggle(uint8 portNumber, uint8 pinNumber);
void DIO_read(uint8 portNumber, uint8 pinNumber, uint8 *value);

#endif /* DIO_H_ */