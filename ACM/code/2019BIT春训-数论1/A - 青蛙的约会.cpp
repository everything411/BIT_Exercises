#include <iostream>
using namespace std;
int main(void)
{
    long long x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    long long ans;
    ans = abs(x - y) % abs(m - n);
    return 0;
}