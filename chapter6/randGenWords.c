#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define LOW 0
#define HIGH 25
#define MAXLEN 20           /* max length of a word */
#define MINLEN 1            /* min length of a word */
#define MAXWORD 1000

char *randWord(void);

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < MAXWORD; i++)
        printf("%s\n", randWord());

    return 0;
}

char *randWord(void) {
    char *word;
    int len;

    len = rand() % (MAXLEN - MINLEN + 1) + MINLEN;    /* word's length in range of 0~20 */
    word = (char *)malloc(len+1);
    for (int i = 0; i < len; i++) {
        word[i] = rand() % (HIGH - LOW + 1) + LOW + 'a';  /* random char 'a' ~ 'z' */
    }
    word[len] = '\0';
    return word;
}