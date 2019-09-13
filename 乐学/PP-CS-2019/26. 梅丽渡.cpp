#include <iostream>
// #include <cstring>
#define NEGA_INF (int)0x8f8f8f8f
#define MAXN 500010
using namespace std;
long long beauty_val[MAXN];
long long dp[5][MAXN];
int main(void)
{
    int n;
    long long ans = NEGA_INF;
    scanf("%d", &n);
    // memset(dp, 0x8f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", beauty_val + i);
    }
    for (int i = 1; i <= 3; i++)
    {
        long long max_previous = NEGA_INF;
        for (int j = i; j <= n; j++)
        {
            if (i == j)
            {
                dp[i][j] = dp[i - 1][j - 1] + beauty_val[j];
                continue;
            }
            max_previous = max(max_previous, dp[i - 1][j - 1]);
            dp[i][j] = max(dp[i][j - 1], max_previous) + beauty_val[j];
        }
    }
    for (int i = 3; i <= n; i++)
    {
        ans = max(ans, dp[3][i]);
    }
    printf("%lld\n", ans);
    return 0;
}