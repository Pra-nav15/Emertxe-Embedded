/*
 * File:   isr.c
 * Author: PRANAV
 *
 * Created on February 6, 2026, 8:16 AM
 */


#include <xc.h>
#include "time_seperator.h"

void __interrupt() isr(void)
{
   static unsigned int count_timer0=0;
   static unsigned int count_timer1=0;
   static unsigned int count_timer2=0;
   if(TMR0IF == 1)
   {
       TMR0IF = 0;
       TMR0 = 6;
       count_timer0++;
       if(count_timer0 == 10000)
       {
           count_timer0 = 0;
           PORTB = PORTB ^ 0x01;
       }
       TMR0 +=8;
   }
   if(TMR1IF == 1)
   {
       TMR1IF = 0;
       TMR1 = 3038;
       count_timer1++;
       if(count_timer1 == 40)
       {
           count_timer1 = 0;
           PORTB = PORTB ^ 0x02;
       }
   }
   if(TMR2IF == 1)
   {
       TMR2IF = 0;
       count_timer2++;
       if(count_timer2 == 10000)
       {
           count_timer2 = 0;
           PORTB = PORTB ^ 0x04;
       }
   }
}
