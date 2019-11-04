;
; Lab6.asm
;
; Created: 10/28/2019 7:46:27 AM
; Author : Brent
;


start:
    ;Display 9 on 7 segment display
	LDI R16, $FF
	OUT DDRD, R16	; Make port D output
	CBI DDRC, 0		; Make PC0 an input
	LDI R17, $00

LREAD:
	SBIC PINC, 0
	CALL LOUTPUT
	SBIS PINC, 0
	CALL LCLEAR
	RJMP LREAD
	
LOUTPUT:
	LDI R16, 0b00000110
	OUT PORTD, R16	; Display 1 from PORTD
	CALL WAIT
	LDI R16, 0b01011011
	OUT PORTD, R16
	CALL WAIT
	RET

LCLEAR:
	OUT PORTD, R17	;Reset the display
	RET

WAIT:
	LDI R20, $FF
	L1:
		NOP
		NOP
		NOP
		LDI R21, $FF
		L2:
			NOP
			NOP
			NOP
			LDI R22, $0F
			L3:
				NOP
				NOP
				NOP
				DEC R22
				BRNE L3
			DEC R21
			BRNE L2
		DEC R20
		BRNE L1
	RET

HERE: RJMP HERE

