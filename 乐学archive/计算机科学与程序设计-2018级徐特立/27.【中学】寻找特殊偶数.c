#include <stdio.h>
int main(int argc, char const *argv[])
{
    int min, max;
    int i, count;
    char num[5];
    while (1)
    {
        scanf("%d%d", &min, &max);
        if (min == 0 || max == 0)
            return 0;
        if (min < 1000 || max > 9999 || min > max)
        {
            puts("Error");
            continue;
        }
        for (i = min, count = 0; i <= max; i++)
        {
            if (i % 2)
                continue;
            sprintf(num, "%d", i);
            if (num[0] != num[1] && num[0] != num[2] && num[0] != num[3] && num[1] != num[2] && num[1] != num[3] && num[2] != num[3])
            {
                printf("%d  ", i);
                count++;
            }
        }
        printf("\ncounter=%d\n", count);
    }
}
