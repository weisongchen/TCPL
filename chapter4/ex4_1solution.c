#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ou";

int main()
{
    char line[MAXLINE];
    int found = 0;
    int index;

    while (getLine(line, MAXLINE) > 0) {
        if ((index = strrindex(line, pattern)) >= 0) {
            printf("index = %d\n", index);
            printf("%s", line);
            found++;
        }
    }

    return found;
}


int getLine(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strrindex: returns right most index of string t in string s, -1 if none */
int strrindex(char s[], char t[]) {
    int i, j, k, pos;

    pos = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}

// /* strrindex: returns right most index of string t in string s, -1 if none */
// int strrindex(char s[], char t[]) {
//     int i, j, k;

//     for (i = strlen(s) - strlen(t); i >= 0; i--) {
//         for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
//             ;
//         if (k > 0 && t[k] == '\0')
//             return i;
//     }
//     return -1;
// }
