#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p[1005];
int dp[1005];
int n, m;
int main(int argc, char *argv[])
{
    while (scanf("%d", &n) == 1)
    {
        if (n == 0)
            break;

        for (int i = 1; i <= n; ++i)
            scanf("%d", &p[i]);
        scanf("%d", &m);

        if (m < 5)
        {
            printf("%d\n", m);
            continue;
        }

        sort(p + 1, p + 1 + n);

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n - 1; ++i)
        {
            for (int j = m - 5; j >= p[i]; --j)
                dp[j] = max(dp[j], dp[j - p[i]] + p[i]);
        }

        int maxcost = 0;
        for (int i = 0; i <= m - 5; ++i)
            maxcost = max(maxcost, dp[i]);

        printf("%d\n", m - maxcost - p[n]);
    }

    return 0;
}
