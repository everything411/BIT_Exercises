#include <stdio.h>
int main(int argc, char const *argv[])
{
    int pos, count;
    char str[256];
    char *del_pos, *next_pos;
    scanf("%s%d%d", str, &pos, &count);
    del_pos = str + pos - 1;
    next_pos = del_pos + count;
    *del_pos = 0;
    printf("%s%s\n", str, next_pos);
    return 0;
}
