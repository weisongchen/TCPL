#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10   /* default # of lines to print */
#define LINES    100  /* max # of lines to print     */
#define MAXLEN   100  /* max length of an input line */

void error(char *s);
int getLine(char *s, int lim);


/* print last n lines of the input */
int main(int argc, char *argv[])
{
    char *p;
    char *buf;               /* pointer to large buffer */
    char *bufend;            /* end of the buffer       */
    char line[MAXLEN];       /* current input line      */
    char *lineptr[LINES];    /* pointers to lines read  */
    int first, i, last, len, n, nlines;

    if (argc == 1)
        n = DEFLINES;
    else if (argc == 2 && (*++argv)[0] == '-')
        n = atoi(argv[0]+1);
    else
        error("Usage: tail [-n]\n");

    if (n < 1 || n > LINES)
        n = LINES;           /* unreasonable value for n ? */
    for (i = 0; i < LINES; i++)
        lineptr[i] = NULL;
    if ((p = buf = malloc(LINES * MAXLEN)) == NULL)
        error("tail: cannot allocate buf");
    bufend = buf + LINES * MAXLEN;
    last = 0;                /* index of last line read   */
    nlines = 0;              /* number of lines read      */
    while ((len = getLine(line, MAXLEN)) > 0) {
        if (p + len + 1 >= bufend)
            p = buf;         /* buffer wrap around        */
        lineptr[last] = p;
        strcpy(lineptr[last], line);
        if (++last >= LINES)
            last = 0;        /* ptrs to buffer wrap around */
        p += len + 1;
        nlines++;
    }
    if (n >= nlines)
        n = nlines;          /* req. lines more than rec ? */
    first = last - n;
    if (first < 0)
        first += LINES;
    for (i = first; n-- > 0; i = (i + 1) % LINES)
        printf("%s", lineptr[i]);

    return 0;
}


/* getLine: read next line from input */
int getLine(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* error: print error message and exit */
void error(char *s) {
    printf("%s", s);
    exit(1);
}