#include <stdio.h>
#include <stdlib.h>
int cmp(const void *i, const void *j)
{
    return *((const int *)i) > *((const int *)j) ? 1 : -1;
}
int main(int argc, char const *argv[])
{
    int stamps[4];
    int sum = 0;
    scanf("%d%d%d%d", stamps, stamps + 1, stamps + 2, stamps + 3);
    qsort(stamps, 4, sizeof(int), cmp);
    while (1)
    {
    out_for:
        sum++;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                for (int k = 0; k < 6; k++)
                    for (int l = 0; l < 6; l++)
                        if (i * stamps[0] + j * stamps[1] + k * stamps[2] + l * stamps[3] == sum && i + j + k + l < 6)
                            goto out_for;
        printf("The max is %d.\n", sum - 1);
        return 0;
    }
}
