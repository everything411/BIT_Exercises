#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int count, len, period;
    int flag;
    int i, j;
    char str[100];
    scanf("%d", &count);
    for (i = 0; i < count; i++)
    {
        scanf("%s", str);
        len = strlen(str);
        for (period = 1; period <= len; period++)
        {
            flag = 1;
            if (len % period)
            {
                continue;
            }
            for (j = period; j < len; j += period)
            {
                if (strncmp(&str[j - period], &str[j], period))
                    flag = 0;
            }
            if (flag || period == len)
            {
                printf(i == count - 1 ? "%d\n" : "%d\n\n", period);
                break;
            }
        }
    }
    return 0;
}
