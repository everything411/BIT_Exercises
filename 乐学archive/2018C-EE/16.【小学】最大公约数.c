#include<stdio.h>
long long gcd(long long a, long long b)
{
    long long c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main(int argc, char const *argv[])
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("GCD(%d,%d)=%lld\n", x, y, gcd(x, y));
    return 0;
}
