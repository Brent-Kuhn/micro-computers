;
; Lab3.asm
;
; Created: 10/7/2019 7:13:28 AM
; Author : Brent
;

; Activity 3 code
; Output the first 10 values of the fibonacci sequence to PORTB
start:
	LDI R16, 0
	LDI R17, 1
	LDI R18, 0
	LDI R19, 11

OUTPUT:
	OUT PORTB, R16
	MOV R18, R17
	ADD R17, R16
	MOV R16, R18
	DEC R19
	BRNE OUTPUT

END:
	RJMP END

; Activity 2 code
; Check value against 12, if R20 < 12 R24 = 3, if R20 == 12 R24 = 3, else R24 = 5
;start:
;	LDI R20, 15;input value
;	LDI R16, 12
;	SUB R20, R16
;	BRCC ELSE1
;	LDI R24, 3
;	RJMP END

;ELSE1:
;	BRNE ELSE2
;	LDI R24, 2
;	RJMP END

;ELSE2:
;	LDI R24, 5

;END:
;	RJMP END



; Activity 1 code
; Check value against R16 if >= 18, set R24 to 1 else, set R24 to 2
;start:
;   LDI R16, 19
;	LDI R17, 18
;	SUB R16, R17
;	BRSH LABEL1
;	LDI R24, 2
;	RJMP END

;LABEL1:
;	LDI R24, 1
;
;END:
;	JMP END