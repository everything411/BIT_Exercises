#include <iostream>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
#define MAXN 2010   // 最大顶点数
#define MAXM 200010 // 最大边数
using namespace std;
class ShortestPath
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
    int N;
    Edge edge[MAXM];
public:
    int head[MAXN];
    int num;
    int dist[MAXN];
    int vist[MAXN];
    int cnt[MAXN];
    int pre[MAXN];
    int next[MAXN][MAXN];
    void init(int __N);
    void Dijkstra(int s);
    bool SPFA(int s);
    void AddEdge(int a, int b, int w);
    void FindNext(int e);
};

ShortestPath sp;
int main(int argc, char const *argv[])
{
    int n, ml, md;
    int a, b, d;
    scanf("%d%d%d", &n, &ml, &md);
    sp.init(n);

    for (int i = 0; i < ml; i++)
    {
        scanf("%d%d%d", &a, &b, &d);
        sp.AddEdge(a, b, d);
    }
    for (int i = 0; i < md; i++)
    {
        scanf("%d%d%d", &a, &b, &d);
        sp.AddEdge(b, a, -d);
    }
    if (sp.SPFA(1))
    {
        if (sp.dist[n] == INF)
        {
            puts("-2");
        }
        else
        {
            printf("%d\n", sp.dist[n]);
        }
    }
    else
    {
        puts("-1");
    }
    return 0;
}

void ShortestPath::init(int __N)
{
    // 链式前向星初始化，只需要初始化顶点数组和num的值
    memset(head, -1, sizeof(head));
    num = 0;
    N = __N;
}
//邻接表部分
// SPFA算法（优化的Bellman-Ford算法）
bool ShortestPath::SPFA(int s)
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
void ShortestPath::AddEdge(int a, int b, int w)
{
    edge[num].to = b;
    edge[num].w = w;
    edge[num].next = head[a];
    head[a] = num++;
    // edge[num].to = a;
    // edge[num].w = w;
    // edge[num].next = head[b];
    // head[b] = num++;
}
