#include <stdio.h>
#include <string.h>
int c[30][30];
void Combination() //求组合数
{
    for (int i = 0; i <= 26; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int main()
{
    char str[32];
    Combination();
    scanf("%*d");
    while (~scanf("%s", str))
    {
        int len = strlen(str);
        int i;
        for (i = 1; i < len; i++)
        {
            if (str[i] <= str[i - 1])
                break;
        }
        if (i < len)
        {
            printf("0\n");
            continue;
        }
        int sum = 0;
        for (i = 1; i < len; i++)
            sum += c[26][i];      //长度比该串短的先加上
        for (i = 0; i < len; i++) //从高位进行处理对于每一位处理到该位的前一个，比如该位为‘d'，就处理到c
        {
            char ch = (!i ? 'a' : (str[i - 1] + 1));
            for (int j = ch; j < str[i]; j++)
                sum += c['z' - j][len - 1 - i];
        }
        printf("%d\n", sum + 1);
    }
    return 0;
}