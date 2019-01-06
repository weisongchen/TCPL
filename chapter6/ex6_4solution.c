#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>


#define MAXWORD 100
#define NDISTINCT 1400000

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

/* function prototypes */
struct tnode *addtree(struct tnode *p, char *w);
int getword(char *w, int lim);
void sortlist(void);
void treestore(struct tnode *p);
void treeprint(struct tnode *p);
void quicksortlist(int left, int right);

struct tnode *talloc(void);
char *strDup(char *w);
int comment(void);
int getch(void);
void ungetch(int);

struct tnode *list[NDISTINCT];     /* pointers to tree tnode */
int ntn = 0;                       /* number of tree nodes   */

/* print distinct words sorted in decreasing order of frequency */
int main(int argc, char *argv[])
{
    int c;
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while ((c = getword(word, MAXWORD)) != EOF) {
        if (isalpha(c) || c == '_' || c == '#')
            root = addtree(root, word);
    }

    treestore(root);
    quicksortlist(0, ntn-1);

    for (int i = 0; i < ntn; i++)
        printf("%2d:%20s\n", list[i]->count, list[i]->word);

    return 0;
}


struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strDup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }

    return p;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc(void) {
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strDup(char *s) {
    char *p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
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

/* treestore: store in list[] pointers to tree nodes */
void treestore(struct tnode *p) {
    if (p != NULL) {
        treestore(p->left);
        if (ntn < NDISTINCT)
            list[ntn++] = p;
        treestore(p->right);
    }
}

/* sortlist: sort list of pointers to tree nodes */
void sortlist(void) {
    int gap, i, j;
    struct tnode *temp;

    for (gap = ntn/2; gap > 0; gap /= 2) {
        for (i = gap; i < ntn; i++) {
            for (j = i-gap; j >= 0; j -= gap) {
                if ((list[j]->count) >= (list[j+gap]->count))
                    break;
                temp = list[j];
                list[j] = list[j+gap];
                list[j+gap] = temp;
            }
        }
    }
}

/* quicksortlist: quick sort algorithm to sort list of pointers to tree nodes */
void quicksortlist(int left, int right) {
    int i, last;
    void swap(int i, int j);

    if (left >= right)
        return;
    swap(left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (list[i]->count >= list[left]->count)
            swap(++last, i);
    }
    swap(left, last);
    quicksortlist(left, last-1);
    quicksortlist(last+1, right);
}

/* swap: swap list[i] and list[j] */
void swap(int i, int j) {
    struct tnode *temp;

    temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}