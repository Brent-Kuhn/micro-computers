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

LR:
	; Read from PORTD
	SBIC PIND, 4	
	RJMP LO		;If PD4 is high, go to LO
	RJMP LR		;Else check again

LO:
	; Send out to PORTB
	OUT PORTB, R17
	; Copy the contents to R21 and R22
	;MOV R21, R17
	;MOV R22, R17
	RJMP LR
	
