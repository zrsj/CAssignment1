/*Author: c3283006 (Zayne Jeffries)
  Description: header file for encryption/decryption project
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
/*maxfind():
	INPUTS: integer array of tallies, integer array indicating used information, array length
	RETURNS: integer (index of max)
	DESCRIPTION: finds the location of the largest number in an array of integers, saves it once found in an array and returns the index
	LIMITATIONS: none
*/
int maxfind(int search[], int used[], size_t arrlen);

/*printerr():
	INPUTS: none
	RETURNS: void (none)
	DESCRIPTION: prints an error message should input file not contain valid information
	LIMITATIONS: none
*/
void printerr();
/*charcheck():
	INPUTS: single char (m)
	RETURNS: integer, either 1 or 0
	DESCRIPTION: returns 1 if char m is found to be a special character, 0 if it is a letter
	LIMITATIONS: none
*/
int charcheck(char m);
/*rotencr():
	INPUTS: char array with message, integer specifying key, length of message
	RETURNS: encrypted message array
	DESCRIPTION: encrypts message contained within message string using key to specify rotational shift
	LIMITATIONS: none
*/
char* rotencr(char message[], int key, size_t arrlen);
/*rotdecr():
	INPUTS: char array with ciphertext, integer specifying key, length of message
	RETURNS: decrypted ciphertext array
	DESCRIPTION: decrypts ciphertext contained within ciphertext string using key to specify rotational shift
	LIMITATIONS: if encrypted with rotencr, the same key value must be used for this function
*/
char* rotdecr(char ciph[], int key, size_t arrlen);
/*subencr():
	INPUTS: char array with message, length of message
	RETURNS: encrypted message array
	DESCRIPTION: encrypts message contained within message string using a series of letter substitutions
	LIMITATIONS: none
*/
char* subencr(char message[], size_t arrlen);
/*subdecr():
	INPUTS: char array with ciphertext, length of message
	RETURNS: decrypted ciphertext array
	DESCRIPTION: decrypts ciphertext containted within ciphertext string using a series of letter substitutions
	LIMITATIONS: must have been encrypted by rotencr
*/
char* subdecr(char ciph[], size_t arrlen);
/*ciphrotdecr():
	INPUTS: char array with ciphertext, length of ciphertext
	RETURNS: potentially decrypted ciphertext array
	DESCRIPTION: attempts to decrypt rotational ciphertext encrypted with an unknown rotational key
	LIMITATIONS: may not correctly decrypt entire message
*/
char* ciphrotdecr(char ciph[], size_t arrlen);
/*ciphsubdecr():
	INPUTS: char array with ciphertext, length of ciphertext
	RETURNS: potentially decrypted ciphertext array
	DESCRIPTION: attempts to decrypt substitutional ciphertext encrypted with an unknown substitution
	LIMITATIONS: may not correctly decrypt entire message
*/
char* ciphsubdecr(char ciph[]);
/*Function Implementations*/
int maxfind(int search[], int used[], size_t arrlen){
	int max = 0, max_ind = 0, i;
	for(i = 0; i < arrlen; i++){
		if(search[i] > max && used[i] != 1){
			max = search[i];
			max_ind = i;
		}
	}
	used[max_ind] = 1;
	return max_ind;
}

int charcheck(char m){
	char specials[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '_', '+', '{', '}', '|', '~', '`', ':', ';', 
		'<', '>', '?', ',', '.', '/', '\'', '\"', ' '};
	for(int i = 0; i < strlen(specials); i++){
		if(m == specials[i])
			return 1;
	}
	return 0;
}

void printerr(){
	printf("USAGE: ./progname input.txt\n");
	printf("Selection options:\n (1)Rotation Encrypt\n (2)Rotation Decrypt\n (3)Substitution Encrypt\n (4)Substitution Decrypt\n");
	printf(" (5)Rotation Decrypt Cipher Text Only\n (6)Substitution Decrypt Cipher Text Only\n");
	printf("-END ERROR MESSAGE-\n");
}

char* rotencr(char message[], int key, size_t arrlen){
	for(int i = 0; i < arrlen; i++){
		if(charcheck(message[i])){
			message[i] = message[i];
			continue;
		}
		message[i] = abs((message[i] - 65) + key) % 26;
		message[i] += 65;
	}
	message[arrlen] = '\0';
	return message;
}

char* rotdecr(char ciph[], int key, size_t arrlen){
	for(int i = 0; i < arrlen; i++){
		if(charcheck(ciph[i])){
			ciph[i] = ciph[i];
			continue;
		}
		ciph[i] = abs((ciph[i] - 65) - key) % 26;
		ciph[i] += 65;
	}
	ciph[arrlen] = '\0';
	return ciph;
}

char* subencr(char message[], size_t arrlen){
	for(int i = 0; i < arrlen; i++){
		if(message[i] == ' ')
			continue;
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
		if(ciph[i] == ' ' || ciph[i] == '.' || ciph[i] == ',' || ciph[i] == ';')
			continue;
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

char* ciphrotdecr(char ciph[], size_t arrlen){
	//count letter freq
	int lfreq[26] = {}; //holds frequency of letters counted from ciphertext, 26 size corresponding to all letters of the alphabet
	int used[26] = {}; //holds 1 if used, 0 if not yet used corresponding to the letter
	char letters[] = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'R', 'H', 'D', 'L', 'U', 'C', 'M', 'F', 'Y', 'W', 'G', 'P', 'B', 'V', 'K', 'X', 'Q', 'J', 'Z'};
	int i, currentletter = 0, max = 0;
	for(i = 0; i < arrlen; i++){
		if(charcheck(ciph[i])){
			continue;
		}
		lfreq[abs((ciph[i] - 65))]++;
	}
	//assign highest freq to corresponding english lang char
	for(i = 0; i < 26; i++){
		max = maxfind(lfreq, used, 26);
		for(int j = 0; j < arrlen; j++){
			if(abs(ciph[j] - 65) == max)
				ciph[j] = letters[currentletter];
		}
		currentletter++;
	}
	ciph[arrlen] = '\0';
	return ciph;
}

/*char* ciphsubdecr(){

}*/