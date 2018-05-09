echo Assembling kasm.asm...
nasm -f elf32 kernel.asm -o kasm.o
echo Compiling kernel...
gcc -m32 -c kernel.c -o kc.o -ffreestanding
gcc -m32 -c include/system.c -o obj/system.o -ffreestanding
gcc -m32 -c include/string.c -o obj/string.o -ffreestanding
gcc -m32 -c include/screen.c -o obj/screen.o -ffreestanding
gcc -m32 -c include/keyboard.c -o obj/keyboard.o -ffreestanding
gcc -m32 -c include/shell.c -o obj/shell.o -ffreestanding
gcc -m32 -c include/util.c -o obj/util.o -ffreestanding
gcc -m32 -c include/idt.c -o obj/idt.o -ffreestanding
gcc -m32 -c include/isr.c -o obj/isr.o -ffreestanding
echo Linking kernel...
ld -m elf_i386 -T linker.ld -o znix/boot/kernel.bin kasm.o kc.o obj/system.o obj/string.o obj/keyboard.o obj/screen.o obj/shell.o obj/util.o obj/idt.o obj/isr.o
rm kasm.o kc.o obj/*
#echo Building image...
#grub-mkrescue -o znix.iso znix
echo Launching VM...
qemu-system-i386 -kernel znix/boot/kernel.bin
