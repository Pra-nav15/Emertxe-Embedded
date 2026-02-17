/*
 * File:   timer0.c
 * Author: PRANAV
 *
 * Created on February 12, 2026, 7:44 AM
 */

#include <xc.h>
#include"dynamic_clock.h"

void init_timer0(void)
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    T0CONbits.T08BIT = 1;
    T0CONbits.T0CS = 0;
    T0CONbits.PSA = 1;
    TMR0 = 6;
    TMR0IF = 0;
    TMR0IE = 1;
    T0CONbits.TMR0ON = 1;
}
