# define MAX_LINE 1000
# define MAX_LENGTH 256

# define TRUE 1
# define FALSE 0

typedef struct FileBuffer {
    int n;
    char lines[MAX_LINE][MAX_LENGTH];
} FileBuffer;

/* main.c */

int main(int argc, char const *argv[]);

/* file.c */

int fileExists(char filename[]);
void setFilename(char line[], char fn[]);
void openFile(FileBuffer *buf, char line[], char fn[]);
void readIntoBuffer(FileBuffer *buf, char line[], char fn[]);
void writeFile(FileBuffer *buf, char fn[]);

/* string.c */

int getLine(char line[], int max);
int stringLength(char line[]);
void stringCopy(char to[], char from[]);
void stringSplit(char token[], char line[], char t);

/* buffer.c */

void clearBuffer(FileBuffer *buf);
void listBuffer(FileBuffer *buf);

/* misc.c */

void changePrompt(char *prompt, char line[]);