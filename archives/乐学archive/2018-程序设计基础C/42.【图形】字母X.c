#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    int height, ch = 0;
    const char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    scanf("%d %c", &height, &ch);
    if (!isupper(ch))
    {
        puts("input error.");
        return 0;
    }
    if (height == 1)
    {
        printf("%c\n", ch);
        return 0;
    }
    ch = ch - 'A' + 25 + height + 260;
    for (i = height - 1; i > 0; i--, ch--)
        printf("%*c%*c\n", height - i, Alphabet[ch % 26], 2 * i, Alphabet[ch % 26]);
    printf("%*c\n", height, Alphabet[ch % 26]);
    for (i = 1, ch--; i < height; i++, ch--)
        printf("%*c%*c\n", height - i, Alphabet[ch % 26], 2 * i, Alphabet[ch % 26]);
    return 0;
}
