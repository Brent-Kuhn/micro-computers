/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#define F_CPU 16000000UL  // 16 MHz
#define __DELAY_BACKWARD_COMPATIBLE__

#include <asf.h>
#include <avr/io.h>
#include <util/delay.h>

void delay_us(unsigned int);
void to_wire(int, int, int, int, int, int, int*);
void monitor_buttons(void);
void blink(void);

#define SELECT PINB0
#define UP PINB1
#define DOWN PINB2
#define LEFT PINB3
#define RIGHT PINB4

// Buffers used for transmitting data to the board
int buff0[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int buff1[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int buff2[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int buff3[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int buff4[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int buff5[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int buff6[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int buff7[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

// Use position to keep current position from 0 to 7 x and y
// This will allow me to keep the state of the pointer
// XOR with 1 using buff0-buff7 will toggle the current location
int position[2] = {0, 0};

int main (void)
{
	DDRD |= (0b111<<2); // Set DDRD 2, 3, and 4 as outputs to the LCD
	DDRB &= ~(0b11111); // Set DDRB 0, 1, 2, 3, and 4 as inputs for the buttons
	int buff[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};

	//board_init(); // do I even need this?
	to_wire(PORTD, PORTD4, PORTD, PORTD2, PORTD, PORTD3, buff);

	while(1){
		monitor_buttons();
	}
}

void delay_us(unsigned int d) {
	_delay_us(d);
}

void to_wire(int DATAPORT, int DATA, int CLKPORT, int CLK, int CSPORT, int CS, int* buffer) {
	for (int byte = 15; byte >= 0;byte--) {
		int bit = buffer[byte];
		if(bit == 1) {
			DATAPORT |= (1<<DATA);
		} else {
			DATAPORT &= ~(1<<DATA);
		}
		CLKPORT |= (1<<CLK);
		delay_us(1);
		CLKPORT &= ~(1<<CLK);
	}
}

void monitor_buttons(void) {
	 if(PINB&(1<<SELECT)) {
		 // check for long press
		 
		 // Else toggle current bit
		 
		 blink();
	 }
	else if(PINB&(1<<UP)) {
		// Move the cursor up
		blink();
	} 
	else if(PINB&(1<<DOWN)) {
		// Move the cursor up
		blink();
	}
	else if(PINB&(1<<LEFT)) {
		// Move the cursor left
		blink();
	}
	else if(PINB&(1<<RIGHT)) {
		// Move the cursor right
		blink();
	}
	else {
		blink();
	}
}

void blink(void) {
	// toggle the current location on and off
	delay_us(600);
}