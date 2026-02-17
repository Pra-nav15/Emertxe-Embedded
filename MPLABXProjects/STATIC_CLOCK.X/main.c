/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on February 10, 2026, 8:57 AM
 */



#include <xc.h>
#include "ssd_display.h"

unsigned char half_sec_flag;
unsigned char one_sec_flag;
unsigned char one_sec_count;

static unsigned char ssd[SSD_COUNT];
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
static void init_config(void)
{
    init_ssd_display();
    init_timer0();
}

void main(void)
{
    init_config();
    unsigned char hour = 12;
    unsigned char minutes = 0;
    unsigned char dp_flag = 0;
    while(1)
    {
        if(half_sec_flag == 1)
        {
            dp_flag = dp_flag ^ 1;
        }
        if(one_sec_flag == 1)
        {
            one_sec_flag = 0;
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
        display(ssd);
        ssd[3] = digit[minutes%10];
        ssd[2] = digit[(minutes/10)%10];
        ssd[1] = digit[hour%10];
        ssd[0] = digit[(hour/10)%10];
        if (dp_flag)
        {
           ssd[1] = ssd[1] | 0x10;  
        }
    }
}

