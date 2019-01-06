#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101
#define MAXWORD  100
#define GOODMAN  "I love programming"
static struct nlist *hashtab[101];

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);
void freenlist(struct nlist *p);
void establishTab();
void printHashtab(void);

char *strDup(char *s);
int trim(char *s);
int getword(char *word, int lim);
int comment(void);
int getch(void);
void ungetch(int c);
int getLine(char *line, int lim);


int main(int argc, char *argv[])
{
    char word[100];
    struct nlist *np;
    char *name;
    char *defn;
    int c;
    char *gm = "I love programming";

    while ((c = getch()) != EOF) {
        if (isspace(c))
            putchar(c);
        else {
            ungetch(c);
            if (getword(word, 100) != EOF) {
                if ((np = lookup(word)))
                    printf("%s", np->defn);
                else if (strcmp(word, "#define") == 0) {
                    printf("%s", word);
                    establishTab();
                } else {
                    printf("%s", word);
                }
            }
        }
    }

    return 0;
}


unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = 31 * hashval + *s;
    return hashval % 101;
}

struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0)
            return np;
    }
    return NULL;
}



struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *)malloc(sizeof(struct nlist));
        if (np == NULL || (np->name = strDup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free(np->defn);
    }

    if ((np->defn = strDup(defn)) == NULL)
        return NULL;
    return np;
}








void undef(char *s) {
    int h;
    struct nlist *prev, *np;

    prev = NULL;
    h = hash(s);
    for (np = hashtab[h]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0)
            break;
        prev = np;          
    }
    if (np != NULL) {
        if (prev == NULL)
            hashtab[h] = np->next;
        else
            prev->next = np->next;
        freenlist(np);
    }
}

void freenlist(struct nlist *p) {
    free(p->name);
    free(p->defn);
    free(p);
}

char *strDup(char *s) {
    char *p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}



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
        if ((d = getch()) == '*') {
            c = comment();
            *--w = '\0';    
            return '\0';
        }
        else
            ungetch(d);
    }

    *w = '\0';
    return c;
}


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

int getLine(char *line, int lim) {
    int c;
    int i;
    for (i = 0; i < lim-1 && (c = getch()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

int trim(char *s) {
    int n;

    
    for (n = strlen(s)-1; n >= 0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    }
    s[++n] = '\0';

    
    for (n = 0; n < strlen(s); n++) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    }
    int i = 0;
    while ((s[i++] = s[n++]))
        ;

    return i - 1;
}


void establishTab(void) {
    char word[100];
    char name[100];
    int c;

    while ((c = getch()) != EOF && isspace(c))
        putchar(c);
    if (!isspace(c))
        ungetch(c);
    while (getword(word, 100) != EOF) {
        printf("%s", word);
        if (isalpha(word[0])) {
            strcpy(name, word);
            break;
        }
    }
    if (getLine(word, 100) > 0) {
        printf("%s", word);
        if (trim(word) > 0) {
            if (install(name, word) == NULL) {
                fprintf(stderr, "can't install %s and %s in hashtab\n", name, word);
                exit(2);
            }
        }
    }
}


void printHashtab(void) {
    int i;
    struct nlist *np;

    for (i = 0; i < 101; i++) {
        if ((np = hashtab[i])) {
            for ( ; np; np = np->next) {
                printf("name = %s\n", np->name);
                printf("defn = %s\n", np->defn);
            }
        }
    }
}