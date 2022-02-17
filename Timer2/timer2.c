/*
 * timer2.c
 *
 * Created: 2/17/2022 10:19:30 AM
 *  Author: User
 */ 
#ifndef F_CPU
#define F_CPU 8e6
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#ifndef BIT(x)
#define BIT(x)			(1 << (x))
#endif

void (*func)(void);

void setTCCR(char val) {
	TCCR2 = val;
}

void setTCNT(char TCNT) {
	TCNT2 = TCNT;
}

void timer2Init(void (*fun)(), int TCNT, char TCCR, char interuptPin) {
	func = (*fun);
	TCNT2 = TCNT; // This is inaccurate. actual value should be 7.812,5.
	TIMSK |= BIT(interuptPin);
	sei();
	TCCR2 = TCCR;
}

ISR (TIMER2_COMP_vect ) {
	func();
}