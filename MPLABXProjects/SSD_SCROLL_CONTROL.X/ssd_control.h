/* 
 * File:   ssd_control.h
 * Author: PRANAV
 *
 * Created on February 5, 2026, 6:19 PM
 */

#ifndef SSD_CONTROL_H
#define	SSD_CONTROL_H


#define EDGE              0
#define LEVEL             1

#define SSD_COUNT		  4

#define SSD_DATA_PORT			PORTD
#define SSD_CONTROL_PORT		PORTA
#define KEY_PORT                PORTC
#define SWITCH1                 0x0E
#define SWITCH2                 0x0D
#define ALL_RELEASED            0x0F
#define INPUT_PINS              0x0F

/* This values are for common cathode display */
#define ZERO			0xE7
#define ONE				0x21
#define TWO				0xCB
#define THREE			0x6B
#define FOUR			0x2D
#define FIVE			0x6E
#define SIX				0xEE
#define SEVEN			0x23
#define EIGHT			0xEF
#define NINE			0x6F
#define DECIMAL_POINT	0x10
#define SPACE			0x00


void init_ssd_display(void);
void display_left(unsigned char data[]);
void display_right(unsigned char data[]);
void init_digital_keypad(void);
unsigned char read_digital_keypad(unsigned char type);

#endif	/* SSD_CONTROL_H */

