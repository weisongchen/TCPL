#include <stdio.h>

/* function prototypes */
void squeeze(char s[], int c);
void squeezeString(char s1[], char s2[]);
int findChar(char s[], int c);

int main()
{
    char s[] = "I love programming, programming is very interesting and useful!";
    int c = 'i';
    char s2[] = "ing";

    printf("s[] = %s\n", s);
    // printf("c = %c\n", c);
    printf("s2[] = %s\n", s2);
    squeezeString(s, s2);
    // printf("After deleting character c in string s[]...\n");
    printf("After deleting character that appears in string s2[] from s[]...\n");
    printf("s[] = %s\n", s);

    return 0;
}


/* squeeze: delete character c in string s */
void squeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}


/* squeezeString: delete any character that appears in string s2 from string s1 */
void squeezeString(char s1[], char s2[]) {
    int i, j, index;

    for (i = j = 0; s1[i] != '\0'; i++) {
        if ((index = findChar(s2, s1[i])) == -1)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}


/* return index(>= 0) if find character c in string s, otherwise -1 */
int findChar(char s[], int c) {
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c)
            return i;
    }
    return -1;
}