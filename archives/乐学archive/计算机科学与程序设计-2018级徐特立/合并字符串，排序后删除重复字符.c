#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(const void *i, const void *j);
int main(int argc, char const *argv[])
{
    char str1[512], str2[512];
    int i;
    scanf("%s%s", str1, str2);
    strcat(str1, str2);
    qsort(str1, strlen(str1), sizeof(char), compare);
    for (i = 0; str1[i] != 0; i++)
        if (i != 0 && str1[i - 1] == str1[i])
        {
            memmove(&str1[i - 1], &str1[i], strlen(&str1[i - 1]));
            i--;
        }
    puts(str1);
    return 0;
}
int compare(const void *i, const void *j)
{
    return (int)*((const char *)i) - (int)*((const char *)j);
}