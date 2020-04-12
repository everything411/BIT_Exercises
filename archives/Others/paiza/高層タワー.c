#include <stdio.h>
#include <string.h>
extern char *gets(char *);
char ans[10010];
int get_offset(char *str, int len, char *append)
{
    int offset = len;
    while (offset > 0)
        if (strncmp(str + len - offset, append, offset))
            offset--;
        else
            break;
    return offset;
}
int main(void)
{
    int count;
    int len;
    int offset;
    char str[110];
    scanf("%d", &count);
    getchar();
    for (int i = 0; i < count; i++)
    {
        len = strlen(ans);
        gets(str);
        offset = get_offset(ans, len, str);
        strcpy(ans + len - offset, str);
    }
    puts(ans);
    return 0;
}