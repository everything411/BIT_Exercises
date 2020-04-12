#include <stdio.h>
int main(int argc, char const *argv[])
{
    int height;
    const char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ch;
    int index;
    int i;
    scanf("%d\n%c", &height, &ch);
    if (height == 1) {
        putchar(ch);
        putchar('\n');
        return 0;
    }
    ch -= 'A';
    index = ch;
    printf("%*c", height, Alphabet[index++ % 26]);
    for (i = 0; i < height / 2 - 1; i++)
        putchar(Alphabet[index++ % 26]);
    if (height % 2)
        putchar(Alphabet[index % 26]);
    index--;
    for (i = 0; i < ((height % 2) ? (height - height / 2 - 1) : (height - height / 2)); i++)
        putchar(Alphabet[index-- % 26]);
    putchar('\n');
    index += 2;
    for (i = 0; i < height - 2; i++)
    {
        printf("%*c%*c\n", height - i - 1, Alphabet[index % 26], 2 * i + height + 1, Alphabet[index % 26]);
        index++;
    }
    for (i = 0; i < (3 * height - 2) / 2; i++)
        putchar(Alphabet[index++ % 26]);
    if (!(height % 2))
        index--;
    for (i = 0; i < 3 * height - 2 - (3 * height - 2) / 2; i++)
        putchar(Alphabet[index-- % 26]);
    putchar('\n');
    return 0;
}
