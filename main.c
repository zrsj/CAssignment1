/*Author: c3283006 (Zayne Jeffries)
  Description: main file for encryption/decryption assignment
*/
#include "encdec.h"
#define OUT "file.txt"
#define MAX_BUFFER 1000
int main(int argc, char* argv[]){
	FILE* fp; //pointer to file type, filename specified through command line
	int sel = 0, key = 0, argsc = 0, charc = 0, iskey = 0; //any variable ending in c is a counter for their respective type
	char* args[3]; //seperate from command line arguments, these hold the arguments for the algorithms
	char* text; //used for storing message to be encrypted and writing it to output
	char c; //holds the currently read character from the text file
	for(int i = 0; i < 3; i++)
		args[i] = malloc(MAX_BUFFER); //dynamically allocate memory so that char* variables can be appended to
	fp = fopen(argv[1], "r");
	while((c = getc(fp)) != EOF){
		if(c == '#'){ //a key has been specified in the input file, set flag to true for key being present
			iskey = 1; 
			continue;	
		}
		if(c == ' ' && argsc < 2){ //indicates end of an argument reached and adds null escape character
			argsc++;
			args[argsc][charc++] = '\0';
			charc = 0; //reset for next argument such that array of next argument can be filled from the beginning
			continue;
		}
		if(c == '\n') continue; //skip all newlines in text file, input read in straight line
		args[argsc][charc++] = c;
	}
	charc = 0; //set back to 0 for later usage when reading output file
	sel = atoi(args[0]); //argument 0 must always be a selection variable
	key = (iskey)?atoi(args[1]):1; //iskey is a flag that determines whether or not a key has been passed to the program
	strcat(args[1], " "); //if the key was not specified, the first word of the message will be stored in args[1]
	text = (iskey)?strdup(args[2]):strcat(strdup(args[1]), strdup(args[2])); //if key is found, text is stored in args[2]. If not, concat args[1] and args[2]
	fclose(fp);
	size_t textlen = strlen(text);
	switch(sel){
		case 1:
			fp = fopen(OUT, "w"); 
			fprintf(fp, "%s\n", rotencr(text, key, textlen));
			printf("%s\n", text);
			break;
		case 2:
			fp = fopen(OUT, "r");
			while((c = getc(fp)) != EOF){
				text[charc++] = c;
			}
			fclose(fp);
			fp = fopen(OUT, "w");
			fprintf(fp, "%s\n", rotdecr(text, key, textlen));
			printf("%s\n", text);
			break;
		case 3:
			fp = fopen(OUT, "w");
			fprintf(fp, "%s\n", subencr(text, textlen));
			printf("%s\n", text);
			break;
		case 4: 
			fp = fopen(OUT, "r");
			while((c = getc(fp)) != EOF){
				text[charc++] = c;
			}
			fclose(fp);
			fp = fopen(OUT, "w");
			fprintf(fp, "%s\n", subdecr(text, textlen));
			printf("%s\n", text);
			break;
		case 5: 
			fp = fopen(OUT, "w");
			fprintf(fp, "%s\n", ciphrotdecr(text, textlen));
			printf("%s\n", text);
			break;
		case 6:
			break;
		default: 
			printerr();
			break;
	}
	fclose(fp);
	for(int i = 0; i < 3; i++){
		free(args[i]);
		args[i] = NULL;
	}
	return 0;
}
