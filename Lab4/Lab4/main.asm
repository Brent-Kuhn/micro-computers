;
; Lab4.asm
;
; Created: 10/14/2019 7:06:11 AM
; Author : Brent
;


start:
	; Initialize the stack
    LDI R16, HIGH(RAMEND)
	OUT SPH, R16
	LDI R16, LOW(RAMEND)
	OUT SPL, R16

	LDI R16, $00
	LDI R17, $FF
	LDI R18, 1

count:
	LDI R17, $FF
	PUSH R16
	INC R16

	CALL display

	SUB R17, R16
	BREQ end

	RJMP count

display:
	OUT PORTB, R16
	CALL delay
	RET


delay:
	INC R18
	DEC R18
	RET

	NOP

end:
	RJMP end

;Actvity 2, push values to the stack at $29D, then pop them to R20-R24
/*start:
	LDI R16, $02
	OUT SPH, R16
	LDI R16, $9D
	OUT SPL, R16

	LDI R16, 1
	PUSH R16
	INC R16
	PUSH R16
	INC R16
	PUSH R16
	INC R16
	PUSH R16
	INC R16
	PUSH R16
	INC R16
	PUSH R16

	POP R20
	POP R21
	POP R22
	POP R23
	POP R24

	NOP

end:
	RJMP end*/


; Activity 1, push values to the initialized stack at the end of ram
/*start:
	; Initialize the stack
    LDI R16, HIGH(RAMEND)
	OUT SPH, R16
	LDI R16, LOW(RAMEND)
	OUT SPL, R16

	LDI R20, 20
	LDI R21, 21
	LDI R22, 22
	LDI R23, 23
	LDI R24, 24

	PUSH R20
	PUSH R21
	PUSH R22
	PUSH R23
	PUSH R24

	NOP

LOOP:
	RJMP LOOP*/