#include <iostream>
#define MOD 998244353
using namespace std;
long long num[1000010];
int main(int argc, char const *argv[])
{
    int n;
    num[0] = num[1] = num[2] = 1;
    for (int i = 3; i < 1000010; i++)
    {
        num[i] = (num[i - 1] + num[i - 2] + num[i - 3]) % MOD;
    }
    for (; ~scanf("%d", &n);)
    {
        printf("%lld\n", num[n - 1]);
    }
    return 0;
}
