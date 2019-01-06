#include <stdio.h>

void comment(void);
void singleLineComment(void);
void inString(int c);

int main(int argc, char *argv[])
{
    int c, d;

    while ((c = getchar()) != EOF) {
        if (c == '/') {
            if ((d = getchar()) == '*')
                comment();
            else if (d == '/')
                singleLineComment();
            else {
                putchar(c);
                putchar(d);
            }
        } else if (c == '\'' || c == '\"') {
            inString(c);
        } else {
            putchar(c);
        }
    }

    return 0;
}

void comment(void) {
    int c, d;

    while ((c = getchar()) != EOF) {
        if (c == '*' && (d = getchar()) == '/')
            break;
    }
}

void singleLineComment(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            break;
    }
    if (c == '\n')
        putchar(c);      /* put a new line */
}

void inString(int c) {
    int ch;

    putchar(c);
    while ((ch = getchar()) != EOF) {
        putchar(ch);
        if (ch == '\\')
            putchar(getchar());
        if (ch == c)
            break;
    }
}