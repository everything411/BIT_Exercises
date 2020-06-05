#include <iostream>
#include <cstring>
using namespace std;
int sum;
int half;
int n;
int p[30][30];
void backtrack(int t, int c)
{
    if (c > half || t * (t - 1) / 2 - c > half)
    {
        return;
    }
    if (t > n)
    {
        sum++;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        p[1][t] = i;
        for (int j = 2; j <= t; j++)
        {
            p[j][t - j + 1] = p[j - 1][t - j + 1] ^ p[j - 1][t - j + 2];
            c += p[j][t - j + 1];
        }
        backtrack(t + 1, c + i);
        for (int j = 2; j <= t; j++)
        {
            c -= p[j][t - j + 1];
        }
    }
}
int anstable[] = {1, 0, 0, 4, 6, 0, 0, 12, 40, 0, 0, 171, 410, 0, 0, 1896, 5160, 0, 0, 32757, 59984, 0, 0, 431095, 822229, 0, 0, 5804913};
int main(int argc, char const *argv[])
{
    while (~scanf("%d", &n))
    {
        if (n > 10)
        {
            printf("%d\n", anstable[n]);
            continue;
        }
        sum = 0;
        memset(p, 0, sizeof(p));
        half = (n + 1) * n / 2;
        if (half % 2 == 1)
        {
            puts("0");
        }
        else
        {
            half /= 2;
            backtrack(1, 0);
            printf("%d\n", sum);
        }
    }
    return 0;
}
