#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 200000 + 50
using namespace std;
long long siz[MAXN];
long long depth[MAXN];
bool vis[MAXN];
long long sum[MAXN];
vector<int> vec[MAXN];
long long odd, even;
long long ans;
int n;
int a, b;
long long dfs(int id, long long dep)
{
    if (vis[id])
    {
        return 0;
    }
    else
    {
        siz[id] = 1;
    }
    vis[id] = 1;
    depth[id] = dep;
    if (vec[id].empty())
    {
        return siz[id];
    }
    for (auto &&i : vec[id])
    {
        siz[id] += dfs(i, dep + 1);
    }
    return siz[id];
}
void dfs_sum(int id)
{
    if (vis[id])
    {
        return;
    }
    vis[id] = 1;
    if (vec[id].empty())
    {
        sum[id] = siz[id] * (n - siz[id]);
        return;
    }
    for (auto &&i : vec[id])
    {
        dfs_sum(i);
    }
    sum[id] = siz[id] * (n - siz[id]);
}
int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1, 1);
    memset(vis, 0, sizeof(vis));
    dfs_sum(1);
    for (int i = 1; i <= n; i++)
    {
        ans += sum[i];
        if (depth[i] & 1) //odd
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    printf("%lld\n", (ans + odd * even) / 2);
    return 0;
}
