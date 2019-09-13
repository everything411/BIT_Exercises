#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
void getPrime(vector<int> &prime, int n)
{
    bool *flag = (bool *)calloc(n + 1, sizeof(bool));
    int cnt = 0; // 素数个数
    for (int i = 2; i <= n; ++i)
    {
        if (!flag[i])
        {
            prime.push_back(i);
            cnt++;
        }
        for (int j = 0; j < cnt; ++j)
        {
            if (i * prime[j] > n)
                break;
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main(void)
{
    int l, r;
    int count = 0;
    cin >> l >> r;
    vector<int> prime;
    getPrime(prime, r);
    int index = lower_bound(prime.begin(), prime.end(), l) - prime.begin();
    for (int i = index; i < prime.size(); i++)
    {
        if (prime[i] % 4 == 1)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
