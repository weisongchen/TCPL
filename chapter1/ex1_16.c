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
        printf("%3d: %s", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("\nThe longest line is\n%d: %s", max, longest);

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

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}