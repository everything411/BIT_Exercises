#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[1024];
    int count[128] = {0};
    fgets(str, 1024, stdin);
    int len = strlen(str);
    str[--len] = 0;
    for (int i = 0; i < len; count[str[i++]]++)
        ;
    for (int i = 0; i < 128; i++)
        if (count[i])
            printf("%c=%d\n", i, count[i]);
    putchar('\n');
    return 0;
}
