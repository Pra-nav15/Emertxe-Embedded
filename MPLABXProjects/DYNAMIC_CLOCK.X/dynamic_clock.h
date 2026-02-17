/* 
 * File:   dynamic_clock.h
 * Author: PRANAV
 *
 * Created on February 12, 2026, 7:43 AM
 */

#ifndef DYNAMIC_CLOCK_H
#define	DYNAMIC_CLOCK_H

#define SSD_COUNT        4

#define SSD_DATA_PORT			PORTD
#define SSD_CONTROL_PORT		PORTA
#define KEY_PORT                PORTC

#define EDGE              0
#define LEVEL             1

#define SWITCH1           0x0E
#define SWITCH2           0x0D
#define SWITCH3           0x0B
#define SWITCH4           0x07

#define ALL_RELEASED      0x0F
#define INPUT_PINS        0x0F

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
#define BLANK			0x00


extern unsigned char half_sec_flag;
extern unsigned char sec_flag;
extern unsigned char sec_count;

void init_ssd_display(void);
void display(unsigned char data[]);
void init_timer0(void);
void init_digital_keypad(void);
unsigned char read_digital_keypad(unsigned char type);

#endif	/* DYNAMIC_CLOCK_H */

