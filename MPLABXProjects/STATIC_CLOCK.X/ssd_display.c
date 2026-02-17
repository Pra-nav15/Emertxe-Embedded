#include <xc.h>
#include"ssd_display.h"

void init_ssd_display(void)
{
	TRISD = 0x00;
	TRISA = TRISA & 0xF0;
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