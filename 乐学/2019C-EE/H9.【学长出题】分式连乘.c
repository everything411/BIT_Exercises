#include <stdio.h>
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
int a[100];
int b[100];
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", a + i, b + i);
    }
    int g;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g = gcd(a[i], b[j]);
            if (g == 0)
            {
                continue;
            }
            a[i] /= g;
            b[j] /= g;
        }
    }
    int c, d;
    c = d = 1;
    for (int i = 0; i < n; i++)
    {
        c *= a[i];
        d *= b[i];
    }
    if (d == 1)
    {
        printf("%d\n", c);
    }
    else
    {
        printf("%d/%d\n", c, d);
    }
    return 0;
}
