#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> hashset;
int main(void)
{
    long long n, m;
    string str;
    scanf("%lld%lld", &n, &m);
    cin >> str;
    long long ans = (n - m + 1) * (n - m + 2) / 2;
    long long not_ok = 0;
    // long long val;
    for (int i = m; i <= min(n, 16LL); i++)
    {
        //hashset.clear();
        for (int j = 0; i + j < n + 1; j++)
        {
            if (hashset.find(str.substr(j, i)) == hashset.end())
            {
                hashset.insert(str.substr(j, i));
            }
            else
            {
                not_ok++;
            }
        }
    }
    printf("%lld\n", ans - not_ok);
    return 0;
}