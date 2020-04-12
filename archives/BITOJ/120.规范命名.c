#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    char ch;
    putchar(getchar() + 'a' - 'A');
    while (~(ch = getchar()))
        if (isupper(ch))
        {
            putchar('_');
            putchar(ch - 'A' + 'a');
        }
        else if (islower(ch))
        {
            putchar(ch);
        }
    putchar('\n');
    return 0;
}
