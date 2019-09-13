#include <stdio.h>
#include <stdlib.h>
int compare(const void *i, const void *j);
int main(int argc, char const *argv[])
{
    long long ans = 0;
    int n;
    scanf("%d", &n);
    long long *nums = malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &nums[i]);
        ans += nums[i];
    }
    qsort(nums, n, sizeof(long long), compare);
    if (!(ans & 1))
        for (int i = 0; i < n; i++)
            if (nums[i] & 1)
            {
                ans -= nums[i];
                break;
            }
    if (!(ans & 1))
        ans = -1;
    printf("%lld\n", ans);
    free(nums);
    return 0;
}
int compare(const void *i, const void *j)
{
    return *(const long long *)i > *(const long long *)j ? 1 : -1;
}