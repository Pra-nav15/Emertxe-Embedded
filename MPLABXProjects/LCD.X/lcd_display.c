/*
 * File:   lcd_display.c
 * Author: PRANAV
 *
 * Created on February 3, 2026, 6:34 PM
 */


#include <xc.h>
#include"lcd.h"


void init_lcd_config(void)
{
    TRISD = 0x00;
    TRISC = TRISC & 0xF8;
    CLCD_RW = LOW;
    __delay_ms(15);
    clcd_write(EIGHT_BIT_MODE,INSTRUCTION_COMMAND);
    __delay_us(4100);
    clcd_write(EIGHT_BIT_MODE,INSTRUCTION_COMMAND);
    __delay_us(100);
    clcd_write(EIGHT_BIT_MODE,INSTRUCTION_COMMAND);
    __delay_us(100);
    clcd_write(CURSOR_SET,INSTRUCTION_COMMAND);
    __delay_us(100);
    clcd_write(SET_LINES,INSTRUCTION_COMMAND);
     __delay_us(100);
    clcd_write(CLEAR_DISPLAY,INSTRUCTION_COMMAND);
    __delay_us(500);
    clcd_write(CURSOR_SET,INSTRUCTION_COMMAND);
     __delay_us(100);
    
}

void clcd_write(unsigned char byte,unsigned char control_bit)
{
    CLCD_RS = control_bit;
    CLCD_PORT = byte;
    
    CLCD_EN = HIGH;
    CLCD_EN = LOW;
    
    PORT_DIR = INPUT;
    CLCD_RW = HIGH;
    CLCD_RS = INSTRUCTION_COMMAND;
    
    do
    {
        CLCD_EN = HIGH;
        CLCD_EN = LOW;
    }while(CLCD_BUSY);
    
    CLCD_RW = LOW;
    PORT_DIR= OUTPUT;
}

void clcd_print(unsigned char *str,unsigned char address)
{
    clcd_write(address,INSTRUCTION_COMMAND);
    while(*str != '\0')
    {
        clcd_write(*str++,DATA_COMMAND);
    }
}

