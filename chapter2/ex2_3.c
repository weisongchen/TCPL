#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main()
{
    int x = 0xabcdef;

    printf("This program converts hexadecimal digit to decimal digit...\n");
    printf("hexadecimal: x = 0x%x\n", x);
    printf("decimal: x = %d\n", htoi("0xabcdef"));

    return 0;
}


/* convert hexadecimal to integer in decimal */
int htoi(char s[]) {
    int i = 0;
    int n = 0;
    int c;

    if (s[i] == '0') {
        i++;
        if (s[i] == 'x' || s[i] == 'X')
            i++;
    }

    c = tolower(s[i]);
    while (isdigit(c) || (c >= 'a' && c <= 'f')) {
        if (isdigit(c))
            n = 16 * n + (c - '0');
        else
            n = 16 * n + (c - 'a' + 10);
        c = tolower(s[++i]);
    }

    return n;
}