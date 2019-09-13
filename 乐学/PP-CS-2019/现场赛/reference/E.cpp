// from http://xzm2001.cn/archives/51/
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int h[MAXN][MAXN];
int vis[MAXN][MAXN];
int n, m;

struct node{
    int x, y;
    int height;
    node(){}
    node( int x, int y, int height): x(x), y(y), height(height) {}
};
struct cmp{
    bool operator()( node a, node b ){
        return a.height > b.height;
    }
};
priority_queue<node, vector<node>, cmp> q;
void solve()
{
    for(int i = 1; i <= n; i++ ){
        vis[i][1] = vis[i][m] = 1;
        q.push( node( i, 1, h[i][1]) );
        q.push( node( i, m, h[i][m]) );
    }
    for(int j = 2; j < m; j++ ){
        vis[1][j] = vis[n][j] = 1;
        q.push( node( 1, j, h[1][j]) );
        q.push( node( n, j, h[n][j]) );
    }
    ll ans = 0;
    while( !q.empty() ){
        node now = q.top();
        q.pop();
        int hh = now.height;
        for(int i = 0; i < 4; i++ ){
            int x = now.x+dx[i];
            int y = now.y+dy[i];
            if( x < 1 || x > n || y < 1 || y > m ) continue;
            if( vis[x][y] ) continue;
            vis[x][y] = 1;
            if( hh > h[x][y] ){
                ans += 1ll*(hh-h[x][y]);
                h[x][y] = hh;
            }
            q.push( node( x, y, h[x][y]) );
        }
    }
    printf("%lld\n", ans);
}
int main(int argc, char * argv[])
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++ ){
        for(int j = 1; j <= m; j++ ){
            scanf("%d", &h[i][j]);
        }
    }
    solve();
    return 0;
}