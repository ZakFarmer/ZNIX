GCCPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = obj/loader.o obj/gdt.o obj/port.o obj/interruptstubs.o obj/interrupts.o obj/keyboard.o obj/mouse.o obj/kernel.o


run: kernel.iso
	(killall VirtualBox && sleep 1) || true
	VirtualBox --startvm 'ZNIX' &

obj/%.o: src/%.cpp
	gcc $(GCCPARAMS) -c -o $@ $<

obj/%.o: src/%.s
	as $(ASPARAMS) -o $@ $<

kernel.bin: src/linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

kernel.iso: kernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp kernel.bin iso/boot/kernel.bin
	echo 'set timeout=0'                      > iso/boot/grub/grub.cfg
	echo 'set default=0'                     >> iso/boot/grub/grub.cfg
	echo ''                                  >> iso/boot/grub/grub.cfg
	echo 'menuentry "ZNIX" {' 				>> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin'    >> iso/boot/grub/grub.cfg
	echo '  boot'                            >> iso/boot/grub/grub.cfg
	echo '}'                                 >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=kernel.iso iso
	rm -rf iso

install: kernel.bin
	sudo cp $< /boot/kernel.bin

clean:
	rm -f $(objects) kernel.bin kernel.iso
