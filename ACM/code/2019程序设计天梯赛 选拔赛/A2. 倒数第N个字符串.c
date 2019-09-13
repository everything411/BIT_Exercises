#include <stdio.h>
int main(int argc, char const *argv[])
{
    int len, pos;
    char str[7] = {'z', 'z', 'z', 'z', 'z', 'z', 0};
    scanf("%d%d", &len, &pos);
    pos--;
    for (int i = 0; i < len; i++)
    {
        int tmp = pos;
        for (int j = 0; j < i; j++)
        {
            tmp /= 26;
        }
        str[len - i - 1] -= tmp % 26;
    }
    str[len] = 0;
    puts(str);
    return 0;
}
