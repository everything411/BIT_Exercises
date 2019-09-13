#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000
typedef long long ll_t;
int tree[MAXN];
int val[MAXN];
void push(int rt)
{
    tree[rt].v = max(seg[rt << 1].v, seg[rt << 1 | 1].v);
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
void updata(int n, int add, int l, int r, int rt) //单点更新 ，n这个位置的值加add
{
    int m = (l + r) / 2;
    if (l == r)
    {
        tree[rt] += add;
        return;
    }
    if (n <= m) //更新点在左区间
    {
        updata(n, add, l, m, rt << 1);
    }
    else //更新点在右区间
    {
        updata(n, add, m + 1, r, rt << 1 | 1);
    }
    push(rt);
}
int Query(int L, int R, int l, int r, int rt) //[l,r]区间查询
{
    int m = (l + r) / 2;
    int ans = 0;
    if (L <= l && r <= R)
    {
        return tree[rt];
    }
    if (L <= m)
    {
        ans += Query(L, R, l, m, rt << 1);
    }
    if (R > m)
    {
        ans += Query(L, R, m + 1, r, rt << 1 | 1);
    }
    return ans;
}

/* with lazy */
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
