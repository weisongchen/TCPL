#include <stdio.h>

#define MAXLINE 1000

/* function prototypes */
int getLine(char line[], int maxline);
int removeSpaceTab(char s[], int len);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        int length = removeSpaceTab(line, len);
        if (length >= 0)
            printf("%3d: %s", length, line);
    }

    return 0;
}


int getLine(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int removeSpaceTab(char s[], int len) {
    int i = len - 1;
    while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
        --i;
    if (i >= 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}