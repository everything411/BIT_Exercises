// from http://xzm2001.cn/archives/51/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 210;
const int mod = 1000000007;

int ans[maxn][maxn];
int res, n;
char ss[maxn];

int work(int l) {
    memset(ans, 0, sizeof(ans));
    int n1 = l, n2 = n - l - 1;
    for(int i=1; i<=n1; ++i)
        ans[i][0] = ans[i-1][0] + (ss[i-1] == ss[l] ? 1 : 0);
    for(int i=1; i<=n1; ++i)
        for(int j=1; j<=n2; ++j) {
            ans[i][j] = (ans[i][j-1] + ans[i-1][j])%mod;
            if(ss[i-1] != ss[l+j])
                ans[i][j] = (ans[i][j] - ans[i-1][j-1] + mod)%mod;
        }
    return ans[n1][n2];
}
void solve() {
    res = 0;
    n = strlen(ss);
    for(int i=1; i<n; ++i)
        res = (res + work(i))%mod;
    printf("%d\n", res);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", ss);
        solve();
    }
}