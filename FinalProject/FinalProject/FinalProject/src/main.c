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

#define SET_HIGH(port, pin) port |= (1<<pin);
#define SET_LOW(port, pin) port &= ~(1<<pin);

void delay_ms(unsigned int);
void monitor_buttons(void);
void blink(void);
void spi_out(uint16_t);
void init_LED(void);

// Needs to be re-organized according to circuit
#define SELECT PIND2
#define UP PIND6
#define DOWN PIND5
#define LEFT PIND3
#define RIGHT PIND4
#define CLK PORTB5
#define CS PORTB2
#define MOSI PORTB3

// Use position to keep current position from 0 to 7 x and y
// This will allow me to keep the state of the pointer
// XOR with 1 using buff0-buff7 will toggle the current location
int position[2] = {0, 0};

uint16_t row1 = 0x0800;
uint16_t row2 = 0x0700;
uint16_t row3 = 0x0600;
uint16_t row4 = 0x0500;
uint16_t row5 = 0x0400;
uint16_t row6 = 0x0300;
uint16_t row7 = 0x0200;
uint16_t row8 = 0x0100;

int main (void)
{
	//board_init(); // do I even need this?
	
	//PORTD is the button register
	SET_LOW(DDRD, SELECT);
	SET_LOW(DDRD, UP);
	SET_LOW(DDRD, DOWN);
	SET_LOW(DDRD, LEFT);
	SET_LOW(DDRD, RIGHT);
	
	init_LED();
	
	// Send test data for now
	//spi_out(0x0FFF);
	spi_out(row8 | 0x1);

	while(1){
		monitor_buttons();
	}
}

void init_LED(void) {
	//PORTB is the SPI port
	//DDRB = 0xFF; // Turn DDRB as output
	// Make CLK, MOSI, and CS outputs
	SET_HIGH(DDRB, CLK);
	SET_HIGH(DDRB, MOSI);
	SET_HIGH(DDRB, CS);
	
	//Enable SPI as master
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	
	spi_out(0x0900); // Disable the decoding
	spi_out(0x0B07); // Scan the segments
	
	// Clear each row by sending 0x0r00 where r=row index
	for(uint16_t i = row8; i <= row1; i += 0x0100) {
		spi_out(i);
	}
	
	// Remove the device from shutdown mode
	spi_out(0x0C01);
	
	delay_ms(1);
}

void delay_ms(unsigned int d) {
	_delay_ms(d);
}

void spi_out(uint16_t data){
	PORTB &= ~(1<<CS);				//enable slave device
	SPDR = (data>>8);				//start transmission
	while(!(SPSR & (1<<SPIF)));		//wait transfer finish
	SPDR = (data & 0xFF);			//start transmission
	while(!(SPSR & (1<<SPIF)));		//wait transfer finish
	PORTB |= (1<<CS);				//disable slave device
	delay_ms(1);					//datasheet says to wait a little
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
	// toggle the current location on
	delay_ms(10);
	// toggle the current location off
}