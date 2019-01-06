#include <stdio.h>

#define MAXLINE 200

int main()
{
    /* more comments here */
    /* This is a comment  */
    /* This is also a comment.
     * more comment.
     */
    int a = '\"';
    int b = '\'';
    printf("/* This is not a \"comment */\n");
    printf("// This is not a \'comment, either\n");
    /* But this is a comment */
    /* comment
     * comment,
     * more comment...
     */
    /* printf("Hello World\n"); */
    /* programming /* is interesting */
    return 0;
}
