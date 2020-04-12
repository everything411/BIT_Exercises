#include <iostream>
using namespace std;
int dp[100];
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int m = n * (n + 1);
    int ans;
    if (m % 4)
    {
        ans = 0;
    }
    else
    {
        m /= 4;
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = m; j > i; j--)
            {
                dp[j] += dp[j - i - 1];
            }
        }
        ans = dp[m] / 2;
    }
    printf("%d\n", ans);
    return 0;
}
