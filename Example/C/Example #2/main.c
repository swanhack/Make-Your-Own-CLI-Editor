/*
Contributed by Gnome
to compile  : clang -ansi *.c -o editor
to run      : ./editor
This does not accept command line arguments
*/

# include <stdio.h>
# include "editor.h"

FileBuffer buffer;
char line[MAX_LENGTH];
char filename[MAX_LENGTH];
char prompt = '>';

int main(int argc, char const *argv[]) {
    int exit = FALSE;

    while (!exit) {
        printf("%c ", prompt);
        getLine(line, MAX_LENGTH);
        switch (line[0]) {
        case 'a':
            while (getLine(line, MAX_LENGTH) >= 0 && line[0] != '.') {
                stringCopy(buffer.lines[(buffer.n)++], line);
            }
            break;

        case 'b':
            printf("%d\n", buffer.n);
            break;

        case 'e':
            clearBuffer(&buffer);
            openFile(&buffer, line, filename);
            break;

        case 'f':
            setFilename(line, filename);
            break;

        case 'l':
            listBuffer(&buffer);
            break;

        case 'p':
            changePrompt(&prompt, line);
            break;

        case 'q':
            exit = TRUE;
            break;

        case 'r':
            readIntoBuffer(&buffer, line, filename);
            break;

        case 'w':
            writeFile(&buffer, filename);
            break;

        default:
            printf("?\n");
            break;
        }
    }

    return 0;
}