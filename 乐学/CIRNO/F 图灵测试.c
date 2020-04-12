#include <stdio.h>
int main(void)
{
    int case_count;
    int a_cnt, b_cnt;
    char ch;
    scanf("%d", &case_count);
    getchar();
    for (int i = 0; i < case_count; i++)
    {
        a_cnt = b_cnt = 0;
        while ((ch = getchar()) != '\n')
        {
            if (ch == 'a')
            {
                a_cnt++;
            }
            else
            {
                b_cnt++;
            }
        }
        if (a_cnt == b_cnt)
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }
    return 0;
}