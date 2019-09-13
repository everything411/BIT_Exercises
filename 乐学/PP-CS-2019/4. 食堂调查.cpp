#include <iostream>
using namespace std;
int in[1000010];
int out[1000010];
int tmp1, tmp2;
int m;
int ans, n;
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        in[tmp1]++;
        out[tmp2]++;
    }
    for (int i = 0; i < 1000010; i++)
    {
        ans += in[i];
        m = max(m, ans);
        ans -= out[i];
        // if (ans != 0)
        // cout << ans << endl;
    }
    cout << m << endl;
    return 0;
}