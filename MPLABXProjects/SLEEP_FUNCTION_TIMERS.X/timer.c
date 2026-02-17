/*
 * File:   timer.c
 * Author: PRANAV
 *
 * Created on February 4, 2026, 10:46 AM
 */


#include <xc.h>

void init_timer0(void)
{
    TRISBbits.TRISB0 = 1;
    INTCONbits.INT0IF = 0;
    INTCONbits.INT0IE = 1;
    INTCON2bits.INTEDG0 = 0;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    TMR0 = 6;
    T0CONbits.T08BIT = 1;
    T0CONbits.T0CS = 0;
    T0CONbits.TMR0ON = 1;
    TMR0IF = 0;
    TMR0IE = 1;
}