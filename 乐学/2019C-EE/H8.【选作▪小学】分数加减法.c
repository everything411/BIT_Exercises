#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main(int argc, char const *argv[])
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int f = a * d + b * c;
    int g = b * d;
    int h;
    if (f * g >= 0)
    {
        f = abs(f);
        g = abs(g);
        h = gcd(f, g);
        printf("%d/%d", f / h, g / h);
    }
    else
    {
        f = abs(f);
        g = abs(g);
        h = gcd(f, g);
        printf("-%d/%d", f / h, g / h);
    }
    printf("\n");
    return 0;
}
