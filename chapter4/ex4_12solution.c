#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

/* function prototypes */
void recursiveItoa(char s[], int n);

int main()
{
    char s[MAXLINE];
    int n = +987654321;
    recursiveItoa(s, n);
    printf("n = %d\n", n);
    printf("s = %s\n", s);

    return 0;
}


/* convert n to characters in s; recursive */
void recursiveItoa(char s[], int n) {
    static int i;

    if (n / 10)
        recursiveItoa(s, n / 10);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}