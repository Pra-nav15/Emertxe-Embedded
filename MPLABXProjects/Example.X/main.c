/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on January 19, 2026, 10:08 AM
 */


#include <xc.h>

void main(void) 
{
    unsigned char *trisb =(unsigned char*)0xF93;
    unsigned char *portb =(unsigned char*)0xF81;
    *trisb = 0x00;
    while(1)
    {
        *portb=0x;
    }
}
