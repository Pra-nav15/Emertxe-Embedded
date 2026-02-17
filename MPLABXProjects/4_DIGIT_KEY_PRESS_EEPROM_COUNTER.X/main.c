/*
 * File:   main.c
 * Author: Pranav Prasad
 * Description: This project implements a persistent 4-digit key press counter using a digital keypad and internal EEPROM. 
 *              The counter value is displayed on a 4-digit SSD. 
 *              Each short press of DKS1 increments the count. 
 *              A long press of DKS1 (approximately 2 seconds) resets the counter to zero.
 *              Pressing DKS2 stores the current counter value into the internal EEPROM. 
 *              On subsequent power-ups or resets, the counter resumes from the last stored value.
 * Created on February 2, 2026, 9:48 AM
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
    unsigned int count=((read_internal_eeprom(0x00)*1000)+(read_internal_eeprom(0x01)*100)+(read_internal_eeprom(0x02)*10)+(read_internal_eeprom(0x03)));
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
        else if(SWITCH2 == key)
        {
            write_internal_eeprom(0x03,count%10);
            write_internal_eeprom(0x02,count/10%10);
            write_internal_eeprom(0x01,count/100%10);
            write_internal_eeprom(0x00,count/1000%10);
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