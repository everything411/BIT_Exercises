#include <stdio.h>
#include <string.h>
char fattyhappy[] = "fattyhappy";
char str[1010];
int diff[8];
int first[128];
int last[128];
int fattyhappy_diff(char *str, int pos)
{
    int diff_cnt = 0;
    for (int i = 0; i < 10 && diff_cnt < 3; i++)
    {
        if (fattyhappy[i] != str[i])
        {
            diff[diff_cnt++] = i + pos;
        }
    }
    return diff_cnt;
}
void init_first_last(char *str)
{
    memset(first, -1, sizeof(first));
    memset(last, -1, sizeof(last));
    for (int i = 0; str[i]; i++)
    {
        if (first[str[i]] == -1)
            first[str[i]] = i;
        last[str[i]] = i;
    }
}
int main(void)
{
    int t;
    int len;
    int diff_val;
    int tmp;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%s", str);
        len = strlen(str);
        init_first_last(str);
        for (int i = 0; i < len - 9; i++)
        {
            diff_val = fattyhappy_diff(str + i, i);
            switch (diff_val)
            {
            case 0:
                printf("%d %d\n", i + 3, i + 4);
                goto case_ok;
                break;
            case 1:
                if (first[fattyhappy[diff[0] - i]] != -1 &&
                    (first[fattyhappy[diff[0] - i]] < i || first[fattyhappy[diff[0] - i]] > i + 9))
                {
                    printf("%d %d\n", first[fattyhappy[diff[0] - i]] + 1, diff[0] + 1);
                    goto case_ok;
                }
                else if (last[fattyhappy[diff[0] - i]] != -1 &&
                         (last[fattyhappy[diff[0] - i]] < i || last[fattyhappy[diff[0] - i]] > i + 9))
                {
                    printf("%d %d\n", last[fattyhappy[diff[0] - i]] + 1, diff[0] + 1);
                    goto case_ok;
                }
                break;
            case 2:
                if (str[diff[0]] == fattyhappy[diff[1] - i] && str[diff[1]] == fattyhappy[diff[0] - i])
                {
                    printf("%d %d\n", diff[0] + 1, diff[1] + 1);
                    goto case_ok;
                }
                break;
            default:
                break;
            }
        }
        // fail
        puts("-1");
    case_ok:;
    }
    return 0;
}