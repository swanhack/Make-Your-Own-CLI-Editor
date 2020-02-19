# include "editor.h"

int stringLength(char line[]);

/*
Changes the prompt
*/
void changePrompt(char *p, char line[]) {
    *p = stringLength(line) < 3 ? '>' : line[2];
}