#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str1[256], str2[256];
    int len1, len2;
    int len;
    scanf("%s%s", str1, str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    for (len = 0; len < len1; len++)
        if (!strchr(str2, str1[len]))
            putchar(str1[len]);
    for (len = 0; len < len1; len++)
        if (!strchr(str1, str2[len]))
            putchar(str2[len]);
    putchar('\n');
    return 0;
}
