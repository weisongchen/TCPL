#include <stdio.h>

int main(int argc, char *argv[])
{
    int n = -10;
    unsigned u = n;
    char s[] = "programming is very interesting!";
    char *p = s;

    printf("decimal, n = %d\n", n);
    printf("unsigned, n = %u\n", n);
    printf("octonary, n = %o\n", n);
    printf("hexidecimal, n = %x\n", n);
    printf("hexidecimal, n = %X\n", n);
    printf("s = \"%s\"\n", s);
    printf("pointer s = %p\n", s);
    printf("p = \"%s\"\n", p);
    printf("pointer p = %p\n", p);

    return 0;
}