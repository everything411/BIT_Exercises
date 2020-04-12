#include <stdio.h>
int main(int argc, char const *argv[])
{
    long long a, b, c;
    while (scanf("%lld%lld%lld", &a, &b, &c) != EOF)
        printf("%lld %lld\n", a + b + c, (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
    return 0;
}
