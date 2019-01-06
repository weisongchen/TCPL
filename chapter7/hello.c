#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int main(int argc, char *argv[])
{
    char line[MAXLEN];
    char *p;

    while (fgets(line, MAXLEN, stdin)) {
        puts(line);
    }

    return 0;
}