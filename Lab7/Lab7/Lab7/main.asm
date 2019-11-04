;
; Lab7.asm
;
; Created: 11/4/2019 10:10:22 AM
; Author : Brent
;


; Replace with your application code
start:
	LDI R16, 4

	LDI R17, $00
	OUT DDRD, R17 ; Make PORTD an input
	OUT DDRC, R17 ; Make PORTC an input

	LDI R17, $FF
	OUT DDRB, R17 ; Make PORTB an outoput

	L1:
		IN R17, PINC ; Read from PINC
		IN R18, PIND ; Read from PIND
		ADD R17, R16 ; Add 4 to the value from PIND
		MUL R17, R18 ; Multiply (PORTB+4)*PORTC
		OUT PORTB, R0 ; Output to PORTD from the result
		RJMP L1 ; Repeat this loop


END: RJMP END
