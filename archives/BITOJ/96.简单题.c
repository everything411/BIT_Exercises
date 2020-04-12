#include <stdio.h>
long long f(long long n)
{
    if (n < 20180001)
        return n + 2017;
    return 20182017;
}
int main()
{
    long long n;
    while (~scanf("%lld", &n))
        printf("%lld\n", f(n));
    return 0;
}