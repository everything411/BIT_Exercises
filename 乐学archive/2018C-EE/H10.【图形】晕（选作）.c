#include <stdio.h>
#include <stdlib.h>
enum state
{
    right,
    down,
    left,
    up
};
int main(int argc, char const *argv[])
{
    int count, size, **num;
    int row, col;
    int col_min, row_min, col_max, row_max;
    enum state state = right;
    _Bool state_changed_last_time = 1;
    scanf("%d", &size);
    col_max = row_max = size - 1;
    col_min = row_min = 0;
    count = row = col = 0;
    num = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++)
        *(num + i) = (int *)malloc(sizeof(int) * size);
    while (count < size * size - 1)
    {
        *(*(num + row) + col) = ++count;
        if (!state_changed_last_time)
        {
            if ((col == col_max) && (row == row_min))
            {
                state = down;
                state_changed_last_time = 1;
                row_min++;
            }
            else if ((col == col_max) && (row == row_max))
            {
                state = left;
                state_changed_last_time = 1;
                col_max--;
            }
            else if ((col == col_min) && (row == row_max))
            {
                state = up;
                state_changed_last_time = 1;
                row_max--;
            }
            else if ((col == col_min) && (row == row_min))
            {
                state = right;
                state_changed_last_time = 1;
                col_min++;
            }
        }
        else
            state_changed_last_time = 0;
        switch (state)
        {
        case right:
            col++;
            break;
        case left:
            col--;
            break;
        case up:
            row--;
            break;
        case down:
            row++;
            break;
        }
    }
    if(size % 2)
        *(*(num + size / 2) + size / 2) = size * size;
    else
        *(*(num + size / 2) + size / 2 - 1) = size * size;
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
            printf("%3d", *(*(num + row) + col));
        putchar('\n');
    }
    return 0;
}