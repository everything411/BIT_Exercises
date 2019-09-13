#include <cstdio>
//#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 2000
using namespace std;
int st[MAXN][20];
int values[2000];
void init(int *value, int n)
{
    for (int i = 1; i <= n; i++)
        st[i][0] = value[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int query(int left, int right)
{
    int k = log2(right - left + 1);
    //可以在初始化的时候预处理所有的log2
    return max(st[left][k], st[right - (1 << k) + 1][k]);
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
        scanf("%d", &num_count);
        for (int i = 1; i <= num_count; i++)
        {
            scanf("%d", &values[i]);
        }
        init(values, num_count);
        scanf("%d", &query_count);

        for (int i = 0; i < query_count; i++)
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", query(l, r));
        }
    }

    return 0;
}
