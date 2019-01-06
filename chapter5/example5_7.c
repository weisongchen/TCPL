#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* function prototypes */
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

char *month_name(int n);

int main()
{
    printf("hello world\n");

    return 0;
}


int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400;
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > daytab[leap][month]) {
        printf("Illegal input!\n");
        return -1;
    } else {
        for (i = 1; i < month; i++)
            day += daytab[leap][i];
        return day;
    }
}

/*
 * pointer version: use pointer instead of array index
 * assume all input are valid.(don't deal with error input)
 */
// int day_of_year(int year, int month, int day) {
//     int leap;
//     char *p;

//     leap = year % 4 == 0 && year % 100 != 0 || year % 400;
//     p = daytab[leap];
//     while (--month)
//         day += *++p;
//     return day;
// }

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year 400 == 0;
    if (year >= 0 && yearday > 0 && yearday <= ((leap) ? 366 : 365)) {
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    } else {
        printf("Illegal input!\n");
        *pmonth = -1;
        *pday = -1;
    }
}

/* pointer version and don't deal with error input */
// void month_day(int year, int yearday, int *pmonth, int *pday) {
//     int leap;
//     char *p;

//     leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
//     p = daytab[leap];
//     while (yearday > *++p)
//         yearday -= *p;
//     *pmonth = p - *(daytab + leap);
//     *pday = yearday;
// }


char *month_name(int n) {
    static char *name[] = {
        "Illegal month", "January", "February", "March",
        "April", "May", "June", "July", "August",
        "Septemper", "October", "November", "December"
    };

    return (n < 1 || n > 12) name[0] : name[n];
}