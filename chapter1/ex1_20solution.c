#include <stdio.h>

#define TABINC 8                         /* tab increment size */

/* replace tabs with proper number of blanks */
int main()
{
    int c, nb, pos;

    nb = 0;                              /* number of blanks neccessary   */
    pos = 1;                             /* position of character in line */
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            nb = TABINC - (pos - 1) % TABINC;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {          /* newline character    */
            putchar(c);
            pos = 1;
        } else {                         /* all other characters */
            putchar(c);
            ++pos;
        }
    }

    return 0;
}