#include <stdio.h>
int main(int argc, char const *argv[])
{
    int height, ch = 0;
    const char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    scanf("%d %c", &height, &ch);
    if (height == 1)
    {
        printf("%c\n", ch);
        return 0;
    }
    ch -= 'A';
    printf("%*c\n", height, Alphabet[ch++ % 26]);
    for (i = 1; i < height; i++)
    {
        printf("%*c%*c\n", height - i, Alphabet[ch % 26], 2 * i, Alphabet[(ch + height * 4 - 4 - 2 * i) % 26]);
        ch++;
    }
    for (i = height - 2; i > 0; i--)
    {
        printf("%*c%*c\n", height - i, Alphabet[ch % 26], 2 * i, Alphabet[(ch + 2 * i) % 26]);
        ch++;
    }
    printf("%*c\n", height, Alphabet[ch++ % 26]);
    return 0;
}
