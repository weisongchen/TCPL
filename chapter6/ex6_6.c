#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "hashtable.h"
#include "getch.h"


#define MAXWORD  100
#define GOODMAN  {\
                  for (int i = 0; i < 10; i++) { \
                    printf("Hello world\n");\
                  }\
                 }


void getDefn(void);
void removeDefn(void);
int getword(char *word, int lim);
int getLine(char *line, int lim);
int trim(char *s);


/*
 * Add functionality that can handle char '\\' at the end of macro
 * This program can't handle macro with parameters! (name with parentheses)
 */

int main(int argc, char *argv[])
{
    char word[MAXWORD];
    struct nlist *np;
    char *name;
    char *defn;
    int c;

    GOODMAN;  /* macro that print "hello world\n" to console 10 times */

    while ((c = getch()) != EOF) {
        if (isspace(c))
            putchar(c);
        else {
            ungetch(c);
            if (getword(word, MAXWORD) != EOF) {
                if ((np = lookup(word)))
                    printf("%s", np->defn);
                else if (strcmp(word, "#define") == 0) {
                    printf("%s", word);
                    getDefn();
                } else if (strcmp(word, "#undef") == 0) {
                    printf("%s", word);
                    removeDefn();
                } else {
                    printf("%s", word);
                }
            }
        }
    }

    return 0;
}


/* go through source file and install name and defn if found one pair */
void getDefn(void) {
    char word[MAXWORD];
    char name[MAXWORD];
    char defn[MAXWORD];
    int c;
    int len;
    int i, j;

    while ((c = getch()) != EOF && isspace(c))
        putchar(c);
    if (!isspace(c))
        ungetch(c);
    while (getword(word, MAXWORD) != EOF) {
        printf("%s", word);
        if (isalpha((c = word[0])) || c == '_') {
            strcpy(name, word);
            break;
        }
    }

    i = 0;
    do {
        if (getLine(word, MAXWORD) > 0) {
            printf("%s", word);
            if (trim(word) > 0) {
                if ((len = strlen(word)) > 0) {
                    for (j = 0; i < MAXWORD-1 && j < len; i++, j++)
                        defn[i] = word[j];
                    defn[i-1] = ' ';      /* replace '\\' with ' ' */
                    defn[i] = '\0';
                }
            }
        }
    } while (word[len-1] == '\\');

    if (install(name, defn) == NULL) {
        fprintf(stderr, "can't install %s and %s in hashtab\n", name, word);
        exit(2);
    }
}

/* remove a definition from hashtable */
void removeDefn(void) {
    char word[MAXWORD];

    if (getLine(word, MAXWORD) > 0) {
        printf("%s", word);
        if (trim(word) > 0)
            undef(word);
        else
            fprintf(stderr, "error: expecting a definition after #undef\n");
    } else {
        fprintf(stderr, "error: expecting a definition after #undef\n");
    }
}
