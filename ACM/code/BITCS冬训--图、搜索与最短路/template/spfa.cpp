#include <bits/stdc++.h>
using namespace std;
int matrix[100][100]; //邻接矩阵
bool visited[100];    //标记数组
int dist[100];        //源点到顶点i的最短距离
int path[100];        //记录最短路的路径
int enqueue_num[100]; //记录入队次数
int vertex_num;       //顶点数
int edge_num;         //边数
int s;                //源点
bool SPFA()
{
    memset(visited, 0, sizeof(visited));
    memset(enqueue_num, 0, sizeof(enqueue_num));
    for (int i = 0; i < vertex_num; i++)
    {
        dist[i] = inf
            path[i] = s;
    }

    queue<int> Q;
    Q.push(s);
    dist[s] = 0;
    visited[s] = 1;
    enqueue_num[s]++;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        visited[u] = 0;
        for (int v = 0; v < vertex_num; v++)
        {
            if (matrix[u][v] != inf) //u与v直接邻接
            {
                if (dist[u] + matrix[u][v] < dist[v])
                {
                    dist[v] = dist[u] + matrix[u][v];
                    path[v] = u;
                    if (!visited[v])
                    {
                        Q.push(v);
                        enqueue_num[v]++;
                        if (enqueue_num[v] >= vertex_num)
                            return false;
                        visited[v] = 1;
                    }
                }
            }
        }
    }
    return true;
}