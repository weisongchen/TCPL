#include <stdio.h>
#include <ctype.h>

/* function prototypes */
int getch(void);
void ungetch(int c);
int getDouble(double *pn);

int main()
{
    int state;
    double d;

    printf("Enter an double: ");
    state = getDouble(&d);
    if (state > 0 && state != EOF)
        printf("d = %lf\n", d);
    else
        printf("Invalid input!\n");

    return 0;

}


int getDouble(double *d) {
    int c, n, sign, expo;
    double power;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);           /* Invalid number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        n = c;               /* remember sign char */
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);
            ungetch(n);
            return 0;
        }
    }
    for (*d = 0.0; isdigit(c); c = getch())
        *d = *d * 10.0 + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *d = *d * 10.0 + (c - '0');
        power *= 10.0;
    }
    *d = *d * sign / power;

    if (c == 'e' || c == 'E') {
        c = getch();
        sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-')
            c = getch();
        for (expo = 0; isdigit(c); c = getch())
            expo = 10 * expo + (c - '0');
        if (sign == 1) {
            while (expo-- > 0)
                *d *= 10.0;
        } else {
            while (expo-- > 0)
                *d /= 10.0;
        }
    }

    if (c != EOF)
        ungetch(c);
    return c;
}