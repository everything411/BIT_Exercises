#include <iostream>
#include <map>
#define POW_TWO(i) (1 << (i))
#define MAXN 128
using namespace std;
int adjec[MAXN][MAXN];
int result[MAXN][MAXN];
int points[MAXN];
int main(int argc, char const *argv[])
{
    int div;
    scanf("%d", &div);
    for (int i = 1; i <= div; i++)
    {
        int tmp = POW_TWO(i - 1);
        int p = 0;
        for (int k = tmp; k < 2 * tmp; k++)
        {
            adjec[p][k] = adjec[k][p] = 1;
            p++;
        }
        for (int m = 0; m < tmp; m++)
        {
            for (int n = 0; n < tmp; n++)
            {
                adjec[m + tmp][n + tmp] = adjec[m][n];
            }
        }
    }
    int num;
    int i = 0;
    while (scanf("%d", &num) != EOF)
    {
        points[num] = i++;
    }
    int index = POW_TWO(div);
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = i + 1; j < index; j++)
        {
            if (adjec[i][j])
            {
                int a = points[i];
                int b = points[j];
                result[a][b] = result[b][a] = 1;
            }
        }
    }
    for (int i = 0; i < index; i++)
    {
        for (int j = 0; j < index; j++)
        {
            if (j == index - 1)
            {
                printf("%d\n", result[i][j]);
            }
            else
            {
                printf("%d ", result[i][j]);
            }
        }
    }
    return 0;
}
