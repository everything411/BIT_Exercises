#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str1[256], str2[256];
    char temp[256];
    char *pos;
    char ch;
    scanf("%s%s %c", str1, str2, &ch);
    pos = strchr(str1, ch);
    strcpy(temp, pos);
    *pos = 0;
    strcat(str1, str2);
    strcat(str1, temp);
    puts(str1);
    return 0;
}
