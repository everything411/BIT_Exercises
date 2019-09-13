#include <stdio.h>
#include <stdlib.h>
#define ABS_SUB(X, Y) (X > Y ? X - Y : Y - X)
int compare(const void *i, const void *j)
{
    return *((const long long *)i) > *((const long long *)j) ? 1 : -1;
}
int main(int argc, char const *argv[])
{
    long long total;
    long long ans = 0;
    scanf("%lld", &total);
    long long *x = (long long *)malloc(total * sizeof(long long));
    long long *y = (long long *)malloc(total * sizeof(long long));
    for (long long i = 0; i < total; i++)
        scanf("%lld%lld", x + i, y + i);
    qsort(x, total, sizeof(long long), compare);
    qsort(y, total, sizeof(long long), compare);
    for (long long i = 0; i < total; i++)
        x[i] -= i;
    qsort(x, total, sizeof(long long), compare);
    long long mid = total / 2;
    for (long long i = 0; i < total; i++)
        ans += (ABS_SUB(y[i], y[mid]) + ABS_SUB(x[i], x[mid]));
    printf("%lld\n", ans);
    free(x);
    free(y);
    return 0;
}
