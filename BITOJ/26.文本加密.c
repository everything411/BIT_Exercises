#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int count;
    char *pos;
    char ch;
    char replace_from[128] = {0};
    char replace_to[128] = {0};
    scanf("%d", &count);
    memset(replace_from, 0, sizeof(replace_from));
    memset(replace_to, 0, sizeof(replace_to));
    for (int i = 0; i < count; i++)
        scanf(" %c %c ", &replace_from[i], &replace_to[i]);
    while ((ch = getchar()) != EOF)
        if ((pos = strchr(replace_from, ch)))
            putchar(replace_to[pos - replace_from]);
        else
            putchar(ch);
    return 0;
}
