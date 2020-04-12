/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>
void sort(int *, int, int);
int input(int *, int);
int output(int *, int);
int main()
{
    // 输入n（n<100)个整数，按照指定的方式（升序或降序）进行排序
    int n, flag, a[100];
    scanf("%d%d", &n, &flag);
    input(a, n);
    sort(a, n, flag); // flag=0：升序，flag=1：降序
    output(a, n);
    return 0;
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */

void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
int Ascending(const void *i, const void *j);
int Descending(const void *i, const void *j);

void sort(int *base, int nmemb, int flag)
{
    qsort(base, nmemb, sizeof(int), flag ? Descending : Ascending);
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
int Ascending(const void *i, const void *j)
{
    return *((const int *)i) - *((const int *)j);
}
int Descending(const void *i, const void *j)
{
    return *((const int *)j) - *((const int *)i);
}