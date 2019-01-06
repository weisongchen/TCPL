#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"


static struct nlist *hashtab[HASHSIZE];

char *strDup(char *s);

unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = 31 * hashval + *s;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0)
            return np;
    }
    return NULL;
}


/*
 * the code is very small and compact, it remove many duplicated codes
 * you should learn to write code in this way!
 */
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

/*
 * my implementation. the code is terrible! not a good solution.
 * too many duplicated codes.
 */
/*
struct nlist *install(char *name, char *defn) {
    struct nlist *np;

    np = hashtab[hash(name)];
    if (np == NULL)
        return NULL;
    np = lookup(name);
    if (np == NULL) {
        np = (struct nlist *)malloc(sizeof(struct nlist));
        if (np == NULL)
            return NULL;
        np->name = strDup(name);
        if (np->name == NULL)
            return NULL;
        np->defn = strDup(defn);
        if (np->defn == NULL)
            return NULL;
        return np;
    } else {
        np->defn = strDup(defn);
        if (np->defn == NULL)
            return NULL;
        return np;
    }
}
*/

/*
 * my implementation of undef function.
 */
/*
void undef(char *name) {
    struct nlist *np;
    struct nlist *curor;
    unsigned hashval;

    if ((np = lookup(name)) != NULL) {
        hashval = hash(name);
        if ((cursor = hashtab[hashval]) == np) {
            hashtab[hashval] = np->next;
        } else {
            for ( ; cursor != NULL cursor = cursor->next) {
                if (cursor->next == np)
                    cursor->next = np->next;
            }
        }
        freenlist(np);
    }
}
*/

/* undef: remove a name and definition from the table */
void undef(char *s) {
    int h;
    struct nlist *prev, *np;

    prev = NULL;
    h = hash(s);
    for (np = hashtab[h]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0)
            break;
        prev = np;          /* remember previous entry */
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

/* printHashtab: for debugging */
void printHashtab(void) {
    int i;
    struct nlist *np;

    for (i = 0; i < HASHSIZE; i++) {
        if ((np = hashtab[i])) {
            for ( ; np; np = np->next) {
                printf("name = %s\n", np->name);
                printf("defn = %s\n", np->defn);
            }
        }
    }
}