/* There is a DECODE bug... */
/* waiting for a fix... */
#include <stdio.h>
#include <stdlib.h>
#define ENCODE 1
#define DECODE 2
int cmp(const void *p1, const void *p2)
{
    return *(const int *)p1 > *(const int *)p2 ? 1 : -1;
}

int main(int argc, char const *argv[])
{
    int flag, count;
    scanf("%d%d", &flag, &count);
    //int data[count];
    //int data_processed[count];
    int *data = calloc(count, sizeof(int));
    int *data_processed = calloc(count, sizeof(int));
    for (int i = 0; i < count; i++)
        scanf("%d", data + i);
    switch (flag)
    {
    case ENCODE:
        data_processed[0] = 0;
        for (int i = 1; i < count; i++)
        {
            int code = 0;
            for (int j = 0; j < i; j++)
                code += data[j] < data[i];
            data_processed[i] = code;
        }
        break;
    case DECODE:
        data_processed[count - 1] = data[count - 1];
        int *data_ori = calloc(count, sizeof(int));
        for (int i = 0; i < count; i++)
            data_ori[i] = i;
        data_ori[data[count - 1]] = __INT_MAX__;
        for (int i = count - 2; i >= 0; i--)
        {
            data_processed[i] = data_ori[data[i]];
            data_ori[data[i]] = __INT_MAX__;
            qsort(data_ori, count, sizeof(int), cmp);
        }

        free(data_ori);
        break;
    }
    for (int i = 0; i < count; i++)
        printf(i == count - 1 ? "%d\n" : "%d ", data_processed[i]);
    free(data);
    free(data_processed);
    return 0;
}
