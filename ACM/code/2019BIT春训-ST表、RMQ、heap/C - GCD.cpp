#include <iostream>
#include <cmath>
#include <map>
using namespace std;
#define MAXN 100040
int st[MAXN][20];
int values[MAXN];
map<int, long long> num_map;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
void init(int *value, int n)
{
    for (int i = 1; i <= n; i++)
        st[i][0] = value[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int query(int left, int right)
{
    int k = log2(right - left + 1);
    //可以在初始化的时候预处理所有的log2
    return gcd(st[left][k], st[right - (1 << k) + 1][k]);
}
int main(int argc, char const *argv[])
{
    int case_count;
    int num_count;
    int query_count;
    int l, r;
    scanf("%d", &case_count);

    for (int i = 0; i < case_count; i++)
    {
        num_map.clear();
        scanf("%d", &num_count);
        for (int i = 1; i <= num_count; i++)
        {
            scanf("%d", &values[i]);
        }
        init(values, num_count);
        scanf("%d", &query_count);

        for (int i = 1; i <= num_count; i++)
        {
            int tmp;
            int ll = i;
            while (ll <= num_count)
            {
                tmp = query(i, ll);
                int l = ll;
                int r = num_count - 1;
                while (l < r)
                {
                    int mid = (l + r + 1) >> 1;
                    if (query(i, mid) >= tmp)
                        l = mid;
                    else
                        r = mid - 1;
                }
                num_map[tmp] += l - ll + 1;
                ll = l + 1;
            }
        }
        printf("Case #%d:\n", i + 1);
        for (int i = 0; i < query_count; i++)
        {
            scanf("%d%d", &l, &r);
            printf("%d %lld\n", query(l, r), num_map[query(l, r)]);
        }
    }

    return 0;
}