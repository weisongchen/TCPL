#include <stdio.h>
#include <ctype.h>

#define YES 1
#define NO  0

/* function prototypes */
int htoi(char s[]);

int main()
{
    int x = 0xabcdef;

    printf("This program converts hexadecimal digit to decimal digit...\n");
    printf("hexadecimal: x = 0x%x\n", x);
    printf("decimal: x = %d\n", htoi("0xabcdef"));

    return 0;
}


/* convert hexadecimal string s to integer */
int htoi(char s[]) {
    int hexdigit, i, inhex, n;

    i = 0;
    /* skip optional 0x or 0X */
    if (s[i] == '0') {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }

    n = 0;                  /* integer value to be returned      */
    inhex = YES;            /* assume valid hexadecimal digit    */
    for (; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex = NO;      /* not a valid hexadecimal digit  */
        if (inhex == YES)
            n = 16 * n + hexdigit;
    }
    return n;
}