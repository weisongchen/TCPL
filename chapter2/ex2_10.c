#include <stdio.h>

/* function prototypes */
int lower(int c);

int main()
{

}


/* lower: converts char c to lower case if c is a character */
int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}