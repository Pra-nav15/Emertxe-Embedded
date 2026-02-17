/*
 * File:   main.c
 * Author: Pranav Prasad
 * Description: This project controls eight LEDs connected to PORTB of a PIC microcontroller. 
 *              The LEDs glow in a running pattern from left to right and right to left. 
 *              Each direction includes LED ON and OFF sequences. 
 *              The pattern is generated using bitwise shift operations and a software delay, without using hardware timers
 * Created on January 21, 2026, 8:45 AM
 */


#include <xc.h>

void main(void) 
{
    TRISB = 0x00;
    PORTB = 0x00;

    unsigned int i = 0;
    unsigned long delay=0;

    while(1)
    {
        if(delay++ == 100000)
        {
            if(i < 8)
            {
                PORTB = (PORTB << 1) | 0x01;
            }
            else if(i < 16)
            {
                PORTB = PORTB << 1;
            }
            else if(i < 24)
            {
                PORTB = (PORTB >> 1) | 0x80;
            }
            else if(i < 32)
            {
                PORTB = (PORTB >> 1);
            }
            else
            {
                i=0;
            }
            delay=0;
            i++;
        }
    }
}
