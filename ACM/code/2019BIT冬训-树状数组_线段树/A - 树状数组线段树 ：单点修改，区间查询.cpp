#include <cstdio>
#include <iostream>
#define MAXN 5000005
using namespace std;
class tree_t
{
  private:
    int n;
    inline int lowbit(int x);

  public:
    long long C[MAXN];
    inline void len(int val);
    inline void add(int i, long long k);
    inline long long sum(int x);
};
tree_t tree;
int main(int argc, char const *argv[])
{
    int len, query;
    int op, op1;
    long long op2;
    scanf("%d%d", &len, &query);
    tree.len(len);
    for (int i = 0; i < len; i++)
    {
        scanf("%lld", &op2);
        tree.add(i + 1, op2);
    }
    for (int i = 0; i < query; i++)
    {
        scanf("%d%d%lld", &op, &op1, &op2);
        if (op == 1)
        {
            tree.add(op1, op2);
        }
        else
        {
            printf("%lld\n", tree.sum(op2) - tree.sum(op1 - 1));
        }
    }

    return 0;
}
inline void tree_t::len(int val)
{
    n = val;
}
inline int tree_t::lowbit(int x)
{
    return x & (-x);
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
