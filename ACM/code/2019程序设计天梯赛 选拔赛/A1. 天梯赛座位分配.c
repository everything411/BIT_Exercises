#include <stdio.h>
int school_count;
int team_val[100];
int not_calc_num(int curr)
{
    int ret = 0;
    for (int i = 0; i < school_count; i++)
        if (team_val[i] >= curr)
            ret++;
    if (ret == 1)
        ret = 2;
    return ret;
}
int main(int argc, char const *argv[])
{

    scanf("%d", &school_count);
    for (int i = 0; i < school_count; i++)
    {
        scanf("%d", &team_val[i]);
        //team_count[team_val[i]]++;
    }

    for (int i = 0; i < school_count; i++)
    {
        printf("#%d\n", i + 1);
        int pos = i + 1;
        for (int j = 0; j < team_val[i]; j++)
        {
            int step = not_calc_num(j + 1);
            for (int k = 0; k < 10; k++)
            {
                printf("%d%c", pos, k == 9 ? '\n' : ' ');
                pos += step;
            }
        }
    }

    return 0;
}