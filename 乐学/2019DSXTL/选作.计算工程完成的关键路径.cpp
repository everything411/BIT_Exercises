#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
#define OK true
#define ERROR false
#define INF 0x3f3f3f3f
#define MAXN 200 // 最大顶点数
int vexnum;
int arcnum;
int ve[MAXN];
int vl[MAXN];
int indegree[MAXN];
int linknum[MAXN];
int link[MAXN][MAXN];
int mat[MAXN][MAXN];
int topo[MAXN];
int critical[4 * MAXN];
char value[MAXN][20];
int critical_count;
void AddEdge(int a, int b, int w)
{
    link[a][linknum[a]++] = b;
    mat[a][b] = w;
    indegree[b]++;
}
int linkcmp(const void *p1, const void *p2)
{
    return *(const int *)p1 > *(const int *)p2;
}
int topocmp(const void *p1, const void *p2)
{
    return *(const int *)p1 < *(const int *)p2;
}
void sort_edge(void)
{
    for (int i = 0; i < vexnum; i++)
    {
        qsort(link[i], linknum[i], sizeof(int), linkcmp);
    }
}
bool TopologicalOrder(void)
{
    int s[MAXN];
    int t[MAXN];
    int s_top, t_top;
    s_top = t_top = 0;
    for (int j = 0; j < vexnum; ++j)
    {
        if (indegree[j] == 0)
        {
            s[s_top++] = j;
        }
    }
    while (s_top)
    {
        int j;
        int k;
        j = s[--s_top];
        t[t_top++] = j;
        for (int p = 0; p < linknum[j]; p++)
        {
            k = link[j][p];
            if (--indegree[k] == 0)
            {
                s[s_top++] = k;
            }
            if (ve[j] + mat[j][k] > ve[k])
            {
                ve[k] = ve[j] + mat[j][k];
            }
        }
        qsort(s, s_top, sizeof(int), topocmp);
    }
    memcpy(topo, t, sizeof(topo));
    if (t_top < vexnum)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }
}
void do_critical_path(int top, int end)
{
    int u = critical[top - 1];
    if (u == end)
    {
        printf("%s", value[critical[0]]);
        for (int i = 1; i < top; i++)
        {
            printf("-%s", value[critical[i]]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < linknum[u]; i++)
    {
        int v = link[u][i];
        if (ve[u] + mat[u][v] < ve[v])
        {
            continue;
        }
        if (ve[v] == vl[v])
        {
            critical[top++] = link[u][i];
            do_critical_path(top, end);
            top--;
        }
    }
}
bool CriticalPath(void)
{
    if (!TopologicalOrder())
    {
        return ERROR;
    }
    else
    {
        for (int i = 0; i < vexnum; i++)
        {
            if (i)
            {
                printf("-");
            }
            printf("%s", value[topo[i]]);
        }
        printf("\n");
    }
    int t[MAXN];
    memcpy(t, topo, sizeof(t));
    int t_top = vexnum;
    for (int a = 0; a < vexnum; a++)
    {
        vl[a] = ve[vexnum - 1];
    }
    while (t_top)
    {
        int j, k;
        int dut;
        j = t[--t_top];
        for (int p = 0; p < linknum[j]; p++)
        {
            k = link[j][p];
            dut = mat[j][k];
            if (vl[k] - dut < vl[j])
            {
                vl[j] = vl[k] - dut;
            }
        }
    }
    critical[0] = topo[0];
    do_critical_path(1, topo[vexnum - 1]);
    return OK;
}

int main(int argc, char const *argv[])
{
    scanf("%d,%d", &vexnum, &arcnum);
    getchar();
    for (int i = 0; i < vexnum - 1; i++)
    {
        scanf("%[^,],", value[i]);
    }
    scanf("%s", value[vexnum - 1]);
    getchar();
    int a, b, w;
    for (int i = 0; i < arcnum; i++)
    {
        scanf("<%d,%d,%d>", &a, &b, &w);
        AddEdge(a, b, w);
        getchar();
    }
    sort_edge();
    if (!CriticalPath())
    {
        puts("NO TOPOLOGICAL PATH");
    }
    return 0;
}
