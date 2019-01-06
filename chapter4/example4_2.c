#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

/* function prototypes */
double atof(char s[]);
int atoi(char s[]);
int getLine(char s[], int lim);

int main()
{
    double sum;
    char line[MAXLINE];

    sum = 0;
    while (getLine(line, MAXLINE) > 0)
        printf("\t%lf\n", sum += atof(line));


}


int getLine(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}


double atof(char s[]) {
    double val, power;
    int i, sign;

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
    return sign * val / power;
}

int atoi(char s[]) {
    return (int)atof(s);
}