#include <stdio.h>
typedef long long ll;
ll GCD(ll, ll);
int main(int argc, char const *argv[])
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", GCD(a, b));
    return 0;
}
ll GCD(ll n, ll m)
{
    if (m <= n && n % m == 0)
        return m;
    if (n < m)
        return GCD(m, n);
    return GCD(m, n % m);
}