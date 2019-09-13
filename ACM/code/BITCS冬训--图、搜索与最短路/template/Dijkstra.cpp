int dist[maxn], vis[maxn], pre[maxn];
void dijkstra(int n, int s)
{
    for (int i = 1; i <= n; ++i)
    {
        dist[i] = inf;
        vis[i] = false;
        pre[i] = -1;
    }
    dist[s] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int k = -1, minn = inf;
        for (int j = 1; j <= n; ++j)
        {
            if (!vis[j] && dist[j] < minn)
            {
                minn = dist[j];
                k = j;
            }
        }
        if (k == -1)
            break;
        vis[k] = true;
        for (int j = 1; j <= n; ++j)
        {
            if (!vis[j] && dist[k] + cost[k][j] < dist[j])
            {
                dist[j] = dist[k] + cost[k][j];
                pre[j] = k;
            }
        }
    }
}