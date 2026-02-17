/*
 * File:   timer2.c
 * Author: PRANAV
 *
 * Created on February 4, 2026, 7:00 PM
 */


#include <xc.h>
#include "clock.h"

void init_timer2(void)
{
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    T2CONbits.TMR2ON = 1;
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 1;
    TMR2 = 0;
    PR2 = 249;
}
