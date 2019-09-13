//堆优化
struct edge
{
    int to, cost;
};
typedef pair<int, int> P; //first是最短距离，second是顶点的编号
int V;                    //顶点个数
vector<edge> G[MAXV];
int d[MAXV];
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P>> que;
    memset(d, INF, sizeof d);
    d[s] = 0;
    que.push(P(0, s)); //把起点推入队列
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second; //顶点的编号
        if (d[v] < p.first)
            continue;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}