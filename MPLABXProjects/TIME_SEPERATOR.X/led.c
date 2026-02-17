/*
 * File:   led.c
 * Author: PRANAV
 *
 * Created on February 6, 2026, 8:15 AM
 */


#include <xc.h>
#include "time_seperator.h"

void init_led_config(void)
{
    TRISB = 0xF8;
    PORTB = 0x07;
}
