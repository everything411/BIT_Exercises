#include <iostream>
#include <cstring>
#define INFINITY 0x3f3f3f3f
#define MAX_VERTEX_NUM 1010
using namespace std;
struct ArcCell
{
    int adj;
};
struct MGraph
{
    int vexs[MAX_VERTEX_NUM];
    ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum;
    int arcnum;
};
struct closedge
{
    int adjvex;
    int lowcost;
} closedge[MAX_VERTEX_NUM];
void CreateUDN(MGraph &G)
{
    int w;
    int v1, v2;
    memset(&G, 0x3F, sizeof(G));
    scanf("%d", &G.vexnum);
    scanf("%d", &G.arcnum);
    for (int i = 0; i < G.vexnum; i++)
    {
        G.vexs[i] = i + 1;
    }
    for (int k = 0; k < G.arcnum; ++k)
    {
        scanf(" %d %d %d", &v1, &v2, &w);
        G.arcs[v1][v2].adj = G.arcs[v2][v1].adj = w;
    }
}

int MiniSpanTree_PRIM(MGraph &G, int u)
{
    int ans = 0;
    for (int j = 1; j <= G.vexnum; ++j)
    {
        if (j != u)
        {
            closedge[j].adjvex = u;
            closedge[j].lowcost = G.arcs[u][j].adj;
        }
    }
    closedge[u].lowcost = 0;
    for (int i = 2; i <= G.vexnum; ++i)
    {
        int min = INFINITY;
        int k = 0;
        for (int i = 1; i <= G.vexnum; i++)
        {
            if (closedge[i].lowcost && min > closedge[i].lowcost)
            {
                min = closedge[i].lowcost;
                k = i;
            }
        }
        if (min == INFINITY)
        {
            return -1;
        }
        ans += min;
        closedge[k].lowcost = 0;
        for (int j = 1; j <= G.vexnum; ++j)
        {
            if (G.arcs[k][j].adj < closedge[j].lowcost)
            {
                closedge[j].adjvex = G.vexs[k];
                closedge[j].lowcost = G.arcs[k][j].adj;
            }
        }
    }

    return ans;
}
MGraph m;
int main(int argc, char const *argv[])
{
    CreateUDN(m);
    int ans = MiniSpanTree_PRIM(m, 1);
    printf("%d\n", ans);
    return 0;
}
