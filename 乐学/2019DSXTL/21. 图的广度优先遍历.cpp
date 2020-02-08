#include <iostream>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
#define MAXN 200   // 最大顶点数
#define MAXM 20000 // 最大边数
using namespace std;
struct Edge
{
    int to;
    int next;
    // int w;
};
int N;
int num;
Edge edge[MAXM];
int head[MAXN];
char value[MAXN];
bool visited[MAXN];
void AddEdge(int a, int b, int w)
{
    edge[num].to = b;
    // edge[num].w = w;
    edge[num].next = head[a];
    head[a] = num++;
    edge[num].to = a;
    // edge[num].w = w;
    edge[num].next = head[b];
    head[b] = num++;
}
void BFS(int x)
{
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            q.push(i);
            while (!q.empty())
            {
                i = q.front();
                printf("%c", value[i]);
                q.pop();
                for (int j = head[i]; j != -1; j = edge[j].next)
                {
                    if (!visited[edge[j].to])
                    {
                        visited[edge[j].to] = true;
                        q.push(edge[j].to);
                    }
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    char ch;
    memset(head, 0xff, sizeof(head));
    memset(visited, 0, sizeof(visited));

    while (~scanf(" %c", &ch) && ch != '*')
    {
        value[N++] = ch;
    }
    int a, b;
    while (~scanf("%d,%d", &a, &b) && ~a && ~b)
    {
        AddEdge(a, b, 0);
    }
    printf("the ALGraph is\n");
    for (int i = 0; i < N; i++)
    {
        printf("%c", value[i]);
        for (int j = head[i]; j != -1; j = edge[j].next)
        {
            printf(" %d", edge[j].to);
        }
        printf("\n");
    }
    printf("the Breadth-First-Seacrh list:");
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            BFS(i);
        }
    }
    printf("\n");
    return 0;
}
