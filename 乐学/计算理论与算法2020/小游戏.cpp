#include <iostream>
#include <cstring>
#define MAXN 2010
using namespace std;
int dp[MAXN][2];
int f[MAXN];
int v[MAXN];
int n;
void dfs(int r)
{
    v[r] = 1;
    for (int i = 0; i < n; i++)
    {
        if (!v[i] && f[i] == r)
        {
            dfs(i);
            dp[r][1] += dp[i][0];
            dp[r][0] += min(dp[i][0], dp[i][1]);
        }
    }
    dp[r][0]++;
}
int main(int argc, char const *argv[])
{
    // int n;
    while (~scanf("%d", &n))
    {
        int r;
        int id, idcnt;
        int t;
        memset(dp, 0, sizeof(dp));
        memset(f, 0, sizeof(f));
        memset(v, 0, sizeof(v));
        for (int i = 0; i < n; i++)
        {
            scanf("%d:(%d)", &id, &idcnt);
            if (i == 0)
            {
                r = id;
            }
            for (int j = 0; j < idcnt; j++)
            {
                scanf("%d", &t);
                f[t] = id;
            }
        }
        dfs(r);
        printf("%d\n", min(dp[r][0], dp[r][1]));
    }
    return 0;
}
