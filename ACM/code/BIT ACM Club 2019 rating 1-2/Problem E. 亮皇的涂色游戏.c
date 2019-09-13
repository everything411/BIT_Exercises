#include <stdio.h>
long long quick_power_mod(long long base, long long power, long long mod)
{
    long long ans = 1;
    while (power)
    {
        if (power & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    long long row, col;
    scanf("%lld%lld", &row, &col);
    printf("%lld\n", quick_power_mod(2, row, 1000000007));
    return 0;
}
