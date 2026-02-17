/*
 * File:   read_digital_keypad.c
 * Author: PRANAV
 *
 * Created on February 5, 2026, 6:21 PM
 */


#include <xc.h>
#include"ssd_control.h"

void init_digital_keypad(void)
{
    TRISC = TRISC | INPUT_PINS;
}

unsigned char read_digital_keypad(unsigned char type)
{
    static unsigned char once = 0;
    if(type == LEVEL)
    {
        return KEY_PORT & INPUT_PINS;
    }
    else if(type == EDGE)
    {
        if((KEY_PORT & INPUT_PINS) != ALL_RELEASED && once)
        {
            once=0;
            return KEY_PORT & INPUT_PINS;
        }
        else if((KEY_PORT & INPUT_PINS) != ALL_RELEASED)
        {
            once=1;
        }
    }
    else
    {
        return ALL_RELEASED;
    }
}



