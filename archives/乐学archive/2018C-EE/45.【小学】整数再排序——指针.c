/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>
void sort(int *, int, int (*)(int, int));
int input(int *, int);
int output(int *, int);
int up(int, int);   // a<b:1； a=b:0；a>b:-1反序
int down(int, int); // a<b:-1；a=b:0；a>b:1 正序

int main()
{
    int n, flag, a[100];
    scanf("%d%d", &n, &flag); // n：数组元素数量； flag=0：升序，flag=1：降序
    input(a, n);
    if (flag == 0)
        sort(a, n, up); // 0：升序，1：降序
    else
        sort(a, n, down);
    output(a, n);
    return 0;
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */

#include <stdlib.h>
int qsort_up(const void *i, const void *j)
{
    return *(const int *)i > *(const int *)j ? 1 : -1;
}
int qsort_down(const void *i, const void *j)
{
    return *(const int *)i < *(const int *)j ? 1 : -1;
}

void sort(int *base, int count, int (*pf)(int, int))
{
    if (pf == up)
    {
        fprintf(stderr, "qsort_up!\n");
        qsort(base, count, sizeof(int), qsort_up);
    }
    else
    {
        fprintf(stderr, "qsort_down!\n");
        qsort(base, count, sizeof(int), qsort_down);
    }

    /*
    int temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (pf(i, j))
            {
                temp = base[i];
                base[i] = base[j];
                base[j] = temp;
            }
        }
    }
    */
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
int up(int a, int b)
{
    if (a < b)
    {
        return 1;
    }
    else if (a == b)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int down(int a, int b)
{
    if (a < b)
    {
        return -1;
    }
    else if (a == b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}