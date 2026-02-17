/* 
 * File:   sleep_and_wake.h
 * Author: PRANAV
 *
 * Created on February 4, 2026, 8:54 AM
 */

#ifndef SLEEP_AND_WAKE_H
#define	SLEEP_AND_WAKE_H

#define SSD_COUNT		4

#define SSD_DATA_PORT			PORTD
#define SSD_CONTROL_PORT		PORTA
#define KEY_PORT                PORTC
#define LED_PORT                PORTB

#define INTERRUPT_BUTTON        RB0

/* This values are for common cathode display */
#define ONE				0x21
#define TWO				0xCB
#define THREE			0x6B
#define FOUR			0x2D
#define FOUR			0x2D
#define FIVE			0x6E
#define SIX				0xEE
#define SEVEN			0x23
#define EIGHT			0xEF
#define NINE			0x6F
#define BLANK           0x00

#define EDGE              0
#define LEVEL             1

#define SWITCH1           0x0E
#define SWITCH2           0x0D
#define SWITCH3           0x0B
#define SWITCH4           0x07

#define ALL_RELEASED      0x0F
#define INPUT_PINS        0x0F

volatile unsigned int idle_count;
volatile unsigned char minute_count;
volatile unsigned char interrupt_pressed;

void init_digital_keypad(void);
unsigned char read_digital_keypad(unsigned char type);
void init_ssd_display(void);
void display(unsigned char data[]);
void init_timer0(void);
void init_led_config(void);

#endif	/* SLEEP_AND_WAKE_H */

