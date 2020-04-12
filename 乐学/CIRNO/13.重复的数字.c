#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long ull_t;
int cmp(const void *i, const void *j)
{
    return *(const ull_t *)i > *(const ull_t *)j ? 1 : -1;
}
int main(int argc, char const *argv[])
{
    int case_count;
    int number_count;
    ull_t data[10000];
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        scanf("%d", &number_count);
        for (int j = 0; j < number_count; j++)
            scanf("%llu", data + j);
        qsort(data, number_count, sizeof(ull_t), cmp);
        int k = 1;
        for (; k < number_count; k++)
            if (data[k - 1] == data[k])
            {
                printf("%llu\n", data[k]);
                break;
            }
    }
    return 0;
}
