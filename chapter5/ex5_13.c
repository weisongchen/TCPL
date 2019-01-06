#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN   1000    /* max length of each input line    */
#define DEFLINE  10      /* default number of lines to print */

char *lineptr[MAXLINES];

/* function prototypes */
int readlines(char *lineptr[], int nlines);
int getLine(char *s, int lim);
void error(char *msg);


int main(int argc, char *argv[])
{
    int n;
    int nlines = 0;

    if (argc == 1)
        n = DEFLINE;
    else if (argc == 2 && (*++argv)[0] == '-') {
        if ((n = atoi(*argv+1)) == 0)        /* n can be 0 here, if argument is like -a */
            n = DEFLINE;
    }
    else
        error("Usage: tail [-n]\n");

    nlines = readlines(lineptr, MAXLINES);    /* nlines == -1 ??? */
    if (n > nlines)
        n = nlines;
    for (int i = nlines - n; i < nlines; i++)
        printf("%s\n", lineptr[i]);

/* the solution is so simple, why should I think it is so complicated ???? */
    // while (--argc > 0) {
    //     if ((*++argv)[0] == '-') {
    //         if ((n = atof(++*argv)) != 0.0)
    //             argc = 1;        set argc to 1 to break out of while loop
    //         else
    //             n = DEFLINE;
    //     } else {
    //         argc = -1;
    //     }
    // }

    return 0;
}


int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    char *p;
    char *alloc(int);

    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
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

void error(char *msg) {
    printf("%s", msg);
    exit(1);
}