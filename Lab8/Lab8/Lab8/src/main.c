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
#include <asf.h>
#include <avr/io.h>
#include <util/delay.h>

void delay_us(unsigned int);
void lcd_init(void);
void to_wire(int, int, int);

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();
	lcd_init();

	/* Insert application code here, after the board has been initialized. */
}

void delay_us(unsigned int d) {
	_delay_us(d);
}

void lcd_init(void) {
	
}

void to_wire(int SDA, int SCL, int data[8]) {
	for (int byte = 0; byte <= sizeof(data);byte++) {
		
	}
}