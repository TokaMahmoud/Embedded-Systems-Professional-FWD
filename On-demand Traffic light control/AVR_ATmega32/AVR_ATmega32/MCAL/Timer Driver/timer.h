/*
 * timer.h
 *
 * Created: 8/8/2022 7:48:44 PM
 *  Author: tokam
 */ 


#ifndef TIMER_H_
#define TIMER_H_

//includes
#include "../../Utilities/registers.h"

//Typedefs

//Macros
#define  NUMBUR_OF_OVERFLOWS 20 

//Prototypes
void timer_init(void);
void delay_5sec(void);
void timer_init_t2(void);
void delay_5sec_t2(void);

#endif /* TIMER_H_ */