// made by meetowl (Michael)
// this took me ~3h because I forgot how to properly reference pointers
// 30% of the time works 100% of the time, ask me if you're confused about something.
// compile with:
// `gcc -o ced editor.c`
// run with:
// `./ced [<filename>]`

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 999999
#define MAX_CHAR 180

#define MAX_TOKENS 8
#define MAX_TOKEN_STR 256

// File buffer
struct {
	unsigned int lineTotal;
	char lines[MAX_LINES][MAX_CHAR];
	char buffer_name[128];
} typedef buffer_t;

// Token buffer
struct {
	char operation;
	char tokens[MAX_TOKENS][MAX_TOKEN_STR];
	
} typedef token_t;

// Loads file into buffer
buffer_t * openFile(char filename[]) {
	FILE *file = fopen(filename, "r");
	if (!file) {
		return 0;
	}

	buffer_t *buf = malloc(sizeof(buffer_t));
	char c = 0;
	unsigned int currentLineNum = 0;
	unsigned int currentCharNum = 0;
	while (EOF != (c = fgetc(file))) {
		if (c == '\n') {
			buf->lines[currentLineNum][currentCharNum] = '\0';
			currentLineNum++;
			currentCharNum = 0;
		} else {
			buf->lines[currentLineNum][currentCharNum] = c;
			currentCharNum++;
		}
	}

	buf->lines[currentLineNum][currentCharNum] = EOF;

	buf->lineTotal = currentLineNum;
	fclose(file);

	return buf;
}

// String to uint 
unsigned int getUnsignedInt(const char str[]) {
	unsigned int out = 0;
	int multiplier = 1;
	int i = 0;
	while (str[i] != '\0') i++;
	i--;
	while (i >= 0) {
		out += (str[i] - '0') * multiplier;
		multiplier *= 10;
		i--;
	}
	return out;
}
							   
// Prints ranges of buffer
void printBuffer(buffer_t *buf, unsigned int start, unsigned int end) {
	if (!buf) {
		printf("No file loaded.\n");
		return;
	}

	for (int i = start-1; i <= end-1; i++) {
		printf("%d\t%s\n", i+1, buf->lines[i]);
	}
	return;
}

// Reads <num> tokens
int readTokens(token_t *tt, int num) {
	for (int i = 0; i < num; i++) {
		char c = getc(stdin);
		int j = 0;
		while (' ' != c && '\n' != c) {
			tt->tokens[i][j] = c;
			j++;
			c = getc(stdin);
		}
		tt->tokens[i][j] = '\0';
	}
	return 0;
}

// Reads <num> string ("<token>")
int readString(token_t *tt, int num) {
	for (int i = 0; i < num; i++) {
		char c = getc(stdin);
		if (c != '\"') return 1;
		int j = 0;
		while ('\"' != (c = getc(stdin))) {
			tt->tokens[i][j] = c;
			j++;
		}
		if (c == EOF) return 2;
		tt->tokens[i][j] = '\0';
	}
	// eat the newline
	getc(stdin);
	return 0;
}

// Reads tokens to token structure
int getStdinToken(token_t *tt) {
	int tokenNum = 0;
	int charNum = 0;
	char c = getc(stdin);
	tt->operation = c;

	c = getc(stdin);
	while (' ' != c && c != '\n');
	switch (tt->operation) {
	case 'l':
		readTokens(tt, 2);
		break;
	case 'a':
		readString(tt, 1);
		break;
	case 'f':
		readString(tt, 1);
		break;
	default:
		break;
	}
	return 0;
}

// Prints whether the buffer has been loaded to buffer
void printBufferStatus(buffer_t *b, char filename[]) {
	if (b) {
		printf("status: loaded %s\n", filename);
	} else {
		printf("error: could not load %s\n", filename);
	}
}

// Appends to end of file
int appendToBuf(buffer_t *b, char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		b->lines[b->lineTotal][i] = str[i];
		i++;
	}
	b->lineTotal++;
	return 0;
}

// Writes buffer to file
int writeBuffer(buffer_t *b, char filename[]) {
	FILE *file = fopen(filename, "w+");
	for (int i = 0; i < b->lineTotal; i++) {
		fputs(b->lines[i], file);
		fputc('\n', file);
	}
	fclose(file);
	file = 0;
	return 0;
}


int main(int argc, char* argv[]) {
	buffer_t *b = 0;
	char filename[256];
	
	printf("Welcome to CLI editor! (C version)\n"	\
		   "What are your demands?\n");

	if (argc > 1) {
		//		printf("%s", &(argv[1][1]));
		//		exit(1);
		strcpy(filename, &(argv[1][0]));
		b = openFile(filename);
		printBufferStatus(b, filename);
	}

	int exitSig = 0;
	while (!exitSig) {
		printf("> ");
		token_t tt;
		getStdinToken(&tt);

		// This can be improved with enums / a hashmap 
		switch (tt.operation) {
			// No arguments
		case 'w': // write file (cannot write to alternative filename)
			writeBuffer(b, filename);
			break;
		case 'q': // quit
			exitSig = 1;
			break;
			// 2 arguments
		case 'l': // load a file
			printBuffer(b, getUnsignedInt(tt.tokens[0]),			\
						getUnsignedInt(tt.tokens[1]));
			break;
			// 1 string arguments
		case 'a': // append text
			appendToBuf(b, &(tt.tokens[0][0]));
			break;

		case 'f': // open file
			b = openFile(tt.tokens[0]);
			strcpy(filename, tt.tokens[0]);
			printBufferStatus(b, tt.tokens[0]);
			break;
		default:
			printf("error: unrecognized command %c", tt.operation);
			break;
		}
	}

	return 0;
}
