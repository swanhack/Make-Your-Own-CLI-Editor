# include <stdio.h>
# include "editor.h"

/*
Places line into memory, returns length
*/
int getLine(char line[], int max) {
    int c, i;
    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    line[i++] = '\n';
    line[i++] = '\0';
    return i;
}

/*
Returns the length of a string
*/
int stringLength(char line[]) {
    int i = 0;
    while (line[i] != '\0') {
        i++;
    }
    return i;
}

/*
Copies second string onto first
*/
void stringCopy(char to[], char from[]) {
    int i = 0;
    while (from[i] != '\n') {
        to[i] = from[i];
        i++;
    }
    to[i++] = '\0';
}

/*
Splits the string based on first occurence of c
*/
void stringSplit(char token[], char line[], char c) {
    int i, j;
    for (i = 0 ; line[i] != c ; ++i);
    for (j = 0 ; j < i ; j++) {
        token[j] = line[j];
    }
    token[j++] = '\0';
    j = 0;
    while (line[i++] != '\0') {
        line[j++] = line[i];
    }
}