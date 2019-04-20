/*Author: c3283006 (Zayne Jeffries)
  Description: header file for encryption/decryption project
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//defines lookup table for substitution cipher based on QWERTY keyboard layout
#define _A 'Q'
#define _B 'W'
#define _C 'E'
#define _D 'R'
#define _E 'T'
#define _F 'Y'
#define _G 'U'
#define _H 'I'
#define _I 'O'
#define _J 'P'
#define _K 'A'
#define _L 'S'
#define _M 'D'
#define _N 'F'
#define _O 'G'
#define _P 'H'
#define _Q 'J'
#define _R 'K'
#define _S 'L'
#define _T 'Z'
#define _U 'X'
#define _V 'C'
#define _W 'V'
#define _X 'B'
#define _Y 'N'
#define _Z 'M'
/*Function definitions*/
char* rotencr(char message[], int key, size_t arrlen);
char* rotdecr(char ciph[], int key, size_t arrlen);
char* subencr(char message[], size_t arrlen);
char* subdecr(char ciph[], size_t arrlen);
char* ciphrotdecr(char ciph[]);
char* ciphsubdecr(char ciph[]);
void printerr();
/*Function Implementations*/
char* rotencr(char message[], int key, size_t arrlen){
	for(int i = 0; i < arrlen; i++){
		if(message[i] == ' '){
			message[i] = ' ';
			continue;
		}
		message[i] = ((message[i] - 65) + key) % 26;
		message[i] += 65;
	}
	message[arrlen] = '\0';
	return message;
}

char* rotdecr(char ciph[], int key, size_t arrlen){
	for(int i = 0; i < arrlen; i++){
		if(ciph[i] == ' '){
			ciph[i] = ' ';
			continue;
		}
		ciph[i] = ((ciph[i] - 65) - key) % 26;
		ciph[i] += 65;
	}
	ciph[arrlen] = '\0';
	return ciph;
}

char* subencr(char message[], size_t arrlen){
	for(int i = 0; i < arrlen; i++){
		if(message[i] == ' '){
			message[i] = ' ';
			continue;
		}
		switch(message[i]){
			case 'A': message[i] = _A;
			break;
			case 'B': message[i] = _B;
			break;
			case 'C': message[i] = _C;
			break;
			case 'D': message[i] = _D;
			break;
			case 'E': message[i] = _E;
			break;
			case 'F': message[i] = _F;
			break;
			case 'G': message[i] = _G;
			break;
			case 'H': message[i] = _H;
			break;
			case 'I': message[i] = _I;
			break;
			case 'J': message[i] = _J;
			break;
			case 'K': message[i] = _K;
			break;
			case 'L': message[i] = _L;
			break;
			case 'M': message[i] = _M;
			break;
			case 'N': message[i] = _N;
			break;
			case 'O': message[i] = _O;
			break;
			case 'P': message[i] = _P;
			break;
			case 'Q': message[i] = _Q;
			break;
			case 'R': message[i] = _R;
			break;
			case 'S': message[i] = _S;
			break;
			case 'T': message[i] = _T;
			break;
			case 'U': message[i] = _U;
			break;
			case 'V': message[i] = _V;
			break;
			case 'W': message[i] = _W;
			break;
			case 'X': message[i] = _X;
			break;
			case 'Y': message[i] = _Y;
			break;
			case 'Z': message[i] = _Z;
			break;
			default: message[i] = '\0';
			break;
		}
	}
	message[arrlen] = '\0';
	return message;
}

char* subdecr(char ciph[], size_t arrlen){
	for(int i = 0; i < arrlen; i++){
		if(ciph[i] == ' '){
			ciph[i] = ' ';
			continue;
		}
		switch(ciph[i]){
			case _A: ciph[i] = 'A';
			break;
			case _B: ciph[i] = 'B';
			break;
			case _C: ciph[i] = 'C';
			break;
			case _D: ciph[i] = 'D';
			break;
			case _E: ciph[i] = 'E';
			break;
			case _F: ciph[i] = 'F';
			break;
			case _G: ciph[i] = 'G';
			break;
			case _H: ciph[i] = 'H';
			break;
			case _I: ciph[i] = 'I';
			break;
			case _J: ciph[i] = 'J';
			break;
			case _K: ciph[i] = 'K';
			break;
			case _L: ciph[i] = 'L';
			break;
			case _M: ciph[i] = 'M';
			break;
			case _N: ciph[i] = 'N';
			break;
			case _O: ciph[i] = 'O';
			break;
			case _P: ciph[i] = 'P';
			break;
			case _Q: ciph[i] = 'Q';
			break;
			case _R: ciph[i] = 'R';
			break;
			case _S: ciph[i] = 'S';
			break;
			case _T: ciph[i] = 'T';
			break;
			case _U: ciph[i] = 'U';
			break;
			case _V: ciph[i] = 'V';
			break;
			case _W: ciph[i] = 'W';
			break;
			case _X: ciph[i] = 'X';
			break;
			case _Y: ciph[i] = 'Y';
			break;
			case _Z: ciph[i] = 'Z';
			break;
			default: ciph[i] = '\0';
			break;
		}
	}
	ciph[arrlen] = '\0';
	return ciph;
}

void printerr(){
	printf("USAGE: ./progname selection optional_key \"string_to_decrypt\"\n");
	printf("Selection options:\n (1)Rotation Encrypt\n (2)Rotation Decrypt\n (3)Substitution Encrypt\n (4)Substitution Decrypt\n");
	printf(" (5)Rotation Decrypt Cipher Text Only\n (6)Substitution Decrypt Cipher Text Only\n");
	printf("-END ERROR MESSAGE-\n");
}