#include <iostream>
using namespace std;
int table[30][120];
void init(void)
{
    for (int i = 0; i < 120; i++)
    {
        table[3][i] = 12000;
        table[4][i] = 12000;
        table[5][i] = 12000;
        table[6][i] = 18000;
        table[7][i] = 18000;
        table[8][i] = 24000;
        table[9][i] = 24000;
        table[10][i] = 24000;
        table[11][i] = 36000;
        table[12][i] = 36000;
    }
    for (int i = 13; i < 30; i++)
    {
        for (int j = 0; j < 120; j++)
        {
            table[i][j] = 48000;
        }
    }

    table[1][30] = 1500;
    table[1][40] = 2000;
    table[1][50] = 2400;
    table[1][60] = 2900;
    table[1][70] = 3400;
    table[1][80] = 3900;
    table[1][90] = 4400;
    table[1][100] = 4800;
    table[1][110] = 5300;

    table[2][25] = 2400;
    table[2][30] = 2900;
    table[2][40] = 3900;
    table[2][50] = 4800;
    table[2][60] = 5800;
    table[2][70] = 6800;
    table[2][80] = 7700;
    table[2][90] = 8700;
    table[2][100] = 9600;
    table[2][110] = 10600;

    table[3][25] = 4800;
    table[3][30] = 5800;
    table[3][40] = 7700;
    table[3][50] = 9600;
    table[3][60] = 11600;

    table[4][25] = 9600;
    table[4][30] = 11600;
}
int main(void)
{
    init();
    int t;
    int x, y;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", table[x][y]);
    }

    return 0;
}