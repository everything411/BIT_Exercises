#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    long long ans = 0;
    long long num[3];
    cin >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);
    if (num[2] >= 2 * (num[0] + num[1]))
    {
        ans = num[0] + num[1];
    }
    else
    {
        ans = (num[0] + num[1] + num[2]) / 3;
    }

    printf("%lld\n", ans);
    return 0;
}
