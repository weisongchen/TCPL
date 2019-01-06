#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp);

int main(int argc, char *argv[])
{
    FILE *fp;
    char *prog;

    prog = argv[0];
    if (argc == 1)
        filecopy(stdin, stdout);
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open file %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }

    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writting stdout\n", prog);
        exit(2);
    }

    exit(0);         /* exit(expr) == return expr  */
}


void filecopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}

