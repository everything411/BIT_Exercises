#include <iostream>
#include <cstring>
#include <queue>
#define M 100010
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
    int next, to, v, from;
} e[M];

int m, n;
int x, y;
int ecnt = -1;
int head[M];
int deep[M];
int cur[M];
int maxflow;
int source, sink, sum;
queue<int> q;

void add(int x, int y, int z)
{
    e[++ecnt].to = y;
    e[ecnt].v = z;
    e[ecnt].from = x;
    e[ecnt].next = head[x];
    head[x] = ecnt;
}

bool bfs(int s, int t)
{
    memset(deep, -1, sizeof(deep));
    while (!q.empty())
    {
        q.pop();
    }
    for (int i = 0; i <= n + 1; i++)
        cur[i] = head[i];
    deep[s] = 0, q.push(s);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i = head[k]; i != -1; i = e[i].next)
        {
            if (deep[e[i].to] == -1 && e[i].v)
            {
                deep[e[i].to] = deep[k] + 1, q.push(e[i].to);
            }
        }
    }
    if (deep[t] == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int dfs(int s, int t, int limit)
{
    if (!limit || s == t)
    {
        return limit;
    }
    int flow = 0;
    for (int i = cur[s]; i != -1; i = e[i].next)
    {
        cur[s] = i;
        if (deep[e[i].to] != deep[s] + 1)
        {
            continue;
        }
        int f = dfs(e[i].to, t, min(limit, e[i].v));
        if (f)
        {
            e[i].v -= f, e[i ^ 1].v += f;
            limit -= f, flow += f;
            if (!limit)
            {
                break;
            }
        }
    }
    if (!flow)
    {
        deep[s] = -INF;
    }
    return flow;
}

void dinic(int s, int t)
{
    while (bfs(s, t))
    {
        maxflow += dfs(s, t, INF);
    }
}

int main(int argc, char const *argv[])
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &m, &n);
    source = 0, sink = n + 1;
    while (1)
    {
        scanf("%d%d", &x, &y);
        if (x == -1 && y == -1)
        {
            break;
        }
        add(x, y, 1);
        add(y, x, 0);
        sum++;
    }
    for (int i = 1; i <= m; i++)
    {
        add(source, i, 1);
        add(i, source, 0);
    }
    for (int i = m + 1; i <= n; i++)
    {
        add(i, sink, 1);
        add(sink, i, 0);
    }
    dinic(source, sink);
    printf("%d\n", maxflow);
    return 0;
}
