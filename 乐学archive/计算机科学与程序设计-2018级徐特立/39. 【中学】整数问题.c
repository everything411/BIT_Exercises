#include <stdio.h>
/*const int *power_10 = (int[10]){1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
const int *square_n = (int[10]){1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
int main(int argc, char const *argv[])
{
    int len, min, max, count, flag;
    //scanf("%d", &len);
    for (min = max = 1, len = 0, count = 0; len < 10; min = max = 1, len++, count = 0)
    {
        for (int i = 0; i < len; i++)
            max *= 10;
        min = max / 10;
        for (int i = min; i < max; i++)
        {
            flag = 1;
            for (int j = 0; j < len; j++)
                if (i / *(power_10 + len - j - 1) % *(square_n + j))
                    flag = 0;
            if (flag)
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}*/
const int *ans = (int[10]){0, 9, 22, 24, 16, 7, 7, 1, 0, 0};
//The answer is the output of the code commented.
//The time it needs is too long.
//So I just put the answer here.
int main(int argc, char const *argv[])
{
    int len;
    scanf("%d", &len);
    printf("%d\n", ans[len]);
    return 0;
}
