#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000         /* maximum input line length */

void fpat(FILE *fp, char *fname, char *pattern, int except, int number);

/* find: print lines that match pattern from 1st argument */
int main(int argc, char *argv[])
{
    char pattern[MAXLINE];
    int c;
    int except = 0;
    int number = 0;
    FILE *fp;

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
                break;
            }
        }
    }

    if (argc >= 1)
        strcpy(pattern, *argv);
    else {
        fprintf(stderr, "Usage: find [-x] [-n] pattern [file...]\n");
        exit(1);
    }
    if (argc == 1)
        fpat(stdin, "", pattern, except, number);
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "find: can't open %s\n", *argv);
                exit(2);
            } else {
                fpat(fp, *argv, pattern, except, number);
                fclose(fp);
            }
        }
    }

    return 0;
}


void fpat(FILE *fp, char *fname, char *pattern, int except, int number) {
    char line[MAXLINE];
    int lineno = 0;

    while (fgets(line, MAXLINE, fp) != NULL) {
        lineno++;
        if ((strstr(line, pattern) != NULL) != except) {
            if (*fname)
                printf("%s - ", fname);
            if (number)
                printf("%3d: ", lineno);
            printf("%s", line);
        }
    }
}