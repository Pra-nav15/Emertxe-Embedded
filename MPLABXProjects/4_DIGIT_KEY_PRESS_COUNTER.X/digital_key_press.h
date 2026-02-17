/* 
 * File:   digital_key_press.h
 * Author: PRANAV
 *
 * Created on February 2, 2026, 8:23 AM
 */

#ifndef DIGITAL_KEY_PRESS_H
#define	DIGITAL_KEY_PRESS_H

#define KEY_PORT          PORTC

#define EDGE              0
#define LEVEL             1

#define SWITCH1           0x0E

#define ALL_RELEASED      0x0F
#define INPUT_PINS        0x0F

void init_digital_keypad(void);
unsigned char read_digital_keypad(unsigned char type);

#endif	/* DIGITAL_KEY_PRESS_H */

