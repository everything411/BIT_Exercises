#include <algorithm>
#include <cmath>
#define MAXN 10000
using namespace std;
int st[MAXN][20];
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
