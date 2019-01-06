#include <stdio.h>

#define DIGITNUM 10

int main()
{
    int c, i, nwhite, nother;
    int ndigit[DIGITNUM];

    nwhite = nother = 0;
    for (i = 0; i < DIGITNUM; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;
    }
    printf("digits = ");
    for (i = 0; i < DIGITNUM; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}