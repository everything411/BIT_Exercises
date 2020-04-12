/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>

void swap(int *, int *);
int input(int *, int);
int output(int *, int);
int main()
{
    // 分别将输入2*n（n<100)个整数保存在两个数组中，比较对应
    // 数组元素，将较小值保存在a数组中，较大值存入数组b中
    int n, k, a[100], b[100];
    scanf("%d", &n);
    input(a, n);
    input(b, n);
    for (k = 0; k < n; k++)
    {
        if (a[k] > b[k])
            swap(&a[k], &b[k]);
    }
    output(a, n);
    output(b, n);
    return 0;
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */

void swap(int *x, int *y)
{
    if (x != y)
    {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}
int input(int *base, int count)
{
    for (int i = 0; i < count; i++)
        scanf("%d", base + i);
    return 0;
}
int output(int *base, int count)
{
    for (int i = 0; i < count; i++)
        printf("%d,", base[i]);
    putchar('\n');
    return 0;
}