/*
 * Interrupt.h
 *
 * Created: 8/9/2022 3:58:10 PM
 *  Author: tokam
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

//includes
#include "../../Utilities/registers.h"

//Typedefs

//Macros
//Interrupts Vectors
#define EXT_INT0 __vector_1
#define EXT_INT1 __vector_2
#define EXT_INT3 __vector_3

#define  ISR(INT_VECT) void INT_VECT(void)__attribute__((signal, used));\
void INT_VECT(void)
/*
ISR(EXT_INT0) -->

void EXT_INT0(void)__attribute__((signal, used));
void EXT_INT0(void)  -->

void __vector_1(void)__attribute__((signal, used));
void __vector_1(void)
*/

//Prototypes
void interrupt_init(void);

#endif /* INTERRUPT_H_ */