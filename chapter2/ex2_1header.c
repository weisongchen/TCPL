#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Signed type:\n");
    printf("SCHAR_MIN = %d\n", SCHAR_MIN);
    printf("SCHAR_MAX = %d\n", SCHAR_MAX);
    printf("SHRT_MIN  = %d\n", SHRT_MIN);
    printf("SHRT_MAX  = %d\n", SHRT_MAX);
    printf("INT_MIN   = %d\n", INT_MIN);
    printf("INT_MAX   = %d\n", INT_MAX);
    printf("LONG_MIN  = %ld\n", LONG_MIN);
    printf("LONG_MAX  = %ld\n", LONG_MAX);

    printf("\nUnsigned type:\n");
    printf("UCHAR_MAX = %u\n", UCHAR_MAX);
    printf("USHRT_MAX = %u\n", USHRT_MAX);
    printf("UINT_MAX  = %u\n", UINT_MAX);
    printf("ULONG_MAX = %lu\n", ULONG_MAX);

    return 0;
}