/*
 * File:   ssd.c
 * Author: PRANAV
 *
 * Created on February 4, 2026, 6:40 PM
 */


#include <xc.h>
#include"clock.h"

void init_ssd_config(void)
{
    TRISD = 0x00;
    TRISA = TRISA & 0xF0;
    PORTA = PORTA & 0xF0;
}

void display(unsigned char data[])
{
    unsigned int wait;
	unsigned char digit;
    
	for (digit = 0; digit < SSD_COUNT; digit++)
	{
		SSD_DATA_PORT = data[digit];
		SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0xF0) | (0x01 << digit);
		for (wait = 1000; wait--; );
	}
}