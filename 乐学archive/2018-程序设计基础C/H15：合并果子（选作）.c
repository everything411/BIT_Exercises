#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *p1, const void *p2)
{
    return *(const long *)p1 < *(const long *)p2 ? 1 : -1;
}
int main(int argc, char const *argv[])
{
    int total;
    long long answer = 0;
    scanf("%d", &total);
    long long weight[total];
    memset(weight, 0, total * sizeof(long long));
    for (int i = 0; i < total; i++)
        scanf("%lld", &weight[i]);

    for (int i = total; i > 1; i--)
    {
        qsort(weight, i, sizeof(long long), cmp);
        answer += weight[i - 2] += weight[i - 1];
    }
    printf("%lld\n", answer);
    return 0;
}