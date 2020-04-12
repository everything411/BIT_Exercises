#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(const void *, const void *);
int main(int argc, char const *argv[])
{
    char str[1024] = {0};
    char temp[512] = {0};
    scanf("%s%s", str, temp);
    if (*str == 0)
        puts(temp);
    else if (*temp == 0)
        puts(str);
    else
    {
        strcat(str, temp);
        qsort(str, strlen(str), sizeof(char), compare);
        puts(str);
    }
    return 0;
}
int compare(const void *i, const void *j)
{
    return (int)*((const char *)i) - (int)*((const char *)j);
}