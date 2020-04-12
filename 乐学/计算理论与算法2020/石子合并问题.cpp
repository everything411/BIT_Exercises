#include <iostream>
#define MAXN 300
#define INF 0x3f3f3f3f
using namespace std;
int s[MAXN];
int sum[MAXN];
int maxdp[MAXN][MAXN];
int mindp[MAXN][MAXN];
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        s[i + n] = s[i];
    }
    sum[0] = s[0];
    for (int i = 1; i < 2 * n; i++)
    {
        sum[i] = sum[i - 1] + s[i];
    }

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < i + n; j++)
        {
            mindp[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                mindp[i][j] = min(mindp[i][j], mindp[i][k] + mindp[k + 1][j] + sum[j] - sum[i - 1]);
                maxdp[i][j] = max(maxdp[i][j], maxdp[i][k] + maxdp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    int minans = INF;
    int maxans = 0;
    for (int i = 0; i < n; i++)
    {
        minans = min(minans, mindp[i][i + n - 1]);
        maxans = max(maxans, maxdp[i][i + n - 1]);
    }
    printf("%d\n%d\n", minans, maxans);
    return 0;
}
