#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000
typedef long long ll_t;
ll_t tree[MAXN];
ll_t val[MAXN];
ll_t sum[MAXN];
bool lazy[MAXN];
void PushUp(int rt)
{
    tree[rt] = max(val[rt << 1], val[rt << 1 | 1]);
}
void build(int L, int R, int rt) //递归建树
{
    int m = (L + R) / 2;
    if (L == R)
    {
        tree[rt] = val[rt];
        return;
    }
    build(L, m, rt << 1);         //建左子树
    build(m + 1, R, rt << 1 | 1); //建右子树
    push(rt);
}
void update(int L, int R, int c, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        lazy[rt] += c;
        sum[rt] += (ll_t)c * (r - l + 1);
        return;
    }
    PushDown(rt, r - l + 1); //更新时一定要先把lazy下放
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, lson);
    if (m < R)
        update(L, R, c, rson);
    PushUp(rt);
}
void PushDown(int rt, int m) //lazy标记下放操作
{
    if (lazy[rt])
    {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        sum[rt << 1] += lazy[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += lazy[rt] * (m >> 1);
        lazy[rt] = 0;
    }
}
ll_t query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    PushDown(rt, r - l + 1); //先下放lazy标记
    int m = (l + r) >> 1;
    ll_t ret = 0;
    if (L <= m)
        ret += query(L, R, lson);
    if (m < R)
        ret += query(L, R, rson);
    return ret;
}
int main()
{
    int n, q;
    int op;
    int l, r;
    long long val;
    scanf("%d%d", &n, &q);
    build(1, n, 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &val);
        update(n, val, i + 1, i + 1, 1);
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%lld", &l, &r, &val);
            update(n, val, l, r, 1);
        }
        else
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", Query(l, r, 1, n, 1));
        }
    }
    return 0;
}