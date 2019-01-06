#include <stdio.h>

int brace, brack, paren;

/* function prototypes */
void inQuote(int c);
void inComment(void);
void search(int c);

/* rudimentary syntax checker for C programs */
int main()
{
    int c;
    extern int brace, brack, paren;

    while ((c = getchar()) != EOF) {
        if (c == '/') {
            if ((c = getchar()) == '*')
                inComment();
            else
                search(c);
        } else if (c == '\'' || c == '\"') {
            inQuote(c);
        } else {
            search(c);
        }

        if (brace < 0) {
            printf("Unbalanced braces\n");
            brace = 0;
        } else if (brack < 0) {
            printf("Unbalanced brackets\n");
            brack = 0;
        } else if (paren < 0) {
            printf("Unbalanced parentheses\n");
            paren = 0;
        }
    }

    if (brace > 0)
        printf("Unbalanced braces\n");
    if (brack > 0)
        printf("Unbalanced brackets\n");
    if (paren > 0)
        printf("Unbalanced parentheses\n");

    if (brace == 0 && brack == 0 && paren == 0)
        printf("program is good, no syntax error!\n");

    return 0;
}


/* search: search for rudimentary syntax errors */
void search(int c) {
    extern int brace, brack, paren;

    if (c == '{')
        ++brace;
    else if (c == '}')
        --brace;
    else if (c == '[')
        ++brack;
    else if (c == ']')
        --brack;
    else if (c == '(')
        ++paren;
    else if (c == ')')
        --paren;
}

/* This function can't deal with imcomplete comment like no end comment token */
/* inComment: inside of a valid comment */
void inComment(void) {
    int c, d;

    c = getchar();                    /* prev character */
    d = getchar();                    /* curr character */
    while (c != '*' || d != '/') {    /* search for end */
        c = d;
        d = getchar();
    }
}

/* inQuote: inside quote */
void inQuote(int c) {
    int d;

    while ((d = getchar()) != c)
        if (d == '\\')
            getchar();
}