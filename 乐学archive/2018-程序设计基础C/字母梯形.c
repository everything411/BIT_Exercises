#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char *Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int height;
    char ch = 0;
    scanf("%d %c", &height, &ch);
    ch = ch - 'A';
    char(*buffer)[3 * height - 1];
    buffer = (char(*)[3 * height - 1]) malloc(height * (3 * height - 1) * sizeof(char));
    memset(buffer, ' ', height * (3 * height - 1) * sizeof(char));
    for (int i = 0; i < height; i++)
    {
        buffer[i][2 * height - 2 + i] = Alphabet[(ch + 2 * height + i - 2) % 26];
        buffer[i][2 * height - 1 + i] = 0;
    }
    for (int i = 0; i < height - 1; i++)
        buffer[0][height - 1 + i] = Alphabet[(ch + i + height - 1) % 26];
    for (int i = 0; i < height - 2; i++)
        buffer[height - 2 - i][i + 1] = Alphabet[(ch + i + 1) % 26];
    for (int i = 0; i < 3 * height - 2; i++)
        buffer[height - 1][i] = Alphabet[(ch + i) % 26];

    for (int i = 0; i < height; i++)
        puts(buffer[i]);
    free(buffer);
    return 0;
}
