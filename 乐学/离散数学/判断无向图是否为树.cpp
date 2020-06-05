#include <iostream>
using namespace std;
#define N 100
int a[N][N];
int vis[N];
int n;
int dfs(int x)
{
    if (vis[x])
    {
        return 0;
    }
    vis[x] = 1;
    for (int i = x + 1; i < n; i++)
    {
        if (a[x][i])
        {
            if (vis[i])
            {
                return 0;
            }
            else if (!dfs(i))
            {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int result = dfs(0);
    if (result)
    {
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                result = 0;
            }
        }
    }
    if (result)
    {
        puts("yes");
    }
    else
    {
        puts("no");
    }
    return 0;
}