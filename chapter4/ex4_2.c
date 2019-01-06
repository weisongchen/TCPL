#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

/* function prototypes */
double atofExpand(char s[]);
int getLine(char s[], int lim);

int main()
{
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0)
        printf("\t%lf\n", atofExpand(line));

    return 0;
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