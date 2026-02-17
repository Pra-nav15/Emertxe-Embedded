/*
 * File:   timer1.c
 * Author: PRANAV
 *
 * Created on February 6, 2026, 8:22 AM
 */


#include <xc.h>
#include "time_seperator.h"

void init_timer1(void)
{
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1CKPS1 = 0;
    T1CONbits.T1CKPS0 = 0;
    TMR1 = 3036;
    TMR1IF = 0;
    TMR1IE = 1;
    T1CONbits.TMR1ON = 1;
}