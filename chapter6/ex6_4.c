#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

#define MAXWORD 100
#define MAXLEN 1400000         /* max length of the tree tnodes */

struct tnode *desclist[MAXLEN];

/* function prototypes */
struct tnode *addtree(struct tnode *p, char *w);
void treeprint(struct tnode *p);
int getword(char *w, int len);
void printDescByFrequency(struct tnode *p[]);
void sortDesc(struct tnode *desclist[], struct tnode *p);
void goThroughTree(struct tnode *desclist[], struct tnode *p);

struct tnode *talloc(void);
char *strDup(char *w);
int comment(void);
int getch(void);
void ungetch(int);

/*
 * This solution is not efficient enough, it does too many unnecessary operations.
 * actually, you can just store the pointers to tree node when going through the
 * tree. then use an efficient sorting algorithm to sort the pointers in the array.
 */
int main(int argc, char *argv[])
{
    int c;
    struct tnode *root;
    char word[MAXWORD];

    printf("This program read words from input and count the \n");
    printf("frequency of each word and print out by descending order\n");
    printf("The functionality is limited, can't handle too many different words.\n");
    printf("The output is: \n\n");

    desclist[0] = NULL;
    root = NULL;
    while ((c = getword(word, MAXWORD)) != EOF) {
        if (isalpha(c) || c == '_' || c == '#')
            root = addtree(root, word);
    }

    goThroughTree(desclist, root);
    printDescByFrequency(desclist);

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


void goThroughTree(struct tnode *desclist[], struct tnode *p) {
    if (p != NULL) {
        goThroughTree(desclist, p->left);
        sortDesc(desclist, p);
        goThroughTree(desclist, p->right);
    }
}

/* buffer overflow problem... */
void sortDesc(struct tnode *desclist[], struct tnode *p) {
    struct tnode *ptr;
    int i;

    i = 0;
    while ((ptr = desclist[i])) {
        if (ptr->count < p->count)
            break;
        i++;
    }
    int j = i;
    while (desclist[j])
        j++;
    if (j > MAXLEN - 1) {
        printf("error: too manay words!\n");
    } else {
        desclist[j+1] = NULL;
        while (j > i) {
            desclist[j] = desclist[j-1];
            j--;
        }
        desclist[j] = p;
    }
}

/* print every word by its frequency in the tree in descending order */
void printDescByFrequency(struct tnode *desclist[]) {
    struct tnode *p;
    int i = 0;

    while ((p = desclist[i++]))
        printf("%4d %s\n", p->count, p->word);
}