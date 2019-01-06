#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

// char buf[BUFSIZE]; /* char type can't handle EOF (type int) */
static int buf[BUFSIZE];
static int bufp = 0;


int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


void ungets(char s[]) {
    int len = strlen(s) - 1;
    for (int i = 0; s[i] != '\0'; i++) {
        ungetch(s[len - i]);
    }
}