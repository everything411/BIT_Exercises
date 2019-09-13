#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
#define MAXN 2010   // 最大顶点数
#define MAXM 200010 // 最大边数
using namespace std;
class ShortestPath_t
{
  private:
    struct Edge // 边结构体的定义
    {
        int to, next, w;
    };
    struct HeapNode
    {
        int dist, u;
        bool operator<(const HeapNode &rhs) const
        {
            return dist > rhs.dist;
        }
    };
    int M, N;
    Edge edge[MAXM];
    int mat[MAXN][MAXN]; //用于邻接矩阵
  public:
    int head[MAXN];
    int num;
    int dist[MAXN];
    int vist[MAXN];
    int cnt[MAXN];
    int pre[MAXN];
    int next[MAXN][MAXN];
    inline void pass_argv(int _N, int _M);
    inline void init(void);
    inline void Dijkstra(int s);
    inline bool SPFA(int s);
    inline void AddEdge(int a, int b, int w);
    inline bool spfa(int s);
    inline void dijkstra(int s);
    inline void floyd(void);
    inline void addedge(int a, int b, int w);
    inline void FindNext(int e);
};
ShortestPath_t sp;
int main(int argc, char const *argv[])
{
    string name1, name2;
    string start, end;
    int point_count, edge_count;
    int rank;
    map<string, int> name_map;
    decltype(name_map.find(name1)) a_point;
    while (~scanf("%d", &edge_count) && ~edge_count)
    {
        name_map.clear();
        sp.init();
        point_count = 0;
        cin >> start >> end;
        name_map[start] = ++point_count;
        name_map[end] = ++point_count;
        for (int i = 0; i < edge_count; i++)
        {
            cin >> name1 >> name2 >> rank;
            if (name_map[name1] == 0)
            {
                name_map[name1] = ++point_count;
            }
            if (name_map[name2] == 0)
            {
                name_map[name2] = ++point_count;
            }
            sp.addedge(name_map[name1], name_map[name2], rank);
        }
        sp.pass_argv(point_count, edge_count);
        sp.dijkstra(name_map[start]);
        if (sp.dist[name_map[end]] != INF)
        {
            printf("%d\n", sp.dist[name_map[end]]);
        }
        else
        {
            puts("-1");
        }
    }

    return 0;
}

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
inline void ShortestPath_t::pass_argv(int _N, int _M)
{
    N = _N;
    M = _M;
}
inline void ShortestPath_t::init(void)
{
    /*
    N = _N;
    M = _M;
    */
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
inline void ShortestPath_t::Dijkstra(int s)
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
inline bool ShortestPath_t::SPFA(int s)
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
inline void ShortestPath_t::AddEdge(int a, int b, int w)
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
inline bool ShortestPath_t::spfa(int s)
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
inline void ShortestPath_t::dijkstra(int s)
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
inline void ShortestPath_t::floyd(void)
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
inline void ShortestPath_t::addedge(int a, int b, int w)
{
    if (mat[a][b] > w)
        mat[a][b] = w;
    if (mat[b][a] > w)
        mat[b][a] = w;
}
inline void ShortestPath_t::FindNext(int e)
{
    int i = e;
    while (pre[i] != i)
    {
        next[pre[i]][e] = i;
        i = pre[i];
    }
}