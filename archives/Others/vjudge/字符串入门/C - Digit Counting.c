#include <stdio.h>
int main(int argc, char const *argv[])
{
    int count, number, len;
    int i, j;
    char num_str[8];
    scanf("%d", &count);
    while (count--)
    {
        scanf("%d", &number);
        int times[10] = {0};
        for (i = 1; i <= number; i++)
        {
            len = sprintf(num_str, "%d", i);
            for (j = 0; j < len; j++)
                times[num_str[j] - '0']++;
        }
        for (j = 0; j < 10; j++)
            printf(j == 9 ? "%d\n" : "%d ", times[j]);
    }

    return 0;
}
