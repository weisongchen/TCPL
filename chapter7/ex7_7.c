#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int except = 0;
int number = 0;

void findpattern(char *fname, char *pattern);
void handlematch(FILE *fp, char *fname, char *pattern);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    char *prog = argv[0];
    int c;

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
                fprintf(stderr, "%s: illegal option %c\n", prog, c);
                argc = 0;
                break;
            }
        }
    }

    if (argc == 1) {
        findpattern("", *argv);     /* no file for reading in      */
    } else if (argc > 1) {          /* at least has one input file */
        char *pattern = *argv;
        while (--argc > 0) {
            findpattern(*++argv, pattern);
        }
    } else {
        fprintf(stderr, "Usage: %s [-x] [-n] pattern [file...]\n", prog);
        exit(2);
    }

    return 0;
}

void findpattern(char *fname, char *pattern) {
    FILE *fp;

    if (strlen(fname) == 0) {
        handlematch(stdin, fname, pattern);
    } else if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "can't open %s\n", fname);
        exit(1);
    } else {
        handlematch(fp, fname, pattern);
        fclose(fp);
    }
}

void handlematch(FILE *fp, char *fname, char *pattern) {
    char line[MAXLINE];

    int lineno = 0;
    while (fgets(line, MAXLINE, fp) != NULL) {
        lineno++;
        if ((strstr(line, pattern) != NULL) != except) {
            if (strlen(fname) != 0)
                printf("[%s] ", fname);
            if (number)
                printf("%3d: ", lineno);
            printf("%s", line);
        }
    }
}
