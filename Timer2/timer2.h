/*
 * timer2.h
 *
 * Created: 2/17/2022 10:31:14 AM
 *  Author: User
 */ 
#ifndef TIMER2_H
void setTCCR(char val);
void setTCNT(char TCNT);
void timer2Init(void (*fun)(), int TCNT, char TCCR, char interuptPin);
#endif
