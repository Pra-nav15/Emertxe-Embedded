/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on January 22, 2026, 8:25 AM
 */


#include <xc.h>

void main(void) 
{
    TRISB = 0x00;
    PORTB = 0x0F;
    
    unsigned long delay=0;
    while(1)
    {
        if(delay++ == 1000000)
        {
            PORTB=~(PORTB);
            delay=0;
        }
    }
    
}
