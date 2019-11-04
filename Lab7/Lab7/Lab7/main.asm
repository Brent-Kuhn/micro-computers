;
; Lab7.asm
;
; Created: 11/4/2019 10:10:22 AM
; Author : Brent
;


; Replace with your application code
start:
	LDI R17, $00
	OUT DDRD, R17 ; Make PORTD an input

	LDI R17, $FF
	OUT DDRB, R17 ; Make PORTB an output
	OUT DDRC, R17 ; Make PORTC an output

	LDI R16, 39 ; Load constant 39 into R16
	LDI R19, $00 ;Give me a zero!
	L3:
		IN R17, PIND ; Read from PIND
		MUL R17, R17 ; Square R17 value
		ADD R0, R17 ; Add lower bits
		ADC R1, R19 ; Add the carry to R1
		ADD R0, R16 ; Add the 39 with the lower bits
		ADC R1, R19 ; Add the carry to R1
		OUT PORTB, R0 ; Send the lower bits to PORTB
		OUT PORTC, R1 ; Send the upper bits to PORTC
		RJMP L3 ; Repeat this loop

		

/*	Activity 2
	OUT DDRD, R17 ; Make PORTD an input
	OUT DDRC, R17 ; Make PORTC an input

	LDI R17, $FF
	OUT DDRB, R17 ; Make PORTB an output
	L2:
		IN R17, PINC ; Read from PINC
		IN R18, PIND ; Read from PIND
		ADD R17, R18 ; ADD PINC and PIND
		LSR R17 ; Logical Right shift will divide PINC + PIND by two
		OUT PORTB, R17 ; Output the answer to PORTB
		RJMP L2 ; Repeat this loop*/

/*
	Activity 1
	OUT DDRD, R17 ; Make PORTD an input
	OUT DDRC, R17 ; Make PORTC an input

	LDI R17, $FF
	OUT DDRB, R17 ; Make PORTB an output
	LDI R16, 4
	L1:
		IN R17, PINC ; Read from PINC
		IN R18, PIND ; Read from PIND
		ADD R17, R16 ; Add 4 to the value from PIND
		MUL R17, R18 ; Multiply (PORTB+4)*PORTC
		OUT PORTB, R0 ; Output to PORTD from the result
		RJMP L1 ; Repeat this loop*/


END: RJMP END
