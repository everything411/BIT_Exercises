#include <stdio.h>
int main(int argc, char const *argv[])
{
    int count;
    long long value;
    long long ans = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%lld", &value);
        ans |= value;
    }
    printf("%lld\n", ans);
    return 0;
}
