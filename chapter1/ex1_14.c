#include <stdio.h>
#include <ctype.h>

#define CHARLEN 256

/* function prototypes */
int findChar(char s[], char ch);

int main()
{
    int c, index;
    char chTable[CHARLEN];
    int chFrequency[CHARLEN];

    /* initialization */
    for (int i = 0; i < CHARLEN; i++) {
        chTable[i] = '\0';
        chFrequency[i] = 0;
    }

    index = 0;
    while ((c = getchar()) != EOF) {
        int i = findChar(chTable, c);
        if (i >= 0) {
            ++chFrequency[i];
        } else {
            chTable[index] = c;
            chFrequency[index++] = 1;
        }
    }

    for (int i = 0; chTable[i] != '\0'; i++) {
        if (isprint(chTable[i])) {
            printf("%3d  -  %c -  %3d : ", i, chTable[i], chFrequency[i]);
        } else {
            printf("%3d  -     -  %3d : ", i, chFrequency[i]);
        }
        /* print histogram using '*'  */
        for (int j = 0; j < chFrequency[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}


int findChar(char s[], char ch) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (ch == s[i])
            return i;
    }
    return -1;
}