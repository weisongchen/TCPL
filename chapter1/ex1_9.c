#include <stdio.h>

#define NONBLANK 'a'

int main()
{
    int c, sp;

    sp = NONBLANK;  /* avoid to using magic value like '\0' */
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            sp = c;
        } else {
            if (sp == ' ') {
                putchar(sp);
                sp = NONBLANK;   /* set sp to not space character */
            }
            putchar(c);
        }
    }

    return 0;
}