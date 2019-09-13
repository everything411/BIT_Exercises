// from http://xzm2001.cn/archives/51/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
int dp[105][66666];
ll k;
char A[105], B[105];
int a[105];
inline int get(ll x)
{
    static unordered_map<ll, int> dic;
    static int sz = 0;
    if (dic.count(x)) return dic[x];
    return dic[x] = sz++;
}
int dfs(int pos, ll mul, int lead, int flag)
{
    if (mul == 0) return 0;
    if (pos == -1) return mul == 1;
    int h = get(mul);
    if (!flag && !lead && ~dp[pos][h]) return dp[pos][h];
    int sum = 0;
    int up = flag ? a[pos] : 9;
    for (int i = 0; i <= up; i++)
    {
        if (i == 0 && !lead) continue;
        if (i == 0)
            sum += dfs(pos - 1, mul, lead && i == 0, flag && i == a[pos]);
        else if (mul % i == 0)
            sum += dfs(pos - 1, mul / i, lead && i == 0, flag && i == a[pos]);
        if (sum >= MOD) sum -= MOD;
    }
    if (!flag && !lead) dp[pos][h] = sum;
    return sum;
}
int solve(char* c)
{
    int len = strlen(c);
    int pos = 0;
    for (int i = 0; i < len; i++)
        a[pos++] = c[len - 1 - i] - '0';
    return dfs(pos - 1, k, 1, 1);
}
void _minus(char* c)
{
    int len = strlen(c);
    reverse(c, c + len);
    //    cout << c << endl;
    int flag = 1, len1 = 1;
    for (int i = 0; i < len; i++)
    {
        if (flag)
            if (c[i] == '0')
                c[i] = '9';
            else
                c[i]--, flag = 0;
        if (c[i] != '0') len1 = i + 1;
    }
    //    cout << "LEN: "<<len1 << endl;
    reverse(c, c + len1);
    c[len1] = '\0';
}
int fac[] = {2, 3, 5, 7};
int main()
{
    memset(dp, -1, sizeof(dp));
    int T;
    scanf("%d", &T);
    long long TT = 0;
    while (T--)
    {
        scanf("%s%s%lld", A, B, &k);
        ll K = k;
        for (int i = 0; i < 4; i++)
            while (K % fac[i] == 0) K /= fac[i];
        if (K != 1)
        {
            printf("0\n");
            continue;
        }
        _minus(A);
        int ans = solve(B) - solve(A);
        if (ans < 0) ans += MOD;
        printf("%d\n", ans);
        TT += ans;
    }
    cout << TT << endl;
}