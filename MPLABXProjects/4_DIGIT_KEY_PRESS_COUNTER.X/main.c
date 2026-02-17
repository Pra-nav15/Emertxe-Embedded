/*
 * File:   main.c
 * Author: Pranav Prasad
 * Description: This project implements a 4-digit counter controlled by a digital keypad. 
 *              Each short press of switch DKS1 increments the counter by one and updates the value on the SSD.
 *              A long press of the same switch for approximately 2 seconds resets the counter value to zero. 
 *              Software delay is used to differentiate between short and long key presses
 * Created on February 2, 2026, 8:22 AM
 */


#include <xc.h>
#include"digital_key_press.h"
#include"ssd_display.h"

static unsigned char ssd[SSD_COUNT];
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

static void init_config(void)
{
    init_digital_keypad();
    init_ssd_display();
}
void main(void)
{
    init_config();
    unsigned char key;
    unsigned int count=0;
    unsigned long delay=0;
    
    while(1)
    {
        ssd[3]=digit[count%10];
        ssd[2]=digit[count/10%10];
        ssd[1]=digit[count/100%10];
        ssd[0]=digit[count/1000%10];
        display(ssd);
        key=read_digital_keypad(LEVEL);
        if(SWITCH1==key)
        {
            if(delay++ > 200)
            {
                count=0;
            }
        }
        else if(delay > 0 && delay < 200)
        {
            count++;
            delay=0;
        }
        else
        {
            delay=0;
        }
    }
}

