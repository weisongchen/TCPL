#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* function prototypes */
void strcpy(char *s, char *t);
int strcmp(char *s, char *t);

int main()
{
    printf("hello world\n");

    return 0;
}


char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return NULL;
    }
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


/* strcpy: copy string t to string s, assume s has enough space */
void strcpy(char *s, char *t) {
    while (*s++ = *t++)
        ;
}

int strcmp(char *s, char *t) {
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
