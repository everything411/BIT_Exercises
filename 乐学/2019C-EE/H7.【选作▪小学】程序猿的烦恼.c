#include <stdio.h>
int main(int argc, char const *argv[])
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    __uint128_t a, b, c, t; // magic
    a = b = c = t = 1;
    for (int i = 1; i <= x; i++)
    {
        a *= i;
    }
    for (int i = 1; i <= y; i++)
    {
        b *= i;
    }
    for (int i = 1; i <= z; i++)
    {
        c *= i;
    }
    for (int i = 1; i <= x + y + z; i++)
    {
        t *= i;
    }
    printf("%llu\n", t / (a * b * c)); // magic again~
    return 0;
}
