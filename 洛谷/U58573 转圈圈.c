#include <stdio.h>
#include <string.h>
#define BACK 0
#define FORWARD 1
char get_alpha(void)
{
    static char ch = 'A';
    static int state = FORWARD;
    if (state == FORWARD)
    {
        if (ch == 'Z')
        {
            state = BACK;
            return ch--;
        }
        return ch++;
    }
    else
    {
        if (ch == 'A')
        {
            state = FORWARD;
            return ch++;
        }
        return ch--;
    }
}
int main(int argc, char const *argv[])
{
    int size;
    int count = 1;
    int pos_row = 0, pos_col = 0;
    scanf("%d", &size);
    char matrix[size][size];
    memset(matrix, 0, sizeof(matrix));
    matrix[0][0] = get_alpha();
    while (count < size * size)
    {
        while (pos_col + 1 < size && !matrix[pos_row][pos_col + 1])
        {
            matrix[pos_row][++pos_col] = get_alpha();
            count++;
        }
        while (pos_row + 1 < size && !matrix[pos_row + 1][pos_col])
        {
            matrix[++pos_row][pos_col] = get_alpha();
            count++;
        }
        while (pos_col - 1 >= 0 && !matrix[pos_row][pos_col - 1])
        {
            matrix[pos_row][--pos_col] = get_alpha();
            count++;
        }
        while (pos_row - 1 >= 0 && !matrix[pos_row - 1][pos_col])
        {
            matrix[--pos_row][pos_col] = get_alpha();
            count++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
