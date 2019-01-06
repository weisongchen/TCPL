#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

int getLine(char *line, int lim);
int isBlankLine(char *line);

int main(int argc, char *argv[])
{
    int len;
    char line[MAXLEN];

    while ((len = getLine(line, MAXLEN)) > 0) {
        if (!isBlankLine(line))
            printf("%s", line);
    }

    return 0;
}

int isBlankLine(char *line) {
    int i;

    for (i = 0; line[i] != '\0'; i++)
        if (!isspace(line[i]))
            return 0;      /* find a non-blank char */
    return 1;              /* a blank line, no any non-space char */
}

int getLine(char *line, int lim) {
    int i, c;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}