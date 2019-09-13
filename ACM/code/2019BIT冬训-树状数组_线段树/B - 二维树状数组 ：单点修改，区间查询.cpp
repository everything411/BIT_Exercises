#include <cstdio>
#include <iostream>
#define DIM 2
#define MAXM 5000
#define MAXN 5000
using namespace std;
class tree_t
{
  private:
    int n;
    int m;
    inline int lowbit(int x);

  public:
#if DIM == 1
    long long C[MAXN];
    inline void len(int val);
    inline void add(int i, long long k);
    inline long long sum(int x);
#else
    long long c[MAXN][MAXM];
    inline void size(int m, int n);
    inline void update(int x, int y, long long val);
    inline long long sum(int x, int y);
#endif
};
tree_t tree;
int main(int argc, char const *argv[])
{
    int m, n;
    int op;
    scanf("%d%d", &n, &m);
    tree.size(m, n);
    while (~scanf("%d", &op))
    {
        if (op == 1)
        {
            int x, y;
            long long val;
            scanf("%d%d%lld", &x, &y, &val);
            tree.update(x, y, val);
        }
        else
        {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            printf("%lld\n", tree.sum(c, d) + tree.sum(a - 1, b - 1) - tree.sum(c, b - 1) - tree.sum(a - 1, d));
        }
    }
    return 0;
}

inline int tree_t::lowbit(int x)
{
    return x & (-x);
}
#if DIM == 1
inline void tree_t::len(int val)
{
    n = val;
}
inline void tree_t::add(int i, long long k)
{
    while (i <= n)
    {
        C[i] += k;
        i += lowbit(i);
    }
}
inline long long tree_t::sum(int x)
{
    long long ret = 0;
    while (x)
    {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}
#else
inline void tree_t::size(int __m, int __n)
{
    m = __m;
    n = __n;
}
inline void tree_t::update(int x, int y, long long val)
{
    int i = x;
    while (i <= n)
    {
        int j = y;
        while (j <= m)
        {
            c[i][j] += val;
            j += lowbit(j);
        }
        i += lowbit(i);
    }
}
inline long long tree_t::sum(int x, int y)
{
    long long res = 0;
    int i = x;
    while (i > 0)
    {
        int j = y;
        while (j > 0)
        {
            res += c[i][j];
            j -= lowbit(j);
        }
        i -= lowbit(i);
    }
    return res;
}
#endif