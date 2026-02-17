/*
 * File:   main.c
 * Author: Pranav Prasad
 * Description: This project implements a marquee-style scrolling display on SSDs.
 *              A numeric message consisting of digits and leading spaces is stored in the program. 
 *              Upon power-up or reset, the message scrolls from right to left across the SSDs. 
 *              The scrolling repeats indefinitely and is controlled using a non-timer-based software delay to achieve an approximate frequency of 0.5 Hz
 * Created on January 28, 2026, 8:19 AM
 */

#include <xc.h>
#include "ssd_display.h"

static unsigned char ssd[SSD_COUNT];
static unsigned char digit[] = {SPACE, SPACE, SPACE, ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
void init_config(void)
{
	init_ssd_display();
}

void main(void) 
{
    init_config();
    unsigned char d0 = 0;
    unsigned char d1 = 1;
    unsigned char d2 = 2;
    unsigned char d3 = 3;
    
    unsigned long delay = 0;
    while(1)
    {
        ssd[0] = digit[d0];
        ssd[1] = digit[d1];
        ssd[2] = digit[d2];
        ssd[3] = digit[d3];
        display(ssd);
     
        if(delay++ == 100)
        {
            delay = 0;
            d0++;
            d1++;
            d2++;
            d3++;
            if(d3 > 12)
            {
               d3 = 0; 
            }
            if(d2 > 12)
            {
               d2 = 0;
            }
            if(d1 > 12)
            {
               d1 = 0;
            }
            if(d0 > 12)
            {
              d0 = 0;  
            } 
        }
    }
}
