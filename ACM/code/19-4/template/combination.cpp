#define MAXN 2000005
#define MOD 1000000007
long long fac[MAXN];
long long inv[MAXN];
long long pow_mod(long long base, long long power)
{
    long long ret = 1;
    while (power)
    {
        if (power & 1)
            ret = ret * base % MOD;
        base = base * base % MOD;
        power >>= 1;
    }
    return ret;
}
void init(void)
{
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
}
long long C(long long n, long long m)
{
    return fac[n] * pow_mod(fac[m] * fac[n - m] % MOD, MOD - 2) % MOD;
}