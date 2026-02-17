/*
 * File:   main.c
 * Author: PRANAV
 * Description: This project implements a marquee-style scrolling display on SSDs.
 *              A numeric message consisting of digits and leading spaces is stored in the program. 
 *              Upon power-up or reset, the message scrolls from right to left across the SSDs. 
 *              The scrolling repeats indefinitely and is controlled using a non-timer-based software delay to achieve an approximate frequency of 0.5 Hz
 * Created on February 5, 2026, 6:20 PM
 */


#include <xc.h>
#include "ssd_control.h"

static unsigned char ssd[SSD_COUNT];
static unsigned char digit[] = {SPACE, SPACE, SPACE, ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
static void init_config(void)
{
    init_ssd_display();
    init_digital_keypad();
}

void main(void)
{
    init_config();
    unsigned int count = 0;
    unsigned long delay = 0;
    unsigned char key;
    while(1)
    {
        key = read_digital_keypad(EDGE); //edge triggering return which switches is pressed
		if(key != ALL_RELEASED) // if any switch is pressed
        {
            switch(key)
            {
                case SWITCH1: //if switch 1 is pressed
                {
                    if(delay++ == 100000)
                    {
                        ssd[0]= digit[count/1000 % 10];
                        ssd[0]= digit[count/100 % 10];
                        ssd[0]= digit[count/10 % 10];
                        ssd[0]= digit[count/1 % 10];
                        display_left(ssd);
                        delay=0;
                    }
                }
                case SWITCH2: // if switch 2 is pressed
                {
                    if(delay++ == 100000)
                    {
                        ssd[0]= digit[count/1000 % 10];
                        ssd[0]= digit[count/100 % 10];
                        ssd[0]= digit[count/10 % 10];
                        ssd[0]= digit[count/1 % 10];
                        display_right(ssd);
                        delay=0;
                    }
                }
            }
        }
    }
}

