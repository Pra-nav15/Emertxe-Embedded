/*
 * File:   isr.c
 * Author: PRANAV
 *
 * Created on February 10, 2026, 9:42 AM
 */

#include <xc.h>
#include"ssd_display.h"

unsigned int idle_halfsec_count=0;
unsigned int idle_fullsec_count=0;
unsigned char half_sec_flag = 0;
unsigned char one_sec_flag = 0;
unsigned char one_sec_count = 0;

void __interrupt() isr(void)
{ 
    if(TMR0IF == 1)
    {
        TMR0IF=0;
        idle_halfsec_count++;
        idle_fullsec_count++;
        if(idle_halfsec_count == 5000)
        {
            half_sec_flag= !half_sec_flag;
            idle_halfsec_count = 0;
        }
        if(idle_fullsec_count == 20000)
        {
            one_sec_count++;
            idle_fullsec_count = 0;
        }
        if(one_sec_count > 59)
        {
            one_sec_flag=1;
            one_sec_count=0;
        }
        TMR0=TMR0+8;
    }
}