#include <stdio.h>
void generate_mine_map(int row, int col, char mine[row][col], int pos_row, int pos_col);
int main(int argc, char const *argv[])
{
    int row, col;
    int count = 1;
    while (scanf("%d%d", &row, &col) && row && col)
    {
        char mine[row][col + 1];
        for (int i = 0; i < row; i++)
            scanf("%s", mine[i]);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                generate_mine_map(row, col + 1, mine, i, j);
        printf(count > 1 ? "\nField #%d:\n" : "Field #%d:\n", count);
        for (int i = 0; i < row; i++)
            puts(mine[i]);
        count++;
    }
    return 0;
}
void generate_mine_map(int row, int col, char mine[row][col], int pos_row, int pos_col)
{
    col--;
    if (mine[pos_row][pos_col] == '*')
        return;
    int count = '0';
    count += pos_row && pos_col && mine[pos_row - 1][pos_col - 1] == '*';
    count += pos_col && mine[pos_row][pos_col - 1] == '*';
    count += pos_row + 1 != row && pos_col && mine[pos_row + 1][pos_col - 1] == '*';
    count += pos_row && mine[pos_row - 1][pos_col] == '*';
    count += pos_row + 1 != row && mine[pos_row + 1][pos_col] == '*';
    count += pos_row && pos_col + 1 != col && mine[pos_row - 1][pos_col + 1] == '*';
    count += pos_col + 1 != col && mine[pos_row][pos_col + 1] == '*';
    count += pos_col + 1 != col && pos_row + 1 != row && mine[pos_row + 1][pos_col + 1] == '*';
    mine[pos_row][pos_col] = count;
    return;
}