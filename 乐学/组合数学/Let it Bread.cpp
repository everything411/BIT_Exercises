#include <iostream>
using namespace std;
int power_mod(int base, int power)
{
    int ans = 1;
    while (power)
    {
        if (power & 1)
            ans = ans * base;
        base = base * base;
        power >>= 1;
    }
    return ans;
}
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main(int argc, char const *argv[])
{
    int c, s;
    while (~scanf("%d%d", &c, &s) && c && s)
    {
        long long ans = 0;
        for (int i = 1; i <= s; i++)
        {
            ans += power_mod(c, gcd(s, i));
        }
        if ((s & 1) == 1)
        {
            ans += s * power_mod(c, (s + 1) >> 1);
        }
        else
        {
            ans += (s >> 1) * power_mod(c, (s + 2) >> 1);
            ans += (s >> 1) * power_mod(c, s >> 1);
        }
        printf("%lld\n", ans / 2 / s);
    }
    return 0;
}
