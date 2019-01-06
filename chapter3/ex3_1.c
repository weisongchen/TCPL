#include <stdio.h>

#define N 100

/* function ptototypes */
int binsearch(int x, int v[], int n);

int main()
{
    int v[N];

    for (int i = 0; i < N; i++)
        v[i] = i + 1;

    int x = 130;
    int index;
    if ((index = binsearch(x, v, N)) != -1)
        printf("Found %d in v[] at index %d\n", x, index);
    else
        printf("Not Found!\n");
}


/* find x in v[], which v[0] <= v[1] <= v[2]... <= v[n-1]. return -1 if not found */
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}