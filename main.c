/*Author: c3283006 (Zayne Jeffries)
  Description: main file for encryption/decryption assignment
*/
#include "encdec.h"
#define MAX_ARGC 4

int main(int argc, char* argv[]){
	if(argc < 3){
		printerr();
		return -1;
	}
	unsigned int select = atoi(argv[1]);
	unsigned int key = 1;
	char* text;
	if(argc == 4){
		key = atoi(argv[2]);
		text = strdup(argv[3]);
	}
	else{
		text = strdup(argv[2]);
	}
	size_t textlen = strlen(text);
	switch(select){
		case 1: printf("%s\n", rotencr(text, key, textlen));
		break;
		case 2: printf("%s\n", rotdecr(text, key, textlen));
		break;
		case 3: printf("%s\n", subencr(text, textlen));
		break;
		case 4: printf("%s\n", subdecr(text, textlen));
		break;
		case 5:
		break;
		case 6:
		break;
		default: printerr();
		break;
	}
	return 0;
}
