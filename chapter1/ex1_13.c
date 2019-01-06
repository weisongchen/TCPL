#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORDS 100

int main()
{
    int i, c, nc, state;
    int nwords[MAXWORDS];

    for (i = 0; i < MAXWORDS; i++)
        nwords[i] = 0;

    state = OUT;
    i = nc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                nwords[i++] = nc;
                nc = 0;
            }
            state = OUT;
        } else {
            if (state == OUT)
                state = IN;
            ++nc;
        }
    }

    int j;
    for (i = 0; i < MAXWORDS && nwords[i] != 0; i++) {
        for (j = 0; j < nwords[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}