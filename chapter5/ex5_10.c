#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double atofExpand(char s[]);
void push(double f);
double pop(void);
double getTop(void);

int main(int argc, char *argv[])
{
    int c;
    double op2;

    while (--argc > 0) {
        if (isdigit((c = (*++argv)[0]))) {
            push(atofExpand(*argv));
        } else if (c == '+') {
            push(pop() + pop());
        } else if (c == '-') {
            op2 = pop();
            if (op2 != 0.0)
                push(pop() - op2);
            else
                printf("error: zero divisor!\n");
        } else if (c == '*') {
            push(pop() * pop());
        } else if (c == '/') {
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor!\n");
        } else if (c == '%') {
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor!\n");
        } else {
            printf("error: unknown command %s\n", *argv);
        }
    }

    printf("\t%.8g\n", getTop());

    return 0;
}

/* atofExpand: convert string s to float point number */
double atofExpand(char s[]) {
    double val, power;
    int i, sign, exponential;

    /* skip blanks */
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E')
        i++;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (exponential = 0; isdigit(s[i]); i++)
        exponential = 10 * exponential + (s[i] - '0');
    if (sign > 0)
        for (i = 0; i < exponential; i++)
            val *= 10.0;
    else
        for (i = 0; i < exponential; i++)
            val /= 10.0;
    return val;
}