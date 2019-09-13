/*
    n! * 2^n * an = 1 * 3 * 5 * 7 * ... * (2n - 1) * w % 998244353
*/
#include <iostream>
#define MOD 998244353
long long ans[1000010];
void init(void)
{
    ans[1] = 1;
    for (int i = 2; i < 1000010; i++)
    {
        ans[i] = (ans[i - 1] * ((i * 2 - 1) % MOD)) % MOD;
    }
}
int main(void)
{
    init();
    int w, q;
    int n;
    scanf("%d%d", &w, &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &n);
        printf("%lld\n", ans[n] * w % MOD);
    }

    return 0;
}