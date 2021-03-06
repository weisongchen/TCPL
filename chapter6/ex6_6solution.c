#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "hashtable.h"

#define MAXWORD 100

void getdef(void);
void error(int n, char *s);
void skipblanks(void);
void ungets(char *s);
int getch(void);
void ungetch(int c);
void undef(char *name);

int getword(char *w, int lim);

/* simple version of #define processor */
/* This solution seems not to solve the problem... I don't know how it works ! */
int main(int argc, char *argv[])
{
    char w[MAXWORD];
    struct nlist *p;

    while (getword(w, MAXWORD) != EOF) {
        if (strcmp(w, "#") == 0)     /* beginning of direct */
            getdef();
        else if (!isalpha(w[0]))
            printf("%s", w);
        else if ((p = lookup(w)) == NULL)
            printf("%s", w);
        else
            ungets(p->defn);        /* push definition      */
    }

    return 0;
}

/* getdef: get definition and install it */
void getdef(void) {
    int c, i;
    char def[MAXWORD];
    char dir[MAXWORD];
    char name[MAXWORD];

    skipblanks();
    if (!isalpha(getword(dir, MAXWORD)))
        error(dir[0], "getdef: expecting a directive after #");
    else if (strcmp(dir, "define") == 0) {
        skipblanks();
        if (!isalpha(getword(name, MAXWORD)))
            error(name[0], "getdef: non-alpha - name expected");
        else {
            skipblanks();
            for (i = 0; i < MAXWORD-1; i++) {
                if ((def[i] = getch()) == EOF || def[i] == '\n')
                    break;        /* end of definition  */
            }
            def[i] = '\0';
            if (i <= 0)           /* no definition ?    */
                error('\n', "getdef: incomplete define");
            else                  /* install definition */
                install(name, def);
        }
    } else if (strcmp(dir, "undef") == 0) {
        skipblanks();
        if (!isalpha(getword(name, MAXWORD)))
            error(name[0], "getdef: non-alpha in undef");
        else
            undef(name);
    } else {
        error(dir[0], "getdef: expecting a directive after #");
    }
}

/* error: print error message and skip the rest of the line */
void error(int c, char *s) {
    printf("error: %s\n", s);
    while (c != EOF && c != '\n')
        c = getch();
}

/* skipblanks: skip blank and tab characters */
void skipblanks(void) {
    int c;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    ungetch(c);
}