/*
 * File: ex5_6.c
 * ----------------
 * This file rewrite some function from previous chapters, using pointer arithmetic
 * instead of array index. The intension is clear: to practice pointer.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100

/* function prototyeps */
int getLine(char *s, int maxlen);
int strIndex(char *s, char *t);
void reverseStr(char *s);
int strLen(char *s);
int aToi(char *s);
void iToa(char *s, int n);

int main()
{
    char s[] = "I love programming";
    int n = +12345;
    char p[MAXLEN];

    printf("Before reversing...\n");
    printf("s = %s\n", s);
    printf("s length is %d\n", strLen(s));
    reverseStr(s);
    printf("After reversing...\n");
    printf("s = %s\n", s);

    printf("n = %d\n", n);
    iToa(p, n);
    printf("iToa(p, n), p = %s\n", p);

    return 0;
}


int getLine(char *s, int maxlen) {
    int c;
    char *p = s;

    while (--maxlen > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - p;
}

// int strindex(char s[], char t[]) {
//     int i, j, k;

//     for (i = 0; s[i] != '\0'; i++) {
//         for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
//             ;
//         if (k > 0 && t[k] == '\0')
//             return i;
//     }
//     return -1;
// }

/*
 * the pointer version is a little more difficult to understand
 * but the algorithm to solve the problem is the same.
 */
int strIndex(char *s, char *t) {
    char *i, *j, *k;

    for (i = s; *i; i++) {
        for (j = i, k = t; *k && *k == *j; j++, k++)
            ;
        if (k > t && *k == '\0')
            return i - s;
    }
    return -1;
}


void reverseStr(char *s) {
    int c;
    char *p = s + strLen(s) - 1;
    for (; s < p; s++, p--) {
        c = *s;
        *s = *p;
        *p = c;
    }
}

int strLen(char *s) {
    char *p = s;
    while (*p)
        p++;
    return p - s;
}

int aToi(char *s) {
    int n, sign;

    for (; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

void iToa(char *s, int n) {
    int sign;
    char *p = s;

    if ((sign = n) < 0)
        n = -n;

    do {
        *p++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *p++ = '-';
    *p = '\0';
    reverseStr(s);
}

