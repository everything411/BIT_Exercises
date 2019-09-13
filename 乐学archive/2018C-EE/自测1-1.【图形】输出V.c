#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(int argc, char const *argv[])
{
    int row_count;
    int ch = 0;
    scanf("%d %c", &row_count, &ch);
    ch -= 'A'; //to use ch as array index
    char shape[row_count][4 * row_count - 2];
    memset(shape, ' ', sizeof(shape));
    for (int i = 0; i < row_count; i++)
    {
        shape[i][4 * row_count - 3] = 0;
        shape[row_count - i - 1][0] = Alphabet[(ch + 2 * row_count + i - 2) % 26];
        shape[row_count - i - 1][4 * row_count - 4] = Alphabet[(ch + 2 * row_count + i - 2) % 26];
        shape[i][4 * row_count - i * 2 - 4] = Alphabet[(ch + i) % 26];
        shape[i][i * 2] = Alphabet[(ch + i) % 26];
        shape[row_count - 1][2 * row_count - 2 + i * 2] = Alphabet[(ch + row_count + i - 1) % 26];
        shape[row_count - 1][2 * row_count - 2 - i * 2] = Alphabet[(ch + row_count + i - 1) % 26];
    }
    //line 16 && line 17 will destroy the first line of the picture, so we need to repair it
    shape[0][0] = Alphabet[ch];
    shape[0][4 * row_count - 4] = Alphabet[ch];
    for (int i = 0; i < row_count; i++)
        puts(shape[i]);
    return 0;
}
