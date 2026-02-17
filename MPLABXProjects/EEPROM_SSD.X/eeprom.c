/*
 * File:   eeprom.c
 * Author: PRANAV
 *
 * Created on February 1, 2026, 7:03 PM
 */

#include <xc.h>
unsigned int read_internal_eeprom(unsigned char address)
{
    EEADR = address;
    EECON1bits.EEPGD =  0;
    EECON1bits.CFGS =   0;
    EECON1bits.RD =    1;
    return EEDATA;
}

void write_internal_eeprom(unsigned char address,unsigned char data)
{
    EEADR = address;
    EEDATA = data;
    EECON1bits.EEPGD =  0;
    EECON1bits.CFGS =   0;
    EECON1bits.WREN = 1;
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    INTCONbits.GIE = 1;
    while(PIR2bits.EEIF != 1);
    PIR2bits.EEIF =0;
    EECON1bits.WREN = 0;
}


