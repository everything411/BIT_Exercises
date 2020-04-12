#include <stdio.h>
long long pow(long long, long long);

int main(int argc, char const *argv[])
{
    long long a, b;
    while (~scanf("%lld%lld", &a, &b))
        printf("%lld\n", pow(a, b));
    return 0;
}

long long pow(long long a, long long b)
{
    if(!b)
        return 1;
    long long ans = pow(a, b >> 1);
    ans *= ans;
    ans %= 1000000007LL;
    if (b & 1)
    {
        ans *= a;
        ans %= 1000000007LL;
    }
    return ans;
}