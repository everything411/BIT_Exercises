#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+50
int n;
struct E{
    int to,nxt;
}e[2*maxn+10];
int k=n+1;
int vis[maxn];
void build(int a,int b)
{
    e[k].nxt=e[a].nxt;
    e[a].nxt=k;
    e[k].to=b;
    k++;
    return;
}
//DFS
void dfs(int s)
{
    for(int i=e[s].nxt;i!=-1;i=e[i].nxt)
    {
        int t=e[i].to;
        if(vis[t]) continue;
        dfs(t);vis[t]=1;
    }
}
//BFS
int s,value[maxn];
queue<int> q;
q.push(s);
while(!q.empty())
{
    int u=q.front();
    q.pop();
    for(int i=e[u].nxt;i!=-1;i=e[i].nxt)
    {
        if(!vis[e[i].to)
        {
            q.push(e[i].to);
            vis[e[i].to]=1;
            //value[e[i].to]=value[i]+1;
        }
    }
}
