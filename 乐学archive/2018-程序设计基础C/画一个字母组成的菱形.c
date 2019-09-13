#include <stdio.h>
int main(int argc, char const *argv[])
{
    int height, ch = 0;
    const char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    scanf("%c,%d", &ch, &height);
    if (height == 1)
    {
        printf("%c\n", ch);
        return 0;
    }
    ch = ch - 'A' + 26;
    printf("%*c\n", height, Alphabet[ch++ % 26]);
    for (i = 1; i < height; i++)
    {
        printf("%*c%*c\n", height - i, Alphabet[ch % 26], 2 * i, Alphabet[ch % 26]);
        ch++;
    }
    ch -= 2;
    for (i = height - 2; i > 0; i--)
    {
        printf("%*c%*c\n", height - i, Alphabet[ch % 26], 2 * i, Alphabet[ch % 26]);
        ch--;
    }
    printf("%*c\n", height, Alphabet[ch % 26]);
    return 0;
}
