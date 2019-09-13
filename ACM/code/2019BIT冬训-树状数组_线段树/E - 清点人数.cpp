#include <cstdio>
#include <iostream>
#define DIM 1
#define MAXM 500
#define MAXN 5000005
using namespace std;
class tree_t
{
  private:
    int n;
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
    int len, event;
    char op;
    int index;
    long long val;
    scanf("%d%d", &len, &event);
    tree.len(len);
    for (int i = 0; i < event; i++)
    {
        scanf(" %c%d", &op, &index);
        switch (op)
        {
        case 'A':
            printf("%lld\n", tree.sum(index));
            break;
        case 'B':
            scanf("%lld", &val);
            tree.add(index, val);
            break;
        case 'C':
            scanf("%lld", &val);
            tree.add(index, -val);
            break;
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
            c[i][j] += z;
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