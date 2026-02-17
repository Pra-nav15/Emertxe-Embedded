/*
 * File:   timer0.c
 * Author: PRANAV
 *
 * Created on February 6, 2026, 8:19 AM
 */


#include <xc.h>
#include "time_seperator.h"

void init_timer0(void)
{
    T0CONbits.T08BIT = 1;
    T0CONbits.T0CS = 0;
    T0CONbits.PSA = 1;
    TMR0 = 6;
    TMR0IF = 0;
    TMR0IE = 1;
//    T0CONbits.T0PS0= 0;
//    T0CONbits.T0PS1= 0;
//    T0CONbits.T0PS2= 0;
    T0CONbits.TMR0ON = 1;
}

