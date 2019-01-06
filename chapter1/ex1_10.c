#include <stdio.h>

#define INVALIDCHAR 'a'

int main()
{
    int c, n;

    n = INVALIDCHAR;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
           c = '\\';
           n = 't';
        }
        if (c == '\b') {
            c = '\\';
            n = 'b';
        }
        if (c == '\\') {
            c = '\\';
            n = '\\';
        }
        putchar(c);
        if (n != INVALIDCHAR) {
            putchar(n);
            n = INVALIDCHAR;   /* set n back to its original state */
        }
    }

    return 0;
}