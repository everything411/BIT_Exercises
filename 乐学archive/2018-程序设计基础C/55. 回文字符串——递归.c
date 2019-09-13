#include <stdio.h>
#include <string.h>
int is_back(char *, char *);
int main(int argc, char const *argv[])
{
    char str[1024] = {0};
    fgets(str, 1024, stdin);
    int len = strlen(str);
    str[len-- - 1] = 0;
    if (len == 0)
    {
        puts("Yes");
        return 0;
    }
    if (len == 2)
        if (str[0] == str[1])
        {
            puts("Yes");
            return 0;
        }
        else
        {
            puts("No");
            return 0;
        }
    if (is_back(str, str + len - 1))
        puts("Yes");
    else
        puts("No");
    return 0;
}
int is_back(char *start, char *end)
{
    if (end - start < 2)
        if (*end == *start)
            return 1;
        else
            return 0;
    if (*start == *end)
        return is_back(start + 1, end - 1);
    else
        return 0;
}