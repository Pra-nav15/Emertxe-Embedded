/*
 * File:   main.c
 * Author: PRANAV PRASAD
 * Description: 
 *
 * Created on February 4, 2026, 8:52 AM
 */


#include <xc.h>
#include "sleep_and_wake.h"

static unsigned char ssd[SSD_COUNT];
static unsigned char digit[] = {BLANK, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

void init_config(void)
{
    init_digital_keypad();
    init_led_config();
    init_ssd_display();
    init_timer0();
}

void init_led_config(void)
{
    TRISB = 0x01;
    LED_PORT = 0x00;
}

void main(void)
{
    init_config();
    unsigned char key;
    unsigned int count=1234;
    while (1)
    {
        key = read_digital_keypad(EDGE);
        if (key != ALL_RELEASED)
        {
            minute_count = 0;  
        }
        else if(key == SWITCH1 || key == SWITCH2 || key == SWITCH3 || key == SWITCH4)
        {
            minute_count = 5;
        }
        if(interrupt_pressed)
        {
           interrupt_pressed = 0;
           minute_count = 0;
        }
        if (minute_count == 5)
        {   
            minute_count = 0;
            ssd[0] = digit[(count / 1000) % 10];
            ssd[1] = digit[(count / 100) % 10];
            ssd[2] = digit[(count / 10) % 10];
            ssd[3] = digit[count % 10];
            display(ssd);
            SLEEP(); 
        }
        else
        {
            ssd[0] = digit[(count / 1000) % 10];
            ssd[1] = digit[(count / 100) % 10];
            ssd[2] = digit[(count / 10) % 10];
            ssd[3] = digit[count % 10];
            display(ssd);
        }
    }
        
}