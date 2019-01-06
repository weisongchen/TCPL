#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, nw, nl, nc, state;

    nw = nl = nc = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n') {
            nl++;
        }
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            nw++;
            state = IN;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}