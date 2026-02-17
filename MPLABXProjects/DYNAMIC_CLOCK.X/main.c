/*
 * File:   main.c
 * Author: PRANAV PRASAD
 * Description: This project implements a 24-hour dynamic (configurable) digital  clock  
 *              uses Timer0, and a 4-digit multiplexed Seven Segment Display. 
 *              On power-up or reset, the clock starts at 00.00, and the decimal point of the hour?s one?s digit blinks every 500 ms in run mode. 
 *              Pressing the Set/Edit key enters configuration mode, where the selected field (hour or minute) blinks at 500 ms for indication.
 *              The Choose Field key selects the field, and Increment/Decrement keys modify the selected value in level-triggered mode.
 *              Pressing Set/Edit again exits configuration mode and resumes normal clock operation.
 *
 * Created on February 12, 2026, 7:37 AM
 */

#include <xc.h>
#include "dynamic_clock.h"

static unsigned char ssd[SSD_COUNT];
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
static void init_config(void)
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    init_timer0();
    init_ssd_display();
    init_digital_keypad();
}

void main(void)
{
    init_config();
    unsigned char key;
    unsigned char mode = 0;
    unsigned char field =0;
    unsigned char hour = 0;
    unsigned char minutes = 0;
    unsigned char dp_flag = 0;
    unsigned char delay = 0;
    while(1)
    {
        key=read_digital_keypad(LEVEL);
        if(key == SWITCH4)
        {
            mode= !mode;
        }
        if(mode == 1)
        {
            if(key == SWITCH3)
            {
                field = !field;
            }
            else if(key == SWITCH2)
            {
                if(field == 0)
                {
                    if(delay++ > 20)
                    {
                        if(minutes == 0)
                        {
                            minutes = 59;
                        }
                        else
                        {
                            minutes--;
                        }
                        delay=0;
                    }
                }
                else
                {
                    if(delay++ > 20)
                    {
                        if(hour == 0)
                        {
                            hour= 23;
                        }
                        else
                        {
                           hour--;
                        }
                        delay=0;
                    }
                }
            }
            else if(key == SWITCH1)
            {
                if(field == 0)
                {
                   if(delay++ > 20)
                    {
                        minutes++;
                        if(minutes > 59)
                        {
                            minutes=0;
                        }
                        delay=0;
                    }
                }
                else
                {
                    if(delay++ > 20)
                    {
                        hour++;
                        if(hour > 23)
                        {
                            hour=0;
                        }
                        delay=0;
                    }
                }
            }
            else
            {
                delay=0;
            }
        }
        else
        {
            if(half_sec_flag == 1)
            {
                dp_flag = dp_flag ^ 1; 
            }
            if(sec_flag == 1)
            {
                sec_flag = 0;
                minutes++;
                if(minutes>59)
                {
                    minutes=0;
                    hour++;
                }
                if(hour>23)
                {
                    hour=0;
                }
            }
        }
        ssd[3] = digit[minutes%10];
        ssd[2] = digit[(minutes/10)%10];
        ssd[1] = digit[hour%10];
        ssd[0] = digit[(hour/10)%10];
        if (mode == 0 && dp_flag)
        {
           ssd[1] = ssd[1] | 0x10;
        }
        if(mode == 1 && half_sec_flag)
        {
            if(field == 0)
            {
                ssd[3] = BLANK;
                ssd[2] = BLANK;
            }
            else
            {
                ssd[1] = BLANK;
                ssd[0] = BLANK;
            }
        }
        display(ssd);
    }
}


