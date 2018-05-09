#include "../include/screen.h"
#include "../include/keyboard.h"
#include "../include/string.h"

int kmain() {
	isr_install();
	clear_screen();
	launch_shell();
}