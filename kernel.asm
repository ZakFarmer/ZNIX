bits	32				; use 32 bit processor mode (for compatibility)
section			.text
		align	4
		dd		0x1BADB002
		dd		0x00
		dd		- (0x1BADB002+0x00)

global start
extern kmain			; declare main kernel function
start:
		cli     		; clear interrupts
		call kmain  	; call main kernel function
		hlt				; halt