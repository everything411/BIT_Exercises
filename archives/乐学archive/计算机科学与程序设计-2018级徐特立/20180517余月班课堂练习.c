#include <stdio.h>
int main(int argc, char const *argv[])
{
    char ch;
    while ((ch = getchar()) != '0')
        if (ch != ' ')
            putchar(ch);
    putchar('\n');
    return 0;
}
