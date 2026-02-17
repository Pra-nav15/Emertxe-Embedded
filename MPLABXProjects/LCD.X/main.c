/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on February 3, 2026, 6:33 PM
 */


#include <xc.h>
#include "lcd.h"
#define _XTAL_FREQ 20000000

unsigned char str[CHARACTER_LENGTH];

void init_config(void)
{
    init_lcd_config();
	
}

void main(void)
{
    init_config();
    while(1)
    {
        clcd_print("Hello World    ", LINE1(0));
        __delay_ms(1000);
        clcd_print("ello World    H", LINE1(0));
        __delay_ms(1000);
        clcd_print("llo World    He", LINE1(0));
        __delay_ms(1000);
        clcd_print("lo World    Hel", LINE1(0));
        __delay_ms(1000);
        clcd_print("o World    Hell", LINE1(0));
        __delay_ms(1000);
        clcd_print(" World    Hello", LINE1(0));
        __delay_ms(1000);
        clcd_print("World    Hello ", LINE1(0));
        __delay_ms(1000);
        clcd_print("orld    Hello W", LINE1(0));
        __delay_ms(1000);
        clcd_print("rld    Hello Wo", LINE1(0));
        __delay_ms(1000);
        clcd_print("ld    Hello Wor", LINE1(0));
        __delay_ms(1000);
        clcd_print("d    Hello Worl", LINE1(0));
        __delay_ms(1000);
        clcd_print("    Hello World", LINE1(0));
        __delay_ms(1000);
        clcd_print("   Hello World ", LINE1(0));
        __delay_ms(1000);
        clcd_print("  Hello World  ", LINE1(0));
        __delay_ms(1000);
        clcd_print(" Hello World   ", LINE1(0));
        __delay_ms(1000);
        clcd_print("Hello World    ", LINE1(0));
        __delay_ms(1000);
    }
}
