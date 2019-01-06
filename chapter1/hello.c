#include <stdio.h>

int main()
{
	printf("Hello World!\n");
	printf("Hello World!\c");
	printf("Hello World!\7");
	printf("Hello World!\?");
	printf("Hello World!\y");

    printf("\n");
    printf("\t");
    printf("\v");
    printf("\b");
    printf("\r");
    printf("\f");
    printf("\a");
    printf("\\");
    printf("\?");
    printf("\'");
    printf("\"");
    printf("\0");
    printf("\023");
    printf("\xff");

	return 0;
}
