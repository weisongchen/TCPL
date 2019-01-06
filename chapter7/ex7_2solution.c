#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100    /* max number of char in one line */
#define OCTLEN    6    /* length of an octal value       */

int inc(int pos, int n);

/* print arbitrary input in a sensible way */
int main(int argc, char *argv[])
{
    int c, pos;

    pos = 0;
    while ((c = getchar()) != EOF) {
        if (iscntrl(c) || c == ' ') {
            /* non-graphic or blank */
            pos = inc(pos, OCTLEN);
            printf(" \\%03o ", c);
            /* newline character ?? */
            if (c == '\n') {
                pos = 0;
                putchar('\n');
            }
        } else {
            /* graphic character */
            pos = inc(pos, 1);
            putchar(c);
        }
    }

    return 0;
}

/* inc: increment position counter for output */
int inc(int pos, int n) {
    if (pos + n < MAXLINE)
        return pos+n;
    else {
        putchar('\n');
        return n;
    }
}