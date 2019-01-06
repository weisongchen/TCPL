#include <stdio.h>

#define NOBLANK 'a'

int main()
{
    int c, lastic;

    lastic = NOBLANK;
    while ((c = getchar()) != EOF) {
        if (c != ' ' || lastic != ' ')
            putchar(c);
        lastic = c;
    }

    return 0;
}
