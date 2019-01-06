#include <stdio.h>

#define MAXLINE 1000

/* function prototypes */
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%s", longest);

    return 0;
}

/* This is the longest line in this source file, this is the long line in this source file */
int getLine(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c != EOF) {
            if (c != '\n')
                s[i] = c;
            else
                break;
        } else {
            break;
        }
    }
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\n')
        ++i;
}
