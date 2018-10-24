/*
 * led-switch-avr-atmega32.c
 *
 * Created: 10/20/2018 8:11:39 PM
 * Author : ashumeow
 */ 
#include <avr/io.h>
#define get_bit(reg,bitnum) ((reg & (1<<bitnum))>>bitnum)
int main(void)
{
	DDRD=0b11111000; // set the first 3 pins of PORTD to be inputs to read from the push buttons
	PORTD=0b00000000; // Initialize PORTD to zeros
	TCCR0=0b01110101; //Configure TCCR0
	TIMSK=0b00000000;
	DDRC = 0x00; //Makes PORTC as Output
    while (1) 
    {
		if (get_bit(PIND,0)==1)
		{
			DDRC= 0xFF; //Turns ON LED
		} else if(get_bit(PIND,0)==0) {
			DDRC= 0x00; //Turns OFF LED
		} else {
			// do nothing
		}
    }
}
