#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    int height, ch = 0;
    const char Alphabet[] = "BCDFGHJKLMNPQRSTVWXYZ";
    scanf("%d %c", &height, &ch);

    ch = ch - (ch > 'A') - (ch > 'E') - (ch > 'I') - (ch > 'O') - (ch > 'U');
    ch = ch - 'A' + 2100;

    if (height == 1)
    {
        printf("%c\n", Alphabet[ch++ % 21]);
        return 0;
    }
    for (int i = 0; i < 2 * height - 1; i++)
        putchar(Alphabet[ch++ % 21]);
    putchar('\n');

    for (int i = 0; i < height - 2; ch += 2, i++)
        printf("%*c%*c\n", i + 2, Alphabet[ch % 21], 2 * height - 2 * i - 4, Alphabet[(ch + 1) % 21]);

    printf("%*c\n", height, Alphabet[ch++ % 21]);

    for (int i = 0; i < height - 2; ch += 2, i++)
        printf("%*c%*c\n", height - i - 1, Alphabet[ch % 21], 2 * i + 2, Alphabet[(ch + 1) % 21]);

    for (int i = 0; i < 2 * height - 1; i++)
        putchar(Alphabet[ch++ % 21]);
    putchar('\n');
    return 0;
}
