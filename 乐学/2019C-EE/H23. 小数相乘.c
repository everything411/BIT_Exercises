#include <stdio.h>
#include <string.h>
#include <ctype.h>
char strnum1[100];
char strnum2[100];
int num1[100];
int num2[100];
int ans[300];
char ansstr[300];
int main(int argc, char const *argv[])
{
    scanf("%s%s", strnum1, strnum2);
    if (!strcmp(strnum1, "0") || !strcmp(strnum2, "0"))
    {
        puts("0");
        return 0;
    }
    int strlen1 = strlen(strnum1);
    int strlen2 = strlen(strnum2);
    int len1 = 0;
    int len2 = 0;
    for (int i = strlen1 - 1; i >= 0; i--)
    {
        if (isdigit(strnum1[i]))
        {
            num1[len1++] = strnum1[i] - '0';
        }
    }
    for (int i = strlen2 - 1; i >= 0; i--)
    {
        if (isdigit(strnum2[i]))
        {
            num2[len2++] = strnum2[i] - '0';
        }
    }
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            ans[i + j] += num2[i] * num1[j];
        }
    }
    int swap_tmp;
    for (int i = 0; i < len1 + len2 + 1; i++)
    {
        swap_tmp = ans[i] / 10;
        ans[i] %= 10;
        ans[i + 1] += swap_tmp;
    }
    char *dot1 = strchr(strnum1, '.');
    char *dot2 = strchr(strnum2, '.');
    int dotlen1, dotlen2;
    dotlen1 = dotlen2 = 0;
    if (dot1)
    {
        dotlen1 = strlen(dot1 + 1);
    }
    if (dot2)
    {
        dotlen2 = strlen(dot2 + 1);
    }
    int anslen = 0;
    for (int i = 0; i < len1 + len2 + 1; i++)
    {
        if (i == dotlen1 + dotlen2)
        {
            ansstr[anslen++] = '.';
        }
        ansstr[anslen++] = ans[i] + '0';
    }
    if ((strnum1[0] == '-' && strnum2[0] != '-') || (strnum1[0] != '-' && strnum2[0] == '-'))
    {
        putchar('-');
    }
    int anspos1 = anslen - 1;
    int anspos2 = 0;
    for (int i = anslen - 1; i >= 0; i--)
    {
        if (ansstr[i] == '0')
        {
            anspos1--;
        }
        else
        {
            break;
        }
    }
    if (ansstr[anspos1] == '.')
    {
        anspos1++;
    }
    for (int i = 0; i < anslen; i++)
    {
        if (ansstr[i] == '0')
        {
            anspos2++;
        }
        else
        {
            break;
        }
    }
    if (ansstr[anspos2] == '.')
    {
        anspos2++;
    }
    for (int i = anspos1; i >= anspos2; i--)
    {
        putchar(ansstr[i]);
    }
    putchar('\n');
    return 0;
}
