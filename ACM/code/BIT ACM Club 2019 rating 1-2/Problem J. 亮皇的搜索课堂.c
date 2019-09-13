#include <stdio.h>
#include <string.h>
const char *dict[8] = {"bob", "Bob", "bOb", "boB", "BOb", "BoB", "bOB", "BOB"};
extern char *gets(char *);
int main(int argc, char const *argv[])
{
    char str[1000];
    char *pos = str + 1000;
    char *tmp;
    gets(str);
    for (int i = 0; i < 8; i++)
    {
        tmp = strstr(str, dict[i]);
        if (tmp && tmp < pos)
        {
            pos = tmp;
        }
    }
    if (pos != str + 1000)
        printf("%ld\n", pos - str);
    else
        puts("-1");
    return 0;
}
