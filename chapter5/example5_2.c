#include <stdio.h>
#include <ctype.h>

/* function prototypes */
int getch(void);
void ungetch(int c);
int getInt(int *pn);

int main()
{
    int n, state;

    printf("Enter an integer: ");
    state = getInt(&n);
    if (state > 0 && state != EOF)
        printf("n = %d\n", n);
    else
        printf("Invalid input!\n");

    return 0;

}


int getInt(int *pn) {
    int c, d, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);        /* input is not a digit */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        d = getch();
        if (!isdigit(d)) {
            if (d != EOF)
                ungetch(d);
            ungetch(c);
            return 0;
        } else {
            c = d;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}