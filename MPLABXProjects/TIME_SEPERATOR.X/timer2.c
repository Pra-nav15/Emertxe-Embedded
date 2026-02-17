/*
 * File:   timer2.c
 * Author: PRANAV
 *
 * Created on February 6, 2026, 8:24 AM
 */


#include <xc.h>
#include "time_seperator.h"

void init_timer2(void)
{
    PR2 = 249;
    T2CKPS0 = 0;
    T2CKPS1 = 0;
    TMR2 = 0;
    TMR2IF = 0;
    TMR2IE = 1;
    T2CONbits.TMR2ON = 1;
}
