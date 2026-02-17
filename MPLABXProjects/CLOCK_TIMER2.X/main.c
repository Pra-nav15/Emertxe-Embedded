/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on February 4, 2026, 6:40 PM
 */


#include <xc.h>
#include"clock.h"

static unsigned char ssd[SSD_COUNT];
static unsigned char digit[]={ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

static unsigned int count=0;
static unsigned char seconds_count = 0;
static unsigned char minutes_count = 0;
void init_config(void)
{
    init_ssd_config();
    init_timer2();
}

void __interrupt() isr(void)
{
    if(PIR1bits.TMR2IF == 1)
    {
        PIR1bits.TMR2IF = 0;
        count++;
        if(count==20000)
        {
            count=0;
            while(1)
            {
                seconds_count++;
                if(seconds_count == 60)
                {
                    seconds_count=0;
                    minutes_count++;
                    if(minutes_count>=60)
                    {
                        minutes_count=0;
                    }
                }
            }
        }
    }
}
void main(void)
{
    init_config();
    while(1)
    {
        ssd[0] = digit[minutes_count / 10];
        ssd[1] = digit[minutes_count % 10];
        ssd[2] = digit[seconds_count / 10];
        ssd[3] = digit[seconds_count % 10];
        display(ssd);
    }
}