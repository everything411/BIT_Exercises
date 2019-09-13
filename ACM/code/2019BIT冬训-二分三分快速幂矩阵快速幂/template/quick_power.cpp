#define MOD 998244353
long long quickpow(long long base, long long power)
{
    long long ans = 1;
    while (power)
    {
        if (power & 1)
            ans *= base;
        base *= base;
        power >>= 1;
    }
    return ans;
}
long long quick_power_mod(long long base, long long power)
{
    long long ans = 1;
    while (power)
    {
        if (power & 1)
            ans = ans * base % MOD;
        base = base * base % MOD;
        power >>= 1;
    }
    return ans;
}