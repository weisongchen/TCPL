#include <stdio.h>

int getLine(char s[], int maxlen) {
    int c, i;

    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

void strCat(char *s, char *t) {
    while (*s)
        s++;
    while ((*s++ = *t++))
        ;
}

void strNcat(char *s, char *t, int n) {
    while (*s)
        s++;
    while (n-- > 0 && (*s++ = *t++))
        ;
}

void strCpy(char *s, char *t) {
    while ((*s++ = *t++))
        ;
}

void strNcpy(char *s, char *t, int n) {
    while (n-- > 0 && (*s++ = *t++))
        ;
    if (n <= 0)
        *s = '\0';
}

int strCmp(char *s, char *t) {
    for (; *s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}

int strNcmp(char *s, char *t, int n) {
    for (; n-- > 0 && *s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    if (n <= 0)
        return 0;
    return *s - *t;
}

int strEnd(char *s, char *t) {
    int sl, tl;

    if ((sl = strLen(s)) >= (tl = strLen(t))) {
        s += sl - tl;
        for (; *s == *t; s++, t++) {
            if (*t == '\0')
                return 1;
        }
        if (*s != *t)
            return 0;
    }
    return 0;
}

int strLen(char *s) {
    char *p = s;
    while (*p)
        p++;
    return p - s;
}

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}