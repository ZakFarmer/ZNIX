#include "../include/isr.h"
#include "../include/idt.h"
#include "../include/screen.h"
#include "../include/util.h"

void isr_install() {
	set_idt_gate(0, (uint32)isr0);
	set_idt_gate(1, (uint32)isr1);
	set_idt_gate(2, (uint32)isr2);
	set_idt_gate(3, (uint32)isr3);
	set_idt_gate(4, (uint32)isr4);
	set_idt_gate(5, (uint32)isr5);
	set_idt_gate(6, (uint32)isr6);
	set_idt_gate(7, (uint32)isr7);
	set_idt_gate(8, (uint32)isr8);
	set_idt_gate(9, (uint32)isr9);
	set_idt_gate(10, (uint32)isr10);
	set_idt_gate(11, (uint32)isr11);
	set_idt_gate(12, (uint32)isr12);
	set_idt_gate(13, (uint32)isr13);
	set_idt_gate(14, (uint32)isr14);
	set_idt_gate(15, (uint32)isr15);
	set_idt_gate(16, (uint32)isr16);
	set_idt_gate(17, (uint32)isr17);
	set_idt_gate(18, (uint32)isr18);
	set_idt_gate(19, (uint32)isr19);
	set_idt_gate(20, (uint32)isr20);
	set_idt_gate(21, (uint32)isr21);
	set_idt_gate(22, (uint32)isr22);
	set_idt_gate(23, (uint32)isr23);
	set_idt_gate(24, (uint32)isr24);
	set_idt_gate(25, (uint32)isr25);
	set_idt_gate(26, (uint32)isr26);
	set_idt_gate(27, (uint32)isr27);
	set_idt_gate(28, (uint32)isr28);
	set_idt_gate(29, (uint32)isr29);
	set_idt_gate(30, (uint32)isr30);
	set_idt_gate(31, (uint32)isr31);

	set_idt();
}

void isr0() {
	printf(exception_messages[0], LRED);
	asm("hlt");
}
void isr1() {
	printf(exception_messages[1], LRED);
	asm("hlt");
}
void isr2() {
	printf(exception_messages[2], LRED);
	asm("hlt");
}
void isr3() {
	printf(exception_messages[3], LRED);
	asm("hlt");
}
void isr4() {
	printf(exception_messages[4], LRED);
	asm("hlt");
}
void isr5() {
	printf(exception_messages[5], LRED);
	asm("hlt");
}
void isr6() {
	printf(exception_messages[6], LRED);
	asm("hlt");
}
void isr7() {
	printf(exception_messages[7], LRED);
	asm("hlt");
}
void isr8() {
	printf(exception_messages[8], LRED);
	asm("hlt");
}
void isr9() {
	printf(exception_messages[9], LRED);
	asm("hlt");
}
void isr10() {
	printf(exception_messages[10], LRED);
	asm("hlt");
}
void isr11() {
	printf(exception_messages[11], LRED);
	asm("hlt");
}
void isr12() {
	printf(exception_messages[12], LRED);
	asm("hlt");
}
void isr13() {
	printf(exception_messages[13], LRED);
	asm("hlt");
}
void isr14() {
	printf(exception_messages[14], LRED);
	asm("hlt");
}
void isr15() {
	printf(exception_messages[15], LRED);
	asm("hlt");
}
void isr16() {
	printf(exception_messages[16], LRED);
	asm("hlt");
}
void isr17() {
	printf(exception_messages[17], LRED);
	asm("hlt");
}
void isr18() {
	printf(exception_messages[18], LRED);
	asm("hlt");
}
void isr19() {
	printf(exception_messages[19], LRED);
	asm("hlt");
}
void isr20() {
	printf(exception_messages[20], LRED);
	asm("hlt");
}
void isr21() {
	printf(exception_messages[21], LRED);
	asm("hlt");
}
void isr22() {
	printf(exception_messages[22], LRED);
	asm("hlt");
}
void isr23() {
	printf(exception_messages[23], LRED);
	asm("hlt");
}
void isr24() {
	printf(exception_messages[24], LRED);
	asm("hlt");
}
void isr25() {
	printf(exception_messages[25], LRED);
	asm("hlt");
}
void isr26() {
	printf(exception_messages[26], LRED);
	asm("hlt");
}
void isr27() {
	printf(exception_messages[27], LRED);
	asm("hlt");
}
void isr28() {
	printf(exception_messages[28], LRED);
	asm("hlt");
}
void isr29() {
	printf(exception_messages[29], LRED);
	asm("hlt");
}
void isr30() {
	printf(exception_messages[30], LRED);
	asm("hlt");
}
void isr31() {
	printf(exception_messages[31], LRED);
	asm("hlt");
}

string exception_messages[] = {
	"Division By Zero",
	"Debug",
	"Non Maskable Interrupt",
	"Breakpoint",
	"Into Detected Overflow",
	"Out of Bounds",
	"No Coprocessor",
	"Double Fault",
	"Coprocessor Segment Overrun",
	"Bad TSS",
	"Segment Not Present",
	"Stack Fault",
	"General Protection Fault",
	"Page Fault",
	"Unknown Interrupt",
	"Coprocessor Fault",
	"Alignment Check",
	"Machine Check",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved"
};