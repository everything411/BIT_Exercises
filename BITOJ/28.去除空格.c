#include <stdio.h>
int main(int argc, char const *argv[])
{
    int len = 0;
    char str[10240] = {0};
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (ch != ' ')
        {
            str[len++] = ch;
        }
    }
    printf("%d\n%s\n", len, str);
    return 0;
}
