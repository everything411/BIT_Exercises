#include <stdio.h>
#include <string.h>
#define MASK 0x80000000
int is_back(char *str);
int main(int argc, char const *argv[])
{
    int number;
    char str_num[33] = {0};
    scanf("%d", &number);
    for (int i = 0; i < 32; i++)
        str_num[i] = '0' + ((number & (MASK >> i)) >> (31 - i));
    fputs(str_num, stderr);
    char *start = strchr(str_num, '1');
    if (!start)
    {
        puts("Yes!0=0");
        return 0;
    }
    if (is_back(start))
        printf("Yes!%d=%s\n", number, start);
    else
        puts("No");
    return 0;
}
int is_back(char *str)
{
    int len = strlen(str);
    int half = len / 2;
    for (int i = 0; i < half; i++)
        if (str[i] != str[len - i - 1])
            return 0;
    return 1;
}