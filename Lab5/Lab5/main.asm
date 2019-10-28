;
; Lab5.asm
;
; Created: 10/21/2019 7:08:50 AM
; Author : Brent
;


start:
	LDI R16, $00
	; Set DDRD to input
    OUT DDRD, R16

	LDI R16, $FF
	; Set DDRB to output
	OUT DDRB, R16
	LDI R17, $FF
	LDI R16, 0b00001000

LR:
	; Read from PORTD
	IN  R20, PIND
	SUB R20, R16
	BREQ LO
	RJMP LR

LO:
	; Send out to PORTB
	OUT PORTB, R17
	; Copy the contents to R21 and R22
	;MOV R21, R17
	;MOV R22, R17
	RJMP LR
	
