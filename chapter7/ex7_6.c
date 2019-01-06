#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char *prog = argv[0];
    char *file1, *file2;
    char line1[MAXLEN];
    char line2[MAXLEN];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s [filename1] [filename2]\n", prog);
        exit(1);
    } else {
        if ((fp1 = fopen((file1 = *++argv), "r")) == NULL) {
            fprintf(stderr, "%s: can't open file %s\n", prog, file1);
            exit(2);
        } else if ((fp2 = fopen((file2 = *++argv), "r")) == NULL) {
            fprintf(stderr, "%s: can't open file %s\n", prog, file2);
            exit(3);
        } else {
            while (fgets(line1, MAXLEN, fp1) && fgets(line2, MAXLEN, fp2)) {
                if (strcmp(line1, line2) != 0) {
                    printf("%s: %s", file1, line1);
                    printf("%s: %s", file2, line2);
                    exit(0);
                }
            }
        }
    }

    return 0;
}