#include <iostream>
#include <algorithm>
using namespace std;
int n;
int p[20][20];
int q[20][20];
int w[20][20];
int x[20];
int m_sum[20];
int ans;
int cc;
void backtrack(int t)
{
    if (t > n)
    {
        if (cc > ans)
            ans = cc;
    }
    else
    {
        int t_sum = 0;
        for (int i = t; i <= n; i++)
        {
            t_sum += m_sum[i];
        }
        for (int j = t; j <= n; j++)
        {
            swap(x[t], x[j]);
            cc += w[t][x[t]];
            if (cc + t_sum > ans)
            {
                backtrack(t + 1);
            }
            cc -= w[t][x[t]];
            swap(x[t], x[j]);
        }
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &q[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            w[i][j] = p[i][j] * q[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m_sum[i] = max(m_sum[i], w[i][j]);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        x[i] = i;
    }
    backtrack(0);
    printf("%d\n", ans);
    return 0;
}
