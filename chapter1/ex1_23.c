/*
 * File: ex1_23.c
 * -----------------
 * This program can handle single line comment.(//)
 * but the ouput isn't as expected. character '\n' and ' ' handling.
 */

#include <stdio.h>

#define IN 1                             /* inside a comment  */
#define OUT 0                            /* outside a comment */

int main()
{
    int c, next, incomment, inString, onelineComment;

    incomment = OUT;      /* not in a comment */
    inString = OUT;
    onelineComment = OUT;
    while ((c = getchar()) != EOF) {
        if (incomment == OUT) {
            if (inString == OUT) {
                if (c == '\"' || c == '\'') {
                    inString = IN;
                    putchar(c);
                } else if (c == '/') {
                    next = getchar();
                    if (next == '*') {
                        incomment = IN;
                    } else if (next == '/') {
                        onelineComment = IN;
                        incomment = IN;
                    } else {
                        putchar(c);
                        putchar(next);
                    }
                } else {
                    putchar(c);
                }
            } else {
                putchar(c);
                if (c == '\\')
                    putchar(getchar());          /* ignore escape seq */
                if (c == '\"' || c == '\'')
                    inString = OUT;
            }
        } else {
            if (onelineComment == IN) {
                if (c == '\n') {
                    onelineComment = OUT;
                    incomment = OUT;
                }
            } else {
                if (c == '*') {
                    if (getchar() == '/')
                        incomment = OUT;
                }
            }
        }
    }

    return 0;
}