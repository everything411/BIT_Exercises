#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern char *gets(char *);
void del_char(char *str)
{
    while ((*str = *(str + 1)))
        str++;
}
char *get_revstr(char *str)
{
    int len = strlen(str);
    char *mem = (char *)calloc(len + 1, 1);
    int pos = 0;
    for (int i = len - 1; i >= 0; i--)
        mem[pos++] = str[i];
    return mem;
}
int diff_check(char *str1, char *str2)
{
    int pos = 0;
    int len = strlen(str1);
    while (str1[pos] && str2[pos])
    {
        if (str1[pos] == str2[pos])
        {
            pos++;
        }
        else
        {
            char *try_1 = (char *)malloc(len + 1);
            char *try_2 = (char *)malloc(len + 1);
            memcpy(try_1, str1, len + 1);
            memcpy(try_2, str2, len + 1);
            del_char(try_1 + pos);
            del_char(try_2 + len - 1 - pos);
            if (!strcmp(try_1, try_2))
            {
                return 1;
            }
            else
            {
                memcpy(try_1, str1, len + 1);
                memcpy(try_2, str2, len + 1);
                del_char(try_2 + pos);
                del_char(try_1 + len - 1 - pos);
                if (!strcmp(try_1, try_2))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    //puts("emmmm");
    return -1; //emmmmm
}
char str[100010];
int main(int argc, char const *argv[])
{
    gets(str);
    char *reversed = get_revstr(str);
    if (diff_check(str, reversed))
        puts("YES");
    else
        puts("NO");
    return 0;
}
