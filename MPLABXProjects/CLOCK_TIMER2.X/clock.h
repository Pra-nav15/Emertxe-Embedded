/* 
 * File:   clock.h
 * Author: PRANAV
 *
 * Created on February 4, 2026, 6:41 PM
 */

#ifndef CLOCK_H
#define	CLOCK_H

#define SSD_COUNT		4

#define SSD_DATA_PORT			PORTD
#define SSD_CONTROL_PORT		PORTA

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
void display(unsigned char* data);
void init_timer2(void);
void __interrupt() isr(void);
void init_config(void);
void init_ssd_config(void);
#endif	/* CLOCK_H */

