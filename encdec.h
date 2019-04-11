/*Author: c3283006 (Zayne Jeffries)
  Description: header file for encryption/decryption project
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//defines lookup table for substitution cipher based on QWERTY keyboard layout
#define _A Q
#define _B W
#define _C E
#define _D R
#define _E T
#define _F Y
#define _G U
#define _H I
#define _I O
#define _J P
#define _K A
#define _L S
#define _M D
#define _N F
#define _O G
#define _P H
#define _Q J
#define _R K
#define _S L
#define _T Z
#define _U X
#define _V C
#define _W V
#define _X B
#define _Y N
#define _Z M
/*Function definitions*/
char* rotencr(char message[], char retarr[], int key, size_t arrlen);
void rotdecr(char ciph[], int key, size_t arrlen);
char* subencr(char message[]);
void subdecr(char ciph[]);
void ciphrotdecr(char ciph[]);
void ciphsubdecr(char ciph[]);
void printerr();
/*Function Implementations*/
char* rotencr(char message[], char retarr[], int key, size_t arrlen){
	for(int i = 0; i < arrlen; i++){
		if(message[i] == ' '){
			retarr[i] = ' ';
			continue;
		}
		retarr[i] = ((message[i] - 65) + key) % (26);
		retarr[i] += 65;
	}
	retarr[arrlen - 1] = '\0';
	return retarr;
}

void printerr(){
	printf("USAGE: ./progname selection optional_key \"string_to_decrypt\"\n");
	printf("Selection options:\n (1)Rotation Encrypt\n (2)Rotation Decrypt\n (3)Substitution Encrypt\n (4)Substitution Decrypt\n");
	printf(" (5)Rotation Decrypt Cipher Text Only\n (6)Substitution Decrypt Cipher Text Only\n");
}