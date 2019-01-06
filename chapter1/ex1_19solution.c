#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char s[]);

int main()
{
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
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

void reverse(char s[]) {
    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0')
        ++i;
    --i;
    if (s[i] == '\n')
        --i;
    j = 0;
    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}