#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

#include "types.h"
#include "port.h"
#include "gdt.h"

class InterruptManager {
	protected:

		static InterruptManager* ActiveInterruptManager;

		struct GateDescriptor
		{
			uint16_t handler_address_low_bits;
			uint16_t gdt_code_segment_selector;
			uint8_t reserved;
			uint8_t access;
			uint16_t handler_address_high_bits;
		} __attribute__((packed));

		static GateDescriptor interrupt_descriptor_table[256];

		struct InterruptDescriptorTablePointer
		{
			uint16_t size;
			uint32_t base;
		} __attribute__((packed));

		static void set_interrupt_descriptor_table_entry(
			uint8_t interrupt_number,
			uint16_t code_segment_selector_offset,
			void (*handler)(),
			uint8_t DescriptorPrivilegeLevel,
			uint8_t DescriptorType
		);

		Port8BitSlow pic_master_command;
		Port8BitSlow pic_master_data;
		Port8BitSlow pic_slave_command;
		Port8BitSlow pic_slave_data;


	public:

		InterruptManager(GlobalDescriptorTable* gdt);
		~InterruptManager();

		void activate();
		void deactivate();

		static uint32_t handle_interrupt(uint8_t interrupt_number, uint32_t esp);
		uint32_t do_handle_interrupt(uint8_t interrupt_number, uint32_t esp);

		static void ignore_interrupt_request();
		static void handle_interrupt_request0x00();
		static void handle_interrupt_request0x01();
};

#endif