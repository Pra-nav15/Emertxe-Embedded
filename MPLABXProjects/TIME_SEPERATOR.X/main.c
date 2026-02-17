/*
 * File:   main.c
 * Author: PRANAV PRASAD
 * Description: This project uses Timer0, Timer1, and Timer2 to generate a digital clock time separator, 
 *              where each timer drives a dedicated LED that toggles at 0.5 Hz (every 500 ms) immediately after power-on or reset.
 *              All timers are configured with the same clock source, pre scaler, and compare values, and are initialized simultaneously to ensure perfect synchronization, 
 *              guaranteeing that the LEDs blink in unison without drift even during extended operation.

 * Created on February 6, 2026, 8:13 AM
 */


#include <xc.h>
#include "time_seperator.h"

void init_config(void)
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    init_led_config();
    init_timer0();
    init_timer1();
    init_timer2();
}

void main(void)
{
    init_config();
    while(1);
}