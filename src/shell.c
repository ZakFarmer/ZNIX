#include "../include/shell.h"

char SHELL_COLOUR = WHITE;

void launch_shell() {
	printf("Launching ZNIX shell...    [", WHITE);
	printf(" OK ", LGREEN);
	printf("]\n\n", WHITE);


	// This will do more in the future.

	shell_loop();
}

void shell_loop() {
	while(1) {
		printf("\nZNIX", LGREEN);
		printf("> ", WHITE);

		string str = read_string();
		if (str_compare(str, "clear")) {
			clear_screen();
		} else {
			printf("\nInvalid command.", LRED);
		}

		printf("\n", WHITE);
	}
}