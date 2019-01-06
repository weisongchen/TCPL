/*
 * File: ex1_23solution.c
 * -----------------------
 * This program can't handle single line comment (//).
 * Add single line comment functionality.
 * not a good solution, if the last line of source file is an
 * incomplete comment like this: /* comment here...
 * the program will loop forever.
 */
#include <stdio.h>

/* function prototypes */
void rcomment(int c);
void inComment(void);
void echoQuote(int c);

/* remove all comments from a valid C program */
int main()
{
    int c;

    while ((c = getchar()) != EOF)
        rcomment(c);

    return 0;
}


/* rcomment: read each character, remove the comments */
void rcomment(int c) {
    int d;

    if (c == '/') {
        if ((d = getchar()) == '*')
            inComment();               /* beginning comment */
        else if (d == '/') {           /* another slash     */
            putchar(c);
            rcomment(d);
        } else {
            putchar(c);
            putchar(d);
        }
    } else if (c == '\'' || c == '\"') {
        echoQuote(c);
    } else {
        putchar(c);
    }
}

/* inComment: inside of a valid comment */
/* This function can't deal with incomplete comment like
 * this /* comment....doesn't has the end comment token
 */
void inComment(void) {
    int c, d;

    c = getchar();                   /* prev character */
    d = getchar();                   /* curr character */
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}

/* echoQuote: echo characters within quotes */
void echoQuote(int c) {
    int d;

    putchar(c);
    /* search for end */
    while ((d = getchar()) != c) {
        putchar(d);
        if (d == '\\')
            putchar(getchar());       /* ignore escape seq */
    }
    putchar(d);
}