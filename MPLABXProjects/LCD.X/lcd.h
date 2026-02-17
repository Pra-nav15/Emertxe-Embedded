/* 
 * File:   lcd.h
 * Author: PRANAV
 *
 * Created on February 3, 2026, 6:35 PM
 */

#ifndef LCD_H
#define	LCD_H
#define _XTAL_FREQ 20000000

#define CLCD_EN               PORTCbits.RC2
#define CLCD_RS               PORTCbits.RC1
#define CLCD_RW               PORTCbits.RC0
#define CLCD_BUSY             PORTDbits.RD7
#define PORT_DIR              TRISDbits.TRISD7
#define CLCD_PORT             PORTD

#define HIGH                  1
#define LOW                   0

#define INPUT                  0xFF
#define OUTPUT                 0x00

#define EIGHT_BIT_MODE        0x33

#define INSTRUCTION_COMMAND    0
#define DATA_COMMAND           1

#define CHARACTER_LENGTH       16

#define LINE1(x)              (0x80 + (x))
#define LINE2(x)              (0xC0 + (x))


#define CURSOR_SET             0x02
#define CLEAR_DISPLAY          0x01
#define SET_LINES              0x38
#define LCD_DISPLAY            0x0C

void init_lcd_config(void);
void clcd_write(unsigned char byte,unsigned char control_bit);
void clcd_putch(unsigned char data,unsigned char address);
void clcd_print(unsigned char str[],unsigned char address);

#endif	/* LCD_H */

