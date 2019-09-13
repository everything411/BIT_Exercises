#include <stdio.h>
int main(int argc, char const *argv[])
{
    int height;
    const char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ch;
    int index;
    int i,j;
    scanf("%d\n%c", &height, &ch);
    ch -= 'A';
    index = ch;
    for (i = 0; i < height - 1; i++)
    {
        printf("%*c", height - i, Alphabet[index % 26]);
        if (i)
            printf("%*c", 2 * i, Alphabet[index % 26]);
        index++;
        putchar('\n');
    }
    for (j = 0; j < height; j++)
    {
        putchar(Alphabet[index++ % 26]);
    }
    index -= 2;
    for (j = 0; j < height - 1; j++)
    {
        putchar(Alphabet[index-- % 26]);
    }
    putchar('\n');
    return 0;
}
