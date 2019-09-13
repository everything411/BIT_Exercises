#include <stdio.h>
int main(int argc, char const *argv[])
{
    unsigned long long ans;
    unsigned long long tmp;
    scanf("%*d%llu", &ans);
    while (~scanf("%llu", &tmp))
        ans ^= tmp;
    printf("%llu\n", ans);
    return 0;
}
