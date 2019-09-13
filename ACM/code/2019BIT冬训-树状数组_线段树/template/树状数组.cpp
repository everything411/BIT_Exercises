#define MAXN 100000
int C[MAXN];
inline int lowbit(int x)
{
    return x & (-x);
}
void change(int i, int k)
{
    while (i <= n)
        C[i] += k, i += lowbit(i);
}
int sum(int x)
{
    int ret = 0;
    while (x)
        ret += C[x], x -= lowbit(x);
    return ret;
}
/* 多维 */
int update(int x, int y, int z)
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
int sum(int x, int y)
{
    int res = 0;
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
