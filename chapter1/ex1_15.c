#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* function prototypes */
float convertFahrToCelsius(float fahr);

int main()
{
    printf("Fahr    Celsius\n");
    for (float fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3.0f   %6.1f\n", fahr, convertFahrToCelsius(fahr));
    }

    return 0;
}


float convertFahrToCelsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}