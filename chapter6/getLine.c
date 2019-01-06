#include <stdio.h>
#include <string.h>
#include "getch.h"

/* getLine: read one line from input and return its length */
int getLine(char *line, int lim) {
    int c;
    int i;
    for (i = 0; i < lim-1 && (c = getch()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

int trim(char *s) {
    int n;

    /* delete blanks at the end */
    for (n = strlen(s)-1; n >= 0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    }
    s[++n] = '\0';

    /* delete blanks at the beginning */
    for (n = 0; n < strlen(s); n++) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    }
    int i = 0;
    while ((s[i++] = s[n++]))
        ;

    return i - 1;
}