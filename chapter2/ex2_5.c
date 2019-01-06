#include <stdio.h>

/* function prototypes */
int any(char s1[], char s2[]);


int main()
{
    int index;
    char s[] = "I love programming, programming is very interesting and useful!";
    int c = 'i';
    char s2[] = "w";

    printf("s[] = %s\n", s);
    // printf("c = %c\n", c);
    printf("s2[] = %s\n", s2);
    // printf("After deleting character c in string s[]...\n");
    if ((index = any(s, s2)) >= 0)
        printf("char in s2 appear firstly in s is %d\n", index);
    else
        printf("Not found!\n");

    return 0;
}


int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                return i;
        }
    }
    return -1;
}

