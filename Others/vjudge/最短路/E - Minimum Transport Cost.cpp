#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
// 最大顶点数
const int MAXN = 2010;
// 最大边数
const int MAXM = 200010;
int M, N;
class ShortestPath
{
  public:
    // 边结构体的定义
    struct Edge
    {
        int to, next, w;
    };
    Edge edge[MAXM];
    int head[MAXN], num, dist[MAXN], vist[MAXN], cnt[MAXN], pre[MAXN], next[MAXN][MAXN];
    struct HeapNode
    {
        int dist, u;
        bool operator<(const HeapNode &rhs) const
        {
            return dist > rhs.dist;
        }
    };
    inline void init()
    {
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                if (i == j)
                    mat[i][j] = 0;
                else
                    mat[i][j] = INF;
        // 链式前向星初始化，只需要初始化顶点数组和num的值
        memset(head, -1, sizeof(head));
        num = 0;
    }
    //邻接表部分
    // dijkstra算法
    inline void Dijkstra(int s)
    {
        priority_queue<HeapNode> Q;
        memset(vist, false, sizeof(vist));
        for (int i = 0; i <= N; i++)
            dist[i] = INF, pre[i] = i;
        dist[s] = 0;
        Q.push((HeapNode){0, s});
        while (!Q.empty())
        {
            HeapNode x = Q.top();
            Q.pop();
            int u = x.u;
            if (vist[u])
                continue;
            vist[u] = true;
            for (int i = head[u]; i != -1; i = edge[i].next)
            {
                if (dist[edge[i].to] > dist[u] + edge[i].w)
                {
                    pre[edge[i].to] = u;
                    dist[edge[i].to] = dist[u] + edge[i].w;
                    Q.push((HeapNode){dist[edge[i].to], edge[i].to});
                }
            }
        }
    }
    // SPFA算法（优化的Bellman-Ford算法）
    inline bool SPFA(int s)
    {
        queue<int> Q;
        memset(vist, 0, sizeof(vist));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i <= N; i++)
            dist[i] = INF, pre[i] = i;
        dist[s] = 0;
        vist[s] = true;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            vist[u] = false;
            for (int i = head[u]; i != -1; i = edge[i].next)
            {
                if (dist[edge[i].to] > dist[u] + edge[i].w)
                {
                    dist[edge[i].to] = dist[u] + edge[i].w;
                    pre[edge[i].to] = u;
                    if (!vist[edge[i].to])
                    {
                        Q.push(edge[i].to);
                        vist[edge[i].to] = true;
                        if (++cnt[edge[i].to] > N)
                            return false;
                    }
                }
            }
        }
        return true;
    }
    inline void AddEdge(int a, int b, int w)
    {
        edge[num].to = b;
        edge[num].w = w;
        edge[num].next = head[a];
        head[a] = num++;
        edge[num].to = a;
        edge[num].w = w;
        edge[num].next = head[b];
        head[b] = num++;
    }
    //邻接矩阵部分
    int mat[MAXN][MAXN];
    inline bool spfa(int s)
    {
        queue<int> Q;
        memset(vist, 0, sizeof(vist));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i <= N; i++)
            dist[i] = INF, pre[i] = i;
        dist[s] = 0;
        vist[s] = true;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            vist[u] = false;
            for (int i = 1; i <= N; i++)
                if (mat[u][i] + dist[u] < dist[i])
                {
                    dist[i] = mat[u][i] + dist[u];
                    pre[i] = u;
                    if (!vist[i])
                    {
                        Q.push(i);
                        vist[i] = true;
                        if (++cnt[i] > N)
                            return false;
                    }
                }
        }
        return true;
    }
    inline void dijkstra(int s)
    {
        priority_queue<HeapNode> Q;
        for (int i = 0; i <= N; i++)
            dist[i] = INF, pre[i] = i;
        dist[s] = 0;
        memset(vist, false, sizeof(vist));
        Q.push((HeapNode){0, s});
        while (!Q.empty())
        {
            HeapNode x = Q.top();
            Q.pop();
            int u = x.u;
            if (vist[u])
                continue;
            vist[u] = true;
            for (int i = 1; i <= N; i++)
            {
                if (mat[u][i] + dist[u] < dist[i])
                {
                    pre[i] = u;
                    dist[i] = mat[u][i] + dist[u];
                    Q.push((HeapNode){dist[i], i});
                }
            }
        }
    }
    //floyd算法
    inline void floyd()
    {
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                next[i][j] = j;
        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    if (mat[i][k] != INF && mat[k][j] != INF)
                    {
                        int t = mat[i][k] + mat[k][j];
                        if (mat[i][j] > t)
                            mat[i][j] = t, next[i][j] = next[i][k];
                        else if (mat[i][j] == t && next[i][j] > next[i][k])
                            next[i][j] = next[i][k];
                    }
    }
    inline void addedge(int a, int b, int w)
    {
        if (mat[a][b] > w)
            mat[a][b] = w;
        if (mat[b][a] > w)
            mat[b][a] = w;
    }
    inline void FindNext(int e)
    {
        int i = e;
        while (pre[i] != i)
        {
            next[pre[i]][e] = i;
            i = pre[i];
        }
    }
};
ShortestPath sp;
//sp.init()初始化
//基于邻接表
//sp.AddEdge(a,b,w)插入一条从a到b权值为w的边
//sp.Dijkstra(s)以s为起点的dijkstra算法
//sp.SPFA(s)以s为起点的SPFA算法
//基于邻接矩阵
//sp.addedge(a,b,w)插入一条从a到b权值为w的边
//sp.dijkstra(s)以s为起点的dijkstra算法
//sp.spfa(s)以s为起点的SPFA算法
//sp.FindNext寻找路径
//sp.floyd()求全局最短路
//sp.head[i]链式前向星起点,M 输入边数,N 点数,sp.num 过程边数;
//sp.dist[i] 某点到i点的距离,sp.vist[i] 标记数组,sp.cnt[i] 记录入队次数判断负环;
//pre[i] 记录前结点保存路径,next[i] 记录后结点保存路径;
int main()
{
    while (scanf("%d %d", &i, &j), i != -1 || j != -1)
    {
        printf("From %d to %d :\n", i, j);
        printf("Path: %d", i);
        x = i;
        while (x != j)
        {
            printf("-->%d", sp.next[x][j]);
            x = sp.next[x][j];
        }
        printf("\n");
        printf("Total cost : %d\n\n", sp.mat[i][j]);
    }
    return 0;
}
