/*
 * registers.h
 *
 * Created: 7/29/2022 4:32:08 PM
 *  Author: tokam
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

//DIO
#define PORTA	*((vuint8 *)0x3B)
#define DDRA	*((vuint8 *)0x3A)
#define PINA	*((vuint8 *)0x39)

#define PORTB	*((vuint8 *)0x38)
#define DDRB	*((vuint8 *)0x37)
#define PINB	*((vuint8 *)0x36)

#define PORTC	*((vuint8 *)0x35)
#define DDRC	*((vuint8 *)0x34)
#define PINC	*((vuint8 *)0x33)

#define PORTD	*((vuint8 *)0x32)
#define DDRD	*((vuint8 *)0x31)
#define PIND	*((vuint8 *)0x30)

//Timers
#define TCCR0	*((vuint8 *)0x53)
#define TCNT0 	*((vuint8 *)0x52)

#define TIFR 	*((vuint8 *)0x58)
#define TIMSK 	*((vuint8 *)0x59)

#define TCCR2	*((vuint8 *)0x45)
#define TCNT2 	*((vuint8 *)0x44)

//Interrupts
#define SREG 	*((vuint8 *)0x5F) //Status Register
#define MCUCR 	*((vuint8 *)0x55)
#define MCUCSR 	*((vuint8 *)0x54)
#define GICR 	*((vuint8 *)0x5B)

//ADC
#define ADMUX	*((vuint8 *)0x27) //ADC Multiplexer Selection Register
#define ADCSRA 	*((vuint8 *)0x26) //ADC Control and Status Register A
#define ADCH 	*((vuint8 *)0x25) //ADC Data Register – ADCL and ADCH
#define ADCL 	*((vuint8 *)0x24)

//Bit operations
#define SET_BIT(REG_NAME, BIT_NO) REG_NAME|=(1<<BIT_NO)
#define CLR_BIT(REG_NAME, BIT_NO) REG_NAME&=~(1<<BIT_NO)
#define READ_BIT(REG_NAME, BIT_NO) ((REG_NAME&(1<<BIT_NO))>>BIT_NO)
#define TOGGLE_BIT(REG_NAME, BIT_NO) REG_NAME^=(1<<BIT_NO)

#endif /* REGISTERS_H_ */