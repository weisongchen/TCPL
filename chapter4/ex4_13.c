/*
 * some problem can be solved easily by using recursion, but some of them are not.
 * this problem is not suitable using recursion.so, you should always try your best
 * to find the solution for a perticular problem.
 */
#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void recursiveReverse(char s[], int left, int right);

int main()
{
    char s[] = "I love programming!";

    printf("s = %s\n", s);
    reverse(s);
    printf("reversed s = %s\n", s);

    return 0;
}

void reverse(char s[]) {
    recursiveReverse(s, 0, strlen(s) - 1);
}
void recursiveReverse(char s[], int left, int right) {
    if (left >= right)
        return;
    int c;
    c = s[left];
    s[left] = s[right];
    s[right] = c;
    recursiveReverse(s, left + 1, right - 1);
}