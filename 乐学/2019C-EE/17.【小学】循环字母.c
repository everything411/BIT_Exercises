#include <stdio.h>
#include <ctype.h>
char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lower[] = "abcdefghijklmnopqrstuvwxyz";
int main(int argc, char const *argv[])
{
    int c = 0;
    scanf("%c", &c);
    if (isupper(c))
    {
        c -= 'A';
        for (size_t i = 0; i < 26; i++)
        {
            putchar(upper[c++ % 26]);
        }
        putchar('\n');
    }
    else if (islower(c))
    {
        c -= 'a';
        for (size_t i = 0; i < 26; i++)
        {
            putchar(lower[c++ % 26]);
        }
        putchar('\n');
    }
    else
    {
        puts("Oops");
    }

    return 0;
}
