/* BUG,WA */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int cmp(const void *p1, const void *p2)
{
    return *(const int *)p1 < *(const int *)p2 ? 1 : -1;
}
int main(int argc, char const *argv[])
{
    int count;
    while (~scanf("%d", &count))
    {
        int data[count];
        int data_processed[count];
        int data_ori[count];
        for (int i = 0; i < count; i++)
            scanf("%d", &data[i]);
        data_processed[0] = data[0];
        for (int i = 0; i < count; i++)
            data_ori[i] = i;
        data_ori[data[0]] = INT_MIN;
        for (int i = 1; i < count; i++)
        {
            data_processed[i] = data_ori[data[i]];
            data_ori[data[i]] = INT_MIN;
            qsort(data_ori, count, sizeof(int), cmp);
        }
        for (int i = 0; i < count; i++)
            printf(i == count - 1 ? "%d\n" : "%d ", data_processed[i]);
    }
    return 0;
}
