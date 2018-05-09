#include "../include/keyboard.h"

char get_scancode() {
    char chr = 0;
    do {
    	if(inportb(0x64) & 0x1) {
	        if(inportb(0x60) != chr) {
	            chr = inportb(0x60);
	            if(chr > 0)
	                return chr;
	        }
	    }
    } while(1);
}

char scancode[57] = {
	(char)27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u',
	'i', 'o', 'p', '[', ']', '\n', ' ', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', (char)44, ' ', ' ', ' ', 'z', 'x',
	'c', 'v', 'b', 'n', 'm', ',', '.', '/', ' ', ' ', ' ', ' '
};

char get_char(char scode) {
    return scancode[scode - 1];
}

string read_string()
{
    char buff;
    string str_buffer;
    uint8 i = 0;
    uint8 reading = 1;
    while(reading)
    {
    	char scode = get_scancode();
    	char chr = get_char(scode);
    	if (char_in_array(chr, scancode, 57)) {
    		switch(chr)
	        {
	        	case '\n':
	        		reading = 0;
	        		break;
	        	default:
	        		str_buffer[i] = chr;
	        		printchr(chr, WHITE);
	        		i++;
	        		break;
		    }
    	}
    }
    //printf("Stopped reading.");
    str_buffer[i] = 0;           
    return str_buffer;
}