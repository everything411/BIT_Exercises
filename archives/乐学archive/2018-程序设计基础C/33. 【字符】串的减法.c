#include <stdio.h>
#include <string.h>
char *gets(char *s);
int main(int argc, char const *argv[])
{
    char str1[128] = {0};
    char str2[128] = {0};
    char str_new[128] = {0};
    gets(str1);
    gets(str2);
    int len = strlen(str1);
    int len_new = 0;
    for (int i = 0; i < len; i++)
        if (!strchr(str2, str1[i]))
            str_new[len_new++] = str1[i];
    puts(str_new);
    return 0;
}