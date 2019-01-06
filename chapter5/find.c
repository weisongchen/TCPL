#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MAXLINE 1000

int getLine(char *line, int lim);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c;
    int except = 0;
    int number = 0;
    int found = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch(c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
        }
    }

    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else {
        while (getLine(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld: ", lineno);
                printf("%s", line);
                found++;
            }
        }
    }

    return found;
}


int getLine(char *line, int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}