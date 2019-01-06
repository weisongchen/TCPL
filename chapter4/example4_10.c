#include <stdio.h>

/* function prototypes */
void printd(int n);
void quickSort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main()
{
    int n = -1234;

    printd(n);

    return 0;
}


void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}


void quickSort(int v[], int left, int right) {
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left])
            swap(v, ++last, i);
    }
    swap(v, left, last);
    quickSort(v, left, last - 1);
    quickSort(v, last + 1, right);
}

void swap(int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}