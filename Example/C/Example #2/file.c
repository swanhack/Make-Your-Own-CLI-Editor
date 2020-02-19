# include <stdio.h>
# include "editor.h"

/*
Sets the filename
*/
void setFilename(char line[], char fn[]) {
    if (stringLength(line) < 3 || line[2] == ' ') {
        /* no filename given */
        if (stringLength(fn) == 0) {
            printf("No filename set.\n");
            return;
        }
    } else {
        /* filename given */
        stringCopy(fn, &line[2]);
    }
    printf("%s\n", fn);
}

/*
Reads the contents of a file into the buffer
*/
void readIntoBuffer(FileBuffer *buf, char line[], char fn[]) {
    if (fn[0] == '\0') {
        printf("No filename set.\n");
    } else {
        FILE *fp;
        fp = fopen(fn, "r");
        while (fgets(line, MAX_LENGTH, fp)) {
            stringCopy((*buf).lines[(*buf).n++], line);
        }
        fclose(fp);
    }
}

/*
Checks if a file exists
*/
int fileExists(char filename[]) {
    return fopen(filename, "r") ? TRUE : FALSE;
}

/*
Opens a file and appends it to the buffer
Makes the file if it did not already exist
*/
void openFile(FileBuffer *buf, char line[], char fn[]) {
    /* I don't like this method */
    if (stringLength(line) < 3 || line[2] == ' ') {
        if (fn[0] == '\0') {
            printf("No filename given or set.\n");
        } else {
            fileExists(fn) ? readIntoBuffer(buf, line, fn) : fopen(fn, "a");
        }
    } else {
        stringCopy(fn, &line[2]);
        fileExists(fn) ? readIntoBuffer(buf, line, fn) : fopen(fn, "a");
    }
}

/*
Writes the contents of buffer to file
*/
void writeFile(FileBuffer *buf, char fn[]) {
    FILE *fp;
    int i;
    fp = fopen(fn, "w");
    for (i = 0 ; i < (*buf).n ; i++) {
        fprintf(fp, "%s\n", (*buf).lines[i]);
    }
    fclose(fp);
}