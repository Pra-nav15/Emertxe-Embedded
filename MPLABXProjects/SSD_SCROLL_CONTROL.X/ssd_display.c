/*
 * File:   ssd_display.c
 * Author: PRANAV
 *
 * Created on February 5, 2026, 6:20 PM
 */


#include <xc.h>
#include"ssd_control.h"

void init_ssd_display(void)
{
	TRISD = 0x00;
	TRISA = TRISA & 0xF0;
	SSD_CONTROL_PORT =  SSD_CONTROL_PORT & 0xF0;
}

/* Better if implemented in timer handler */
void display_left(unsigned char *data)
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

void display_right(unsigned char *data)
{
	unsigned int wait;
	unsigned char digit;

	for (digit = 0; digit < SSD_COUNT; digit++)
	{
		SSD_DATA_PORT = data[digit];
		SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0xF0) | (0x80 >> digit);
		for (wait = 1000; wait--; );
	}
}