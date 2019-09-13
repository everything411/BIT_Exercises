#include <stdio.h>
#define MAX_N 100001
int array[MAX_N];
int main(int argc, char const *argv[])
{
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < MAX_N; i++)
        array[i] = i + 1;
    for (int i = n - 1; i >= 0; i--)
        if (array[i] && !(array[i] & 1))
            array[i / 2] = 0;
    for (int i = 0; i < n; i++)
        ans += array[i];
    printf("%lld\n", ans);
    return 0;
}
