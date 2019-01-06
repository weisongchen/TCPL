#include <stdarg.h>
#include <stdio.h>


void minprintf(char *fmt, ...);

int main(int argc, char *argv[])
{
    int n = -10;
    char s[] = "hello world";
    double d = 12.3;
    char ch = 's';

    minprintf("string s = %s\n", s);
    minprintf("pointer s = %p\n", s);
    minprintf("n = %i\n", n);
    minprintf("unsigned n = %u\n", (unsigned)n);
    minprintf("octonary, n = 0%o\n", n);
    minprintf("hexidecimal, n = OX%X\n", n);
    minprintf("hexidecimal, n = ox%x\n", n);
    minprintf("d = %f\n", d);
    minprintf("e, d = %e\n", d);
    minprintf("E, d = %E\n", d);
    minprintf("g, d = %g\n", d);
    minprintf("G, d = %G\n", d);
    minprintf("ch = %c\n", ch);
    minprintf("%%\n");

    return 0;
}


void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    unsigned uval;
    int oval;
    int hval;
    double dval;
    char ch;
    void *ptr;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
        case 'd':
        case 'i':
        case 'c':
            ival = va_arg(ap, int);
            if (*p == 'c')
                printf("%c", ival);
            else
                printf("%d", ival);
            break;
        case 'u':
        case 'o':
        case 'x':
        case 'X':
            uval = va_arg(ap, unsigned);
            if (*p == 'u')
                printf("%u", uval);
            else if (*p == 'o')
                printf("%o", uval);
            else if (*p == 'x')
                printf("%x", uval);
            else
                printf("%X", uval);
            break;
        case 'f':
        case 'e':
        case 'E':
            dval = va_arg(ap, double);
            if (*p == 'f')
                printf("%f", dval);
            else if (*p == 'e')
                printf("%e", dval);
            else
                printf("%E", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        case 'p':
            ptr = va_arg(ap, void *);
            printf("%p", ptr);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
}