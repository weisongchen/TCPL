#include <stdio.h>

#define N 4;

int main()
{
    int c, i;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i < N; ++i)
                putchar(' ');
        } else {
            putchar(c);
        }
    }

    return 0;
}