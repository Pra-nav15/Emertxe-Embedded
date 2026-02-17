/*
 * File:   ssd_display.c
 * Author: PRANAV
 *
 * Created on February 4, 2026, 8:54 AM
 */

#include<xc.h>
#include"sleep_and_wake.h"

void init_ssd_display(void)
{
	/* Setting PORTD as output for Data Lines */
	TRISD = 0x00;
	/* Setting SSD Enable lines as output */
	TRISA = TRISA & 0xF0;
	/* Switching OFF all the SSDs to start with */
	SSD_CONTROL_PORT =  SSD_CONTROL_PORT & 0xF0;
}

/* Better if implemented in timer handler */
void display(unsigned char *data)
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
