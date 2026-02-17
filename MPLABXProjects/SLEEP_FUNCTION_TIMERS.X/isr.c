/*
 * File:   isr.c
 * Author: PRANAV
 *
 * Created on February 4, 2026, 9:36 AM
 */


#include <xc.h>
#include"sleep_and_wake.h"
#define _XTAL_FREQ 20000000

volatile unsigned int idle_count=0;
volatile unsigned char minute_count = 0;
volatile unsigned char interrupt_pressed = 0;

void __interrupt() isr(void)
{
    if (INTCONbits.INT0IF == 1)
    {
        interrupt_pressed = 1;        
        INTCONbits.INT0IF = 0;
    }   
    if(TMR0IF == 1)
    {
        TMR0IF=0;
        idle_count++;
        if(idle_count == 10000)
        {
          LED_PORT ^= 0x80;  
        }
        if(idle_count == 20000)
        {
            LED_PORT ^= 0x80;
            minute_count++;
            idle_count=0;
        }
        TMR0=TMR0+8;
    }
}
