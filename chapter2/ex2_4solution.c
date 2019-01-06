#include <stdio.h>

/* function prototypes */
void squeeze(char s1[], char s2[]);


int main()
{
    char s[] = "I love programming, programming is very interesting and useful!";
    int c = 'i';
    char s2[] = "ing";

    printf("s[] = %s\n", s);
    // printf("c = %c\n", c);
    printf("s2[] = %s\n", s2);
    squeeze(s, s2);
    // printf("After deleting character c in string s[]...\n");
    printf("After deleting character that appears in string s2[] from s[]...\n");
    printf("s[] = %s\n", s);

    return 0;
}


/* squeeze: delete each char in s1 which is in s2  */
void squeeze(char s1[], char s2[]) {
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}
