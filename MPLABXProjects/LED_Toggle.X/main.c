/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on January 20, 2026, 10:02 AM
 */

#include <xc.h>
#define _XTAL_FREQ 20000000
void main(void) 
{
    TRISB = 0x00; //make PORTB as o/p
    PORTB = 0x00; // All LEDs off
    while(1)
    {
        PORTB=~PORTB; //All LEDs OFF and ON Toggle
        //for(unsigned long wait = 150000;wait--;);
        __delay_ms(1000);
    }
}
