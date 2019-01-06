#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c;
    FILE *fp;
    char *prog = argv[0];
    int page = 0;

    if (argc == 1)
        printf("Usage: %s [filename1] [filename2]...\n", prog);
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                printf("filename: %s\n", *argv);
                printf("page: %d\n", ++page);
                while ((c = getc(fp)) != EOF)
                    putc(c, stdout);
                if (argc > 1)
                    putchar('\f');
                fclose(fp);
            }
        }
    }

    return 0;
}