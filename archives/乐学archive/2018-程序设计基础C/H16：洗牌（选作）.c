#include <stdio.h>
#include <stdlib.h>
void rearrange(int total, int *poker, int *tmp_poker);
int check(int total, int *poker);
int main(int argc, char const *argv[])
{
    int half;
    scanf("%d", &half);
    int total = 2 * half;
    int poker[20000] = {0};
    int tmp_poker[20000] = {0};
    for (int i = 0; i < total; i++)
        poker[i] = i;
    for (int i = 1; 1; i++)
    {
        rearrange(total, poker, tmp_poker);
        if (check(total, poker))
        {
            printf("%d\n", i);
            return 0;
        }
    }
}
void rearrange(int total, int *poker, int *tmp_poker)
{
    int half = total / 2;
    for (int i = 0; i < half; i++)
        tmp_poker[2 * i + 1] = poker[i];
    for (int i = half; i < total; i++)
        tmp_poker[2 * (i - half)] = poker[i];
    for (int i = 0; i < total; i++)
        poker[i] = tmp_poker[i];
}
int check(int total, int *poker)
{

    for (int i = 0; i < total; i++)
    {
        if (*poker++ != i)
            return 0;
    }
    return 1;
}