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
	int select = atoi(argv[1]);
	char* text;
	int key = 1;
	if(argc == 4){
		key = atoi(argv[2]);
		text = strdup(argv[3]);
	}
	else{
		text = strdup(argv[2]);
	}
	size_t textlen = strlen(text);
	char retarr[textlen];
	switch(select){
		case 1: printf("%s\n", rotencr(text, retarr, key, textlen));
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
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
