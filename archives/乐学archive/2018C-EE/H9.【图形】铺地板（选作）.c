#include <stdio.h>
enum state
{
    right,
    down,
    left_down,
    right_up,
    left,
    up,
    right_down,
    left_up
};
int main(int argc, char const *argv[])
{
    int size, row, col, count;
    row = col = count = 0;
    enum state state;
    scanf("%d", &size);
    int num[size][size];
    state = right;
    while (count < size * (size + 1) / 2)
    {
        num[row][col] = ++count;
        if (col == 0 && row == 0)
            state = right;
        else if (state == right)
            state = left_down;
        else if (state == down)
            state = right_up;
        else if (col == 0)
            state = down;
        else if (row == 0)
            state = right;
        switch (state)
        {
        case right:
            col++;
            break;
        case down:
            row++;
            break;
        case left_down:
            row++;
            col--;
            break;
        case right_up:
            row--;
            col++;
            break;
        default:
            break;
        }
    }
    count = size * size;
    col = row = size - 1;
    //state = left;
    while (count > size * (size + 1) / 2)
    {
        num[row][col] = count--;
        if (col == (size - 1) && row == (size - 1))
            state = left;
        else if (state == left)
            state = right_up;
        else if (state == up)
            state = left_down;
        else if (col == size - 1)
            state = up;
        else if (row == size - 1)
            state = left;
        switch (state)
        {
        case left:
            col--;
            break;
        case up:
            row--;
            break;
        case right_up:
            row--;
            col++;
            break;
        case left_down:
            row++;
            col--;
            break;
        default:
            break;
        }
    }
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
            printf((col == 0) ? "%2d" : "%3d", num[row][col]);
        putchar('\n');
    }
    return 0;
}