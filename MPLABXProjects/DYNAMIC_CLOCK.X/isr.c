/*
 * File:   isr.c
 * Author: PRANAV
 *
 * Created on February 12, 2026, 7:46 AM
 */

#include <xc.h>
#include "dynamic_clock.h"

unsigned int idle_halfsec_count=0;
unsigned int idle_sec_count=0;
unsigned char half_sec_flag = 0;
unsigned char sec_flag = 0;
unsigned char sec_count = 0;

void __interrupt() isr(void)
{ 
    if(TMR0IF == 1)
    {
        TMR0IF=0;
        TMR0 = 6;
        if(idle_halfsec_count == 5000)
        {
            half_sec_flag = !half_sec_flag;
            idle_halfsec_count = 0;
        }
        if(idle_sec_count == 20000)
        {
            idle_sec_count = 0;
            sec_count++;
        }
        if(sec_count > 59)
        {
            sec_flag=1;
            sec_count=0;
        }
        idle_halfsec_count++;
        idle_sec_count++;
        TMR0=TMR0+8;
    }
}