#include <stdio.h>
#include <stdlib.h>

struct node {
    char ch;
    struct node *next;
};

int main(int argc, char *argv[])
{
    int c;
    struct node *np;
    struct node *head;

    head = NULL;
    while ((c = getchar()) != EOF && c != '\n') {
        np = (struct node *)malloc(sizeof(struct node));
        if (np != NULL) {
            np->ch = c;
            np->next = head;
            head = np;
        } else {
            fprintf(stderr, "memory is not available!\n");
            exit(1);
        }
    }

    for (np = head; np != NULL; np = np->next)
        putchar(np->ch);
    putchar('\n');

    return 0;
}