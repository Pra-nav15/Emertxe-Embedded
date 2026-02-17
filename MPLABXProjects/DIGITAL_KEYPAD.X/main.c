/*
 * File:   main.c
 * Author: Pranav Prasad
 * Description: This project demonstrates control of multiple LED patterns using a digital keypad. 
 *              Each switch on the keypad is assigned a unique LED pattern (Total 4). 
 *              When a switch is pressed, the corresponding LED pattern is displayed on PORTB. 
 *              The system uses edge-triggered key detection and software delay for pattern timing
 * Created on January 22, 2026, 10:30 AM
 */


#include <xc.h>
#include "digital_keypad.h"

unsigned int i = 0;
unsigned long delay = 0;
 
static void init_config(void)
{
    TRISB = 0x00;   //Set PORTB as output 
    PORTB = 0x00;   //Set PORTB to 0 (All LEDs are OFF)
    init_digital_keypad(); //initialize keypad
}

void main(void)
{
	unsigned char key, flag;
	init_config(); //initialize keypad and switch
	while (1)
	{
		key = read_digital_keypad(EDGE); //edge triggering return which switches is pressed
		if(key != ALL_RELEASED) // if any switch is pressed
        {
            switch(key)
            {
                case SWITCH1: //if switch 1 is pressed
                {
                    flag = 1;
                    break;
                }
                case SWITCH2: // if switch 2 is pressed
                {
                    flag = 2;
                    break;
                }
                case SWITCH3: //if switch 3 is pressed
                {
                    flag = 3;
                    break;
                }
                case SWITCH4: //if switch 4 is pressed
                {
                    flag = 4;
                    break;
                }
            }
        }
        else //if all switches are in released state
        {
            PORTB = 0x00;
        }
        if(flag == 1)   // switch 1 is pressed
        {
            PORTB = 0x00;
            led_pattern1(); 
        }
        else if(flag == 2) // switch 2 is pressed 
        {
            PORTB = 0x00;
            led_pattern2();
        }
        else if(flag == 3) //switch 3 is pressed
        {
            PORTB = 0x00;
            led_pattern3();
        }
        else if(flag == 4) //switch 4 is pressed
        {
            PORTB = 0x00;
            led_pattern4();
        }
	}
}

void led_pattern1(void)
{
    if(delay++ == 10000)   
    {
        if(i < 8)
        {
            PORTB = (PORTB << 1) | 0x01;
        }
        else if(i < 16)
        {
            PORTB = PORTB << 1;
        }
        else if(i < 24)
        {
            PORTB = (PORTB >> 1) | 0x80; 
        }
        else if(i < 32)
        {
            PORTB = PORTB >> 1;
        }
        else
        {
            i = 0;
        }
        i++;
        delay=0;
    }
}
void led_pattern2(void)
{
    if(delay++ == 10000)
    {
        if(i < 8)
        {
           PORTB = (PORTB << 1) | 0x01; 
        }
        else if(i < 16)
        {
            PORTB = PORTB << 1;
        }
        else
        {
            i=0;
        }
        i++;
        delay=0;
    }
}
void led_pattern3(void)
{
    static unsigned char state = 0;
    if (delay++ == 10000)
    {
        if (state == 0)
        {
            PORTB = 0x55;
            state = 1;
        }
        else
        {
            PORTB = ~PORTB;
            state = 0;
        }
        delay = 0;
    }
}
void led_pattern4(void)
{
    static unsigned char state = 0;
    if (delay++ == 10000)
    {
        if (state == 0)
        {
            PORTB = 0x0F;
            state = 1;
        }
        else
        {
            PORTB = ~PORTB;
            state = 0;
        }
        delay = 0;
    }
}

