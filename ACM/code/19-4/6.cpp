#include <iostream>
using namespace std;
long long num[100000];
long long lowbit(long long x)
{
    return x & (-x);
}
int main(void)
{
    int T;
    int n;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &num);
        }
    }
    return 0;
}