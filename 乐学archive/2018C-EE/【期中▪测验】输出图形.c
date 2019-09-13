#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    int height, ch = 0;
    const char Alphabet[] = "ABDFGIJKLMOPQSUVWXZ";
    scanf("%d %c", &height, &ch);

    ch = ch - (ch > 'C') - (ch > 'E') - (ch > 'H') - (ch > 'N') - (ch > 'R') - (ch > 'T') - (ch > 'Y');
    ch = ch - 'A' + 190;

    if (height == 1)
    {
        printf("%c\n", Alphabet[ch++ % 19]);
        return 0;
    }
    for (int i = 0; i < 2 * height - 1; i++)
        putchar(Alphabet[ch++ % 19]);
    putchar('\n');

    for (int i = 0; i < height - 2; ch += 2, i++)
        printf("%*c%*c\n", i + 2, Alphabet[ch % 19], 2 * height - 2 * i - 4, Alphabet[(ch + 1) % 19]);

    printf("%*c\n", height, Alphabet[ch++ % 19]);

    for (int i = 0; i < height - 2; ch += 2, i++)
        printf("%*c%*c\n", height - i - 1, Alphabet[ch % 19], 2 * i + 2, Alphabet[(ch + 1) % 19]);

    for (int i = 0; i < 2 * height - 1; i++)
        putchar(Alphabet[ch++ % 19]);
    putchar('\n');
    return 0;
}
