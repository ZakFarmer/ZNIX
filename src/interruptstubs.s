.set IRQ_BASE, 0x20

.section .text

.extern _ZN16InterruptManager16handle_interruptEhj
.global _ZN16InterruptManager24ignore_interrupt_requestEv

.macro HandleException num
.global _ZN16InterruptManager16handle_exception\num\()Ev
_ZN16InterruptManager28handle_exception_request\num\()Ev:
	movb $\num, (interrupt_number)
	jmp int_bottom
.endm

.macro HandleInterruptRequest num
.global _ZN16InterruptManager28handle_interrupt_request\num\()Ev
_ZN16InterruptManager28handle_interrupt_request\num\()Ev:
	movb $\num + IRQ_BASE, (interrupt_number)
	jmp int_bottom
.endm

HandleInterruptRequest 0x00
HandleInterruptRequest 0x01

int_bottom:

	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs

	pushl %esp
	push (interrupt_number)
	call _ZN16InterruptManager16handle_interruptEhj
	# addl $5, %esp
	movl %eax, %esp

	popl %gs
	popl %fs
	popl %es
	popl %ds
	popa

_ZN16InterruptManager24ignore_interrupt_requestEv:
	iret

.data
	interrupt_number: .byte 0


