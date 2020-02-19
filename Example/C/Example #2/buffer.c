# include <stdio.h>
# include "editor.h"

/*
Clears the buffer
*/
void clearBuffer(FileBuffer *buf) {
    int i;
    for (i = 0 ; i < (*buf).n ; i++) {
        (*buf).lines[i][0] = '\0';
    }
    (*buf).n = 0;
}

/*
List the buffer
*/
void listBuffer(FileBuffer *buf) {
    int i;
    for (i = 0 ; i < (*buf).n ; i++) {
        printf("%d\t%s\n", i,  (*buf).lines[i]);
    }
}