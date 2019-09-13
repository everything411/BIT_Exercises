#include <iostream>
using namespace std;
int n, v;
int fruit_cnt[3200];
int p, q;
int main(void)
{
    int ans = 0;
    int curr_lim;
    int diff;
    cin >> n >> v;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> q;
        fruit_cnt[p] += q;
    }
    for (int i = 0; i < 3200; i++)
    {
        if (i == 0)
        {
            ans += min(fruit_cnt[0], v);
            fruit_cnt[0] -= min(fruit_cnt[0], v);
        }
        else
        {
            curr_lim = v;
            diff = min(fruit_cnt[i - 1], curr_lim);
            ans += diff;
            curr_lim -= diff;
            diff = min(fruit_cnt[i], curr_lim);
            ans += diff;
            fruit_cnt[i] -= diff;
        }
    }
    cout << ans << endl;
    return 0;
}