#include <iostream>
using namespace std;
long long arr[] = {0, 4, 6, 10, 15, 21, 27, 33, 39, 43, 46, 48};
int main(int argc, char const *argv[])
{
    long long n;
    scanf("%lld", &n);
    long long ans = 0;
    if (n < 12)
    {
        for (int i = 1; i <= n; i++)
        {
            ans += arr[i];
        }
    }
    else
    {
        for (int i = 1; i <= 11; i++)
        {
            ans += arr[i];
        }
        ans += 49 * (n - 11);
    }
    printf("%lld\n", ans);
    return 0;
}
