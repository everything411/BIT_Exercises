#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    long long n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans += n / i * i;
    }
    cout << ans << endl;
    return 0;
}
