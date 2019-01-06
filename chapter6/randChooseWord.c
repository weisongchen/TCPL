#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define LOW 0
#define HIGH 25
#define MAXLEN 20               /* max length of a word */
#define MINLEN 1                /* min length of a word */
#define MAXWORD 100             /* max number of chars in a word     */
#define MAXLISTLEN 130000       /* max number of word stored in list */
#define SECONDS 0.01            /* time for generating random words  */

char *wordlist[MAXLISTLEN];     /* list for storing dictionary words */
int nwords = 0;                 /* number of words in the list       */

char *randWord(void);
int getch(void);
void ungetch(int c);
int getword(char *word, int lim);
int comment(void);


int main(int argc, char *argv[])
{
    int c;
    char word[MAXWORD];

    srand((unsigned)time(NULL));     /* set pseudo random number generator seed */
    while ((c = getword(word, MAXWORD)) != EOF) {
        if (isalpha(c) || c == '_' || c == '#') {
            char *w = (char *)malloc(strlen(word));
            if (w != NULL)
                wordlist[nwords++] = strcpy(w, word);
        }
    }

    for (int i = 0; i < nwords; i++) {
        printf("%s\n", wordlist[i]);
    }

    // time_t startTime = time(NULL);
    // while (1) {
    //     double elasedTime = difftime(time(NULL), startTime);
    //     if (elasedTime > SECONDS)
    //         break;
    //     printf("%s\n", randWord());
    // }

    return 0;
}

char *randWord(void) {
    printf("nwords = %d\n", nwords);
    int index = rand() % (nwords - 0 + 1) + 0;   /* random number between [0, nwords] */
    printf("index = %d\n", index);
    return wordlist[index];
}


/* read next word or character from input */
int getword(char *word, int lim) {
    int c, d;
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#') {
        for ( ; --lim > 0; w++) {
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
    } else if (c == '\'' || c == '\"') {
        for ( ; --lim > 0; w++) {
            if ((*w = getch()) == '\\')
                *++w = getch();
            else if (*w == c) {
                w++;
                break;
            } else if (*w == EOF) {
                break;
            }
        }
    } else if (c == '/') {
        if ((d = getch()) == '*')
            c = comment();
        else
            ungetch(d);
    }

    *w = '\0';
    return c;
}

/* comment: skip over comment and return a character */
int comment(void) {
    int c;
    while ((c = getch()) != EOF) {
        if (c == '*') {
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
        }
    }
    return c;
}