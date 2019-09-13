#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    int ch = 0;
    scanf("%c", &ch);
    _Bool isUpper = isupper(ch);
    ch -= isUpper ? 'A' : 'a';
    for (int i = 0; i < 26; i++)
        putchar(ch++ % 26 + (isUpper ? 'A' : 'a'));
    putchar('\n');
    return 0;
}
