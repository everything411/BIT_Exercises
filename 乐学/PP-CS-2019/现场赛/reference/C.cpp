// from http://xzm2001.cn/archives/51/
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll

const int INF = 0x3f3f3f3f;
const int MAXN = 100000+10;
int n;
int a[MAXN];
int b[MAXN];
void solve()
{
    a[0] = a[n+1] = INF;
    for(int i = 1; i <= n; i++ ){
        b[i] = 1;
    }
    for(int i = 1; i <= n; i++ ){
        if( a[i] > a[i-1] ) b[i] = max( b[i], b[i-1]+1 );
    }
    for(int i = n; i >= 1; i-- ){
        if( a[i] > a[i+1] ) b[i] = max( b[i], b[i+1]+1 );
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++ ){
        // printf("%d\n", b[i]);
        ans += 1ll*b[i];
    }
    printf("%lld\n", ans);
}
int main(int argc, char * argv[]) 
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++ ){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}

/*
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct edge{
    int to,next;
}e[100010];
int head[100010],cnt;
int I[100010];
inline void ins(int u,int v)
{
    e[++cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
    I[v]++;
}
int n,a[100010],tot[100010];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",a+i);
    for (int i=1;i<n;i++)
    {
        if (a[i]>a[i+1])ins(i+1,i);
        if (a[i]<a[i+1])ins(i,i+1);
    }
    ll ans=0;
    queue<int>q;while (!q.empty())q.pop();
    for (int i=1;i<=n;i++)if (!I[i])q.push(i),ans+=(tot[i]=1);
    while(!q.empty())
    {
        int now=q.front(),d=tot[now]+1;q.pop();
        for (int i=head[now];i;i=e[i].next)
        {
            tot[e[i].to]=max(tot[e[i].to],d);
            I[e[i].to]--;
            if (!I[e[i].to])q.push(e[i].to),ans+=tot[e[i].to];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
*/