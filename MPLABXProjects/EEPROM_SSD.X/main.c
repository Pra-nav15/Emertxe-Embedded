/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on February 1, 2026, 7:03 PM
 */

#include <xc.h>
#include "ssd_display.h"

static unsigned char ssd[SSD_COUNT];
static unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
void init_config(void)
{
	init_ssd_display();
}

void main(void) 
{
    init_config();
   unsigned int count=((read_internal_eeprom(0x00)*1000)+(read_internal_eeprom(0x01)*100)+(read_internal_eeprom(0x02)*10)+(read_internal_eeprom(0x03)));
    
    unsigned long delay = 0;
    unsigned long led_delay=0;
    while(1)
    {
        display(ssd);
        ssd[0] = digit[count/1000%10];
        ssd[1] = digit[count/100%10];
        ssd[2] = digit[count/10%10];
        ssd[3] = digit[count%10];
     
        if(delay++ == 100)
        {
            count++;
            write_internal_eeprom(0x03,count%10);
            write_internal_eeprom(0x02,count/10%10);
            write_internal_eeprom(0x01,count/100%10);
            write_internal_eeprom(0x00,count/1000%10);
            if(count == 500)
            {
                if(led_delay++==100000)
                {
                    PORTB=~PORTB;
                    led_delay=0;
                }
            }
            delay = 0;
        }
    }
}

