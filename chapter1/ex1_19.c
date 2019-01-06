#include <stdio.h>

#define MAXLINE 1000

/* function prototypes */
int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[], int len);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%3d: %s", len, line);
    }

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
    while ((to[i] = from[i]) != EOF)
        ++i;
}

/* reverse characters' order in s */
void reverse(char s[], int len) {
    /* assume the newline character at the end of the line */
    /* do not reverse the '\n' character at the end of the line */
    len = len - 1;
    for (int i = 0; i < len / 2; ++i) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }

}