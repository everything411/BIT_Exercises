#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define power_two(NUM) (1 << (NUM))
void draw(int size, char *base[size], int n, int offset_col, int offset_row);
int main(int argc, char const *argv[])
{
    int i, n;
    scanf("%d", &n);
    /*if (n > 12 || n < 0)
    {
        fprintf(stderr, "Invalid number: too big or too small.\n");
        return 1;
    }*/
    int size = power_two(n + 2);
    int buf_size = size * (size + 1) * sizeof(char);
    char *membuffer = malloc(buf_size);
    memset(membuffer, ' ', buf_size);
    char *shape[size];
    for (i = 0; i < size; i++)
    {
        shape[i] = membuffer + (size + 1) * i;
        *(shape[i] - 1) = 0;
    }
    *(membuffer + (size + 1) * i - 1) = 0;
    draw(size, shape, n, 0, 0);
    for (i = 0; i < size; i++)
        puts(shape[i]);
    free(membuffer);
    return 0;
}
void draw(int size, char *base[size], int n, int offset_col, int offset_row)
{
    int size_curr = power_two(n + 2);
    base[offset_col][offset_row] = '+';
    memset(&base[offset_col][offset_row] + 1, '-', size_curr - 2);
    base[offset_col][offset_row + size_curr - 1] = '+';
    for (int i = 1; i <= size_curr - 2; i++)
    {
        base[offset_col + i][offset_row] = '|';
        base[offset_col + i][offset_row + size_curr - 1] = '|';
    }
    base[offset_col + size_curr - 1][offset_row] = '+';
    memset(&base[offset_col + size_curr - 1][offset_row] + 1, '-', size_curr - 2);
    base[offset_col + size_curr - 1][offset_row + size_curr - 1] = '+';
    for (int i = 2; i <= (size_curr >> 1) - 2; i++)
    {
        base[offset_col + i][offset_row + (size_curr >> 1) - i] = '/';
        base[offset_col + i][offset_row + (size_curr >> 1) + i - 1] = '\\';
    }
    n--;
    if (n >= 0)
        draw(size, base, n, offset_col + (size_curr >> 1), offset_row + (size_curr >> 2));
    return;
}