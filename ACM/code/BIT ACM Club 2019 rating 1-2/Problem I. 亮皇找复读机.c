#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern char *gets(char *);
void del_char(char *str)
{
    while ((*str = *(str + 1)))
        str++;
}
int diff_check(char *str1, char *str2)
{
    puts("Unimplemented function.hahaha");
    return -1;
}
char str1[1000];
char str2[1000];
int main(int argc, char const *argv[])
{
    gets(str1);
    gets(str2);
    if (diff_check(str1, str2))
        puts("YES");
    else
        puts("NO");
    return 0;
}
