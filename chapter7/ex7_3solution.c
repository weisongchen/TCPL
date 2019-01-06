#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT 100

void minprintf(char *fmt, ...);

int main(int argc, char *argv[])
{
    int n = -10;
    char s[] = "hello world";
    double d = 12.3e+5;
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

/* minprintf: minimal printf with variable arguemnt list */
void minprintf(char *fmt, ...) {
    va_list ap;           /* points to each unnamed arg  */
    char *p, *sval;
    char localfmt[LOCALFMT];
    int i, ival;
    unsigned uval;
    double dval;

    va_start(ap, fmt);   /* make ap point to first unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        i = 0;
        localfmt[i++] = '%';
        while (*(p+1) && !isalpha(*(p+1)))
            localfmt[i++] = *++p;             /* collect chars */
        localfmt[i++] = *(p+1);               /* format letter */
        localfmt[i] = '\0';
        switch(*++p) {
        case 'd':
        case 'i':
        case 'c':
            ival = va_arg(ap, int);
            printf(localfmt, ival);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            uval = va_arg(ap, unsigned);
            printf(localfmt, uval);
            break;
        case 'f':
        case 'e':
        case 'E':
            dval = va_arg(ap, double);
            printf(localfmt, dval);
            break;
        case 's':
            sval = va_arg(ap, char *);
            printf(localfmt, sval);
            break;
        default:
            printf(localfmt);
            break;
        }
    }
    va_end(ap);
}