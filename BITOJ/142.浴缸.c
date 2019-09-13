#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *i, const void *j)
{
    return *(const int *)j - *(const int *)i;
}
int main(int argc, char const *argv[])
{
    int len, wid, vol;
    int size, max;
    int i;
    scanf("%d%d%d", &len, &wid, &vol);
    size = len * wid;
    int pool[size];
    _Bool pool_flag[size];
    for (int i = 0; i < size; i++)
        scanf("%d", pool + i);
    qsort(pool, size, sizeof(int), cmp);
    memset(pool_flag, 0, sizeof(pool_flag));
    max = pool[0];
    
    while (vol)
    {
        for (i = 0; pool[i] == max; i++)
        {
            pool[i]--;
            vol--;
        }
        max = pool[i];
    }
    for (int i = 1; i < size; i++)
    {
        if (!pool_flag[i])
        {
            printf("%d\n", pool[i - 1]);
            return 0;
        }
    }
    printf("%d\n", pool[size - 1]);
    return 0;
}
