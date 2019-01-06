#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
int strindex(char source[], char searchfor[]);

char pattern[] = "ou";

int main()
{
    char line[MAXLINE];
    int found = 0;
    int index;

    while (getLine(line, MAXLINE) > 0) {
        if ((index = strindex(line, pattern)) >= 0) {
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

/* return index of string t in string s, -1 if not found */
int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
