#include <stdio.h>

int main()
{
    int c, cs;

    cs = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            cs++;
        }
    }
    printf("cs = %d\n", cs);

    return 0;
}