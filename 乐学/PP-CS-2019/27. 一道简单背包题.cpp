#include <iostream>
#define MAXN 2010
using namespace std;
int n, v;
int p;
int dp[MAXN][MAXN];
int main(void)
{
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p);
        dp[i][p % v] = 1;

        // p %= v;
        for (int j = 0; j < v; j++)
        {
            dp[i][j] += dp[i - 1][j] + dp[i - 1][(j + v - p % v) % v];
            dp[i][j] %= 10000000;
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}