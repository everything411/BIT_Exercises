#include <stdio.h>
typedef long long ll;
ll GCD(ll n, ll m)
{
    if (m <= n && n % m == 0)
        return m;
    if (n < m)
        return GCD(m, n);
    return GCD(m, n % m);
}
int main(int argc, char const *argv[])
{
    int case_count;
    ll num1, num2;
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        scanf("%lld%lld", &num1, &num2);
        printf("%lld\n", num1 * num2 / GCD(num1, num2));
    }
    return 0;
}
