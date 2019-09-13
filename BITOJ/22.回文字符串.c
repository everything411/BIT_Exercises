#include <stdio.h>
#include <string.h>
char *gets(char *s);
int is_back(char *str)
{
    int len = strlen(str);
    int half = len / 2;
    for (int i = 0; i < half; i++)
        if (str[i] != str[len - i - 1])
            return -1;
    return half + (len & 1);
}
int main(int argc, char const *argv[])
{
    char str[100];
    gets(str);
    printf("%d\n", is_back(str));
    return 0;
}
