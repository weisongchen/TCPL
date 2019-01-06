#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            putchar('~');
        else if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else {
            putchar(c);
        }
    }

    return 0;
}