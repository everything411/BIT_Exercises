#include <cstring>
#include <cstdio>
#include <queue>
#include <map>
#include <string>
#define INF 0x3f3f3f
using namespace std;
// 最大顶点数
const int MAXN = 1000;
// 最大边数
const int MAXM = 1000;
// 边结构体的定义
struct Edge
{
    int to;         // 表示这条边的另外一个顶点
    int next;       // 指向下一条边的数组下标，值为-1表示没有下一条边
    int w;          //表示这条边的权值
};

Edge edge[MAXM];
// head[i] 表示顶点`i`的第一条边的数组下标，-1表示顶点`i`没有边
int head[MAXN];
int M,N,num = 0;
int dist[MAXN];
bool vist[MAXN];
// dijkstra算法
struct HeapNode
{
    int dist,u;
    bool operator < (const HeapNode& rhs)const{
        return dist > rhs.dist;
    }
};

void Dijkstra(int s)
{
    priority_queue<HeapNode> Q;
    for(int i = 1 ; i <= N ; i++)dist[i] = INF;
    dist[s] = 0;
    memset(vist,false,sizeof(vist));
    Q.push((HeapNode){0,s});
    while(!Q.empty())
    {
        HeapNode x = Q.top();Q.pop();
        int u = x.u;
        if(vist[u])continue;
        vist[u] = true;
        for(int i = head[u] ; i != -1 ;i = edge[i].next)
        {
            if(dist[edge[i].to] > dist[u]+edge[i].w)
            {
                dist[edge[i].to] = dist[u]+edge[i].w;
                Q.push((HeapNode){dist[edge[i].to],edge[i].to});
            }
        }
    }
}
// SPFA算法（优化的Bellman-Ford算法）
int cnt[MAXN];
int pre[MAXN];
bool SPFA(int s)
{
    queue<int>Q;
    memset(vist,0,sizeof(vist));
    memset(cnt ,0, sizeof(cnt));
    for(int i = 1 ; i <= N ; i++)dist[i] = INF,pre[i] = i;
    dist[s] = 0;
    vist[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        vist[u] = false;
        for(int i = head[u] ; i != -1 ; i = edge[i].next)
        {
            if(dist[u] < INF && dist[edge[i].to] > dist[u] + edge[i].w)
            {
                dist[edge[i].to] = dist[u] + edge[i].w;
                pre[edge[i].to] = i;
                if(!vist[edge[i].to])
                {
                    Q.push(edge[i].to);
                    vist[edge[i].to] = true;
                    if(++cnt[edge[i].to] > N)
                        return false;
                }
            }
        }
    }
    return true;
}
//SPFA || dijkstra基于邻接矩阵
int mat[MAXN][MAXN];
void init()
{
    for(int i = 0 ; i < MAXN ; i++)
        for(int j = 0 ; j < MAXN ; j++)
            mat[i][j] = INF;
    // 链式前向星初始化，只需要初始化顶点数组和num的值
    memset(head, -1, sizeof(head));
    num = 0;
}
bool spfa(int s)
{
    queue<int>Q;
    memset(vist,0,sizeof(vist));
    memset(cnt ,0, sizeof(cnt));
    for(int i = 1 ; i <= N ; i++)dist[i] = INF,pre[i] = i;
    dist[s] = 0;
    vist[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int u =Q.front(); Q.pop();
        vist[u] = false;
        for(int i = 1;i <= N ; i++)
            if(mat[u][i]+dist[u]<dist[i])
            {
                dist[i]=mat[u][i]+dist[u];
                if(!vist[i])
                    Q.push(i),vist[i]=true;
            }
    }
    return true;
}
void dijkstra(int s)
{
    priority_queue<HeapNode> Q;
    for(int i = 1 ; i <= N ; i++)dist[i] = INF;
    dist[s] = 0;
    memset(vist,false,sizeof(vist));
    Q.push((HeapNode){0,s});
    while(!Q.empty())
    {
        HeapNode x = Q.top();Q.pop();
        int u = x.u;
        if(vist[u])continue;
        vist[u] = true;
        for(int i = 1 ; i <= N; i++)
        {
            if(mat[u][i] + dist[u] < dist[i])
            {
                dist[i] = mat[u][i]+dist[u];
                Q.push((HeapNode){dist[i],i});
            }
        }
    }
}
void addedge(int a,int b,int w)
{
    if(mat[a][b]>w)mat[a][b] = w;
    if(mat[b][a]>w)mat[b][a] = w;
}
// 增加边的方式
// 新增边 a -> b，该边的数组下标为`k`
inline void AddEdge(int a, int b, int w)
{
    edge[num].to = b;
    edge[num].w = w;
    edge[num].next = head[a];    // 新增的边要成为顶点`a`的第一条边，而不是最后一条边
    head[a] = num++;
    edge[num].to = a;
    edge[num].w = w;
    edge[num].next = head[b];    // 新增的边要成为顶点`b`的第一条边，而不是最后一条边
    head[b] = num++;
    return;
}

int main()
{
    int star,end,m,a,b,w;
    char aa[35],bb[35];
    map<string,int>loc;
    while(scanf("%d",&M)>0&&M!=-1)
    {
        init(); N=1; loc.clear();
        scanf("%s%s",aa,bb);
        loc[aa]=N; star=N;
        if(!loc[bb]){N++;loc[bb]=N;}
         end=loc[bb];
        for(m = 0 ; m < M ; m++)
        {
            scanf("%s%s%d",aa,bb,&w);
            if(!loc[aa]){N++;loc[aa]=N;}a=loc[aa];
            if(!loc[bb]){N++;loc[bb]=N;}b=loc[bb];
            addedge(a,b,w);
        }
        if(star==end){printf("0\n");continue;}
        dijkstra(star);
        if(dist[end] == INF) dist[end] = -1;
        printf("%d\n",dist[end]);
    }
}
