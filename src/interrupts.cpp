#include "../include/interrupts.h"

void printf(const char* str);

InterruptManager::GateDescriptor InterruptManager::interrupt_descriptor_table[256];

InterruptManager* InterruptManager::ActiveInterruptManager = 0;

void InterruptManager::set_interrupt_descriptor_table_entry (
	uint8_t interrupt_number,
	uint16_t code_segment_selector_offset,
	void (*handler)(),
	uint8_t DescriptorPrivilegeLevel,
	uint8_t DescriptorType) 
{
	const uint8_t IDT_DESC_PRESENT = 0x80;

	interrupt_descriptor_table[interrupt_number].handler_address_low_bits = ((uint32_t)handler) & 0xFFFF;
	interrupt_descriptor_table[interrupt_number].handler_address_high_bits = (((uint32_t)handler) >> 16) & 0xFFFF;
	interrupt_descriptor_table[interrupt_number].gdt_code_segment_selector = code_segment_selector_offset;
	interrupt_descriptor_table[interrupt_number].access = IDT_DESC_PRESENT | DescriptorType | ((DescriptorPrivilegeLevel&3) << 5);
	interrupt_descriptor_table[interrupt_number].reserved = 0;
}

InterruptManager::InterruptManager(GlobalDescriptorTable* gdt) 
: pic_master_command(0x20),
  pic_master_data(0x21),
  pic_slave_command(0xA0),
  pic_slave_data(0xA1)
  {
	uint16_t code_segment = gdt->CodeSegmentSelector();
	const uint8_t IDT_INTERRUPT_GATE = 0xE;

	for (uint16_t i = 0; i < 256; i++) {
		set_interrupt_descriptor_table_entry(i, code_segment, &ignore_interrupt_request, 0, IDT_INTERRUPT_GATE); 
	}

	set_interrupt_descriptor_table_entry(0x20, code_segment, &handle_interrupt_request0x00, 0, IDT_INTERRUPT_GATE);
	set_interrupt_descriptor_table_entry(0x21, code_segment, &handle_interrupt_request0x01, 0, IDT_INTERRUPT_GATE);


	pic_master_command.Write(0x11);
	pic_slave_command.Write(0x11);

	pic_master_data.Write(0x20);
	pic_slave_data.Write(0x28);

	pic_master_data.Write(0x04);
	pic_slave_data.Write(0x02);

	pic_master_data.Write(0x01);
	pic_slave_data.Write(0x01);

	pic_master_data.Write(0x00);
	pic_slave_data.Write(0x00);


	InterruptDescriptorTablePointer idt;
	idt.size = 256 * sizeof(GateDescriptor) - 1;
	idt.base = (uint32_t)interrupt_descriptor_table;
	asm volatile("lidt %0" : : "m" (idt));
}

InterruptManager::~InterruptManager() {

}

void InterruptManager::activate() {
	if (ActiveInterruptManager != 0)
		ActiveInterruptManager->deactivate();
	ActiveInterruptManager = this;
	asm("sti");
}

void InterruptManager::deactivate() {
	if (ActiveInterruptManager == this) {
		ActiveInterruptManager = 0;
		asm("cli");
	}
}

uint32_t InterruptManager::handle_interrupt(uint8_t interrupt_number, uint32_t esp) {
	if (ActiveInterruptManager != 0) {
		return ActiveInterruptManager->do_handle_interrupt(interrupt_number, esp);
	}

	printf("INTERRUPT");

	return esp;
}

uint32_t InterruptManager::do_handle_interrupt(uint8_t interrupt_number, uint32_t esp) {

	printf("INTERRUPT");

	return esp;
}