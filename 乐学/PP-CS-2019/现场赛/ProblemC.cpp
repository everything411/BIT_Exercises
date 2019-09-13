#include <iostream>
using namespace std;
long long val[100010];
long long ans[100010];
long long total;
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", val + i);
    }

    val[0] = val[n + 1] = 9223372036854775807LL;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (val[i] > val[i - 1])
        {
            ans[i] = max(ans[i], ans[i - 1] + 1);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (val[i] > val[i + 1])
        {
            ans[i] = max(ans[i], ans[i + 1] + 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        total += ans[i];
    }
    printf("%lld\n", total);
    return 0;
}