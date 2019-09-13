#include <iostream>
#define MAXN 2010
#define MOD 2147483647
using namespace std;
long long dp[MAXN][MAXN];
int arr[MAXN];
long long ans;

int main(void)
{
    int n;
    int firstleft;
    int left, right;
    scanf("%d%d", &n, &firstleft);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    dp[0][firstleft] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            left = min(j, arr[i - 1]);
            right = max(j, arr[i - 1]);
            if (arr[i] > left)
            {

                dp[i][left] += dp[i - 1][j];
                dp[i][left] %= MOD;
            }
            if (arr[i] < right)
            {
                dp[i][right] += dp[i - 1][j];
                dp[i][right] %= MOD;
            }
        }
    }
    for (int i = 1; i <= n + 1; i++)
    {
        ans += dp[n - 1][i];
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}