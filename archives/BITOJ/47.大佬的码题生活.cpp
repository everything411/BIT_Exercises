// num 0 0 2 4 10 24
// sum 1 1 3 7 17 41
#include <iostream>
#define MOD 1000000007
using namespace std;
long long num[10010];
int main(int argc, char const *argv[])
{
    int t;
    int n;
    scanf("%d", &t);
    num[0] = num[1] = 1;
    for (int i = 2; i < 10010; i++)
    {
        num[i] = (num[i - 1] + num[i - 2]) % MOD;
    }
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%lld\n", num[n - 1]);
    }
    return 0;
}
