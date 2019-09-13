#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char number[500];
    char *dot_pos;
    while (~scanf("%s", number))
    {
        dot_pos = strchr(number, '.');
        if (dot_pos)
            printf("%zd\n", strlen(dot_pos + 1));
        else
            puts("0");
    }
    return 0;
}
