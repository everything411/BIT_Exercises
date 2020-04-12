#include <stdio.h>
#include <string.h>
inline static void draw(int real_size, int matrix[real_size][real_size], int value, int row, int col)
{
    int size = (real_size + 1) / 2;
    for (int i = 0; i < size; i++)
        matrix[row - i][col + i] = value++;
}
int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);
    int real_size = 2 * size - 1;
    int matrix[real_size][real_size];
    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < size; i++)
    {
        draw(real_size, matrix, i * size + 1, size + i - 1, i);
    }
    for (int i = 0; i < real_size; i++)
    {
        for (int j = 0; j < real_size; j++)
            if (matrix[i][j])
                printf("%3d", matrix[i][j]);
        putchar('\n');
    }
    return 0;
}
