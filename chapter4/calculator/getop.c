#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "calc.h"

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;

    /* add math functions */
    if (islower(c)) {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);          /* went one char too far */
        if (strlen(s) > 1)
            return NAME;         /* > 1 char; it is NAME */
        else
            return c;
    }

    if (!isdigit(c) && c != '.' && c != '-')
        return c;                     /* not a number */
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;               /* negative number */
        else {
            if (c != EOF)
                ungetch(c);
            return '-';               /* minus sign */
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* mathfnc: check string s for supported math function */
void mathfnc(char s[]) {
    double op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp"))
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else {
        printf("error: %s not supported\n", s);
    }
}