#include <stdio.h>

int main()
{
    int c, ct;

    ct = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            ct++;
        }
    }
    printf("ct = %d\n", ct);

    return 0;
}