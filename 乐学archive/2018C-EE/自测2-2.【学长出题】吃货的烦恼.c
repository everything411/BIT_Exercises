#include <stdio.h>
int main(void)
{
    int ori_weight, eat_time;
    int curr_weight;
    scanf("%d%d", &ori_weight, &eat_time);
    int food[eat_time];
    for (int i = 0; i < eat_time; i++)
    {
        scanf("%d", &food[i]);
    }
    for (int i = 0; i < eat_time; i++)
    {
        curr_weight = ori_weight;
        for (int j = 0; j <= i; j++)
            curr_weight += (i - j + 1) * food[j];
        printf("%d", curr_weight);
        putchar(i == eat_time - 1 ? '\n' : ' ');
    }

    return 0;
}
