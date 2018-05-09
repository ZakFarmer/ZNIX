COMPILER = gcc
LINKER = ld
ASSEMBLER = nasm
CFLAGS = -m32 -c -ffreestanding
ASFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T src/linker.ld
EMULATOR = qemu-system-i386
EMULATOR_FLAGS = -kernel

OBJS = obj/kasm.o obj/kc.o obj/idt.o obj/isr.o obj/keyboard.o obj/screen.o obj/string.o obj/system.o obj/util.o obj/shell.o
OUTPUT = znix/boot/kernel.bin

run: all
	$(EMULATOR) $(EMULATOR_FLAGS) $(OUTPUT)

all:$(OBJS)
	mkdir znix/ -p
	mkdir znix/boot/ -p
	$(LINKER) $(LDFLAGS) -o $(OUTPUT) $(OBJS)

obj/kasm.o:src/kernel.asm
	$(ASSEMBLER) $(ASFLAGS) -o obj/kasm.o src/kernel.asm
	
obj/kc.o:src/kernel.c
	$(COMPILER) $(CFLAGS) src/kernel.c -o obj/kc.o 
	
obj/idt.o:src/idt.c
	$(COMPILER) $(CFLAGS) src/idt.c -o obj/idt.o 

obj/keyboard.o:src/keyboard.c
	$(COMPILER) $(CFLAGS) src/keyboard.c -o obj/keyboard.o

obj/isr.o:src/isr.c
	$(COMPILER) $(CFLAGS) src/isr.c -o obj/isr.o

obj/screen.o:src/screen.c
	$(COMPILER) $(CFLAGS) src/screen.c -o obj/screen.o

obj/string.o:src/string.c
	$(COMPILER) $(CFLAGS) src/string.c -o obj/string.o

obj/system.o:src/system.c
	$(COMPILER) $(CFLAGS) src/system.c -o obj/system.o

obj/util.o:src/util.c
	$(COMPILER) $(CFLAGS) src/util.c -o obj/util.o
	
obj/shell.o:src/shell.c
	$(COMPILER) $(CFLAGS) src/shell.c -o obj/shell.o

build:all
	rm znix/boot/grub/ -r -f
	mkdir znix/boot/grub/
	echo set default=0 >> znix/boot/grub/grub.cfg
	echo set timeout=0 >> znix/boot/grub/grub.cfg
	echo menuentry "ZNIX" { >> znix/boot/grub/grub.cfg
	echo         set root='(hd96)' >> znix/boot/grub/grub.cfg
	echo         multiboot /boot/kernel.bin >> znix/boot/grub/grub.cfg
	echo } >> znix/boot/grub/grub.cfg

	grub-mkrescue -o znix.iso znix/
	
clear:
	rm -f obj/*.o
	rm -r -f znix/
	
