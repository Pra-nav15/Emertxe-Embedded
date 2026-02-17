/*
 * File:   digital_keypad.c
 * Author: PRANAV
 *
 * Created on February 2, 2026, 9:48 AM
 */


#include <xc.h>
#include"digital_key_press.h"

void init_digital_keypad(void)
{
    TRISC = TRISC | INPUT_PINS;
}

unsigned char read_digital_keypad(unsigned char type)
{
    if(type == LEVEL)
    {
        return KEY_PORT & INPUT_PINS;
    }
    else
    {
        return 0x0F;  // no switch is pressed
    }
}
