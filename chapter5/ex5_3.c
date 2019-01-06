#include <stdio.h>

#define BUFSIZE 100

/* function prototypes */
void strCat(char *s, char *t);
void strCpy(char *s, char *t);
int strLen(char *s);
int strEnd(char *s, char *t);
int strCmp(char *s, char *t);

void strNcpy(char *s, char *t, int n);
void strNcat(char *s, char *t, int n);


int main()
{
    char *s = "I love programming";
    char *t = "programming";

    if (strEnd(s, t) == 1)
        printf("string \"%s\" appear at the end of string \"%s\"\n", t, s);
    else
        printf("Not appear!\n");

    return 0;
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