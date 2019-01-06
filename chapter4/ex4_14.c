#include <stdio.h>

/*
 * 这个宏只有在两个参数名都不是temp的情况下才能工作。
 * 如果其中一个参数名为temp，那么宏展开将是{int temp; temp = temp, temp = y, y = temp;}
 * 那么将无法进行交换数据了，所以这个temp名字不能和要进行交换的变量同名。
 */
#define swap(t, x, y) {t temp; temp = x, x = y, y = temp;}

int main()
{
    // int temp = 1; x and y can't be named temp
    int x = 1;
    int y = 2;
    printf("before swaping...\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    swap(int, x, y);
    printf("after swaping...\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}