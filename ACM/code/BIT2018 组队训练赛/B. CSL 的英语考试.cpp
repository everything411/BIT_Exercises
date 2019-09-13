#include <iostream>
using namespace std;
char order[128];
char str1[1200];
char str2[1200];
int __strcmp(char *s1, char *s2)
{
    int ret = 0;
    while (!(ret = order[(int)*s1] - order[(int)*s2]) && *s1)
    {
        s1++;
        s2++;
    }
    if (ret < 0)
        return -1;
    else if (ret > 0)
        return 1;
    return 0;
}
int main(void)
{
    int count;
    char ch;
    scanf("%d", &count);
    for (int i = 0; i < 26; i++)
    {
        scanf(" %c", &ch);
        order[(int)ch] = i;
    }
    for (int i = 0; i < count; i++)
    {
        scanf("%s%s", str1, str2);
        switch (__strcmp(str1, str2))
        {
        case 1:
            puts(">");
            break;
        case 0:
            puts("=");
            break;
        case -1:
            puts("<");
            break;
        }
    }

    return 0;
}