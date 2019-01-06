#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
int removeBlankTag(char s[]);

int main()
{
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0)
        if (removeBlankTag(line) > 0)
            printf("%s", line);

    return 0;
}


int getLine(char s[], int lim) {
    int c, i;
    int j = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        /*
         * when i >= lim - 2, characters would't be stored in s[], but reading
         * process is still going, so characters followed will be ignored.
         */
        if (i < lim - 2)
            s[j++] = c;
    }
    if (c == '\n') {
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}

/* remove trailing blanks and tabs from character string */
int removeBlankTag(char s[]) {
    int i = 0;

    while (s[i] != '\n')      /* find newline character */
        ++i;
    --i;                      /* back off from '\n' */
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if (i >= 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}