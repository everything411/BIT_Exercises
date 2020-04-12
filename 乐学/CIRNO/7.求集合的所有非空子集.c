#include <stdio.h>
#include <math.h>
#define MASK 0x01

int main(void)
{
    int n;
    scanf("%d", &n);
    int max = (int)pow(2, n);
    int all_num[n + 1];
    for (int i = 0; i <= n; i++)
    {
        all_num[i] = i;
    }
    for (int i = 1; i < max; i++)
    {
        for (int j = 0; j <= n; j++)
            if ((i >> j) & MASK)
                printf("%d ", all_num[j]);
        putchar('\n');
    }
    return 0;
}