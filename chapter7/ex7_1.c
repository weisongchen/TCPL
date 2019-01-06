#include <stdio.h>
#include <ctype.h>

/* I misunderstand the purpose of this question. */
int main(int argc, char *argv[])
{
    int c;

    while ((c = *(*argv)++)) {
        if (islower(c))
            putchar(toupper(c));
        else
            putchar(tolower(c));
    }
    putchar('\n');

    return 0;
}