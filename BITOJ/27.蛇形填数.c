#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int size;
    int count = 0;
    int pos_row = 0, pos_col = 0;
    scanf("%d", &size);
    pos_col = size - 1;
    int matrix[size][size];
    memset(matrix, 0, sizeof(matrix));
    matrix[pos_row][pos_col] = ++count;
    while (count < size * size)
    {
        while (pos_row + 1 < size && !matrix[pos_row + 1][pos_col])
        {
            matrix[++pos_row][pos_col] = ++count;
        }
        while (pos_col - 1 >= 0 && !matrix[pos_row][pos_col - 1])
        {
            matrix[pos_row][--pos_col] = ++count;
        }
        while (pos_row - 1 >= 0 && !matrix[pos_row - 1][pos_col])
        {
            matrix[--pos_row][pos_col] = ++count;
        }
        while (pos_col + 1 < size && !matrix[pos_row][pos_col + 1])
        {
            matrix[pos_row][++pos_col] = ++count;
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%3d", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
