#include <stdio.h>

/* function prototypes */
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{

}


/*
 * solution use for loop intead of while loop, don't forget '\0' character
 * at the end of each string.
 */
void escape(char s[], char t[]) {
    int i, j;

    j = i = 0;
    while (t[i] != '\0') {
        switch(t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[i] = '\0';
}

/*
 * convert escape sequence into real characters while copying the string
 * t to s.
 */
void unescape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] != '\\')
            s[j++] = t[i];
        else {
            switch(t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        }
    }
    s[j] = '\0';
}