#include <stdio.h>
extern char *gets(char *);
int main(void)
{
    char str[200];
    gets(str);
    for (int i = 0; str[i]; i++)
    {
        if (!(i & 1))
            putchar(str[i]);
    }
    putchar('\n');
    return 0;
}