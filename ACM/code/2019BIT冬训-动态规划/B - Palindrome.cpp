#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    short dp[1010][1010] = {0};
    int len;
    char a[1010], b[1010];
    cin >> len >> a;
    reverse_copy(a, a + len, b);
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            if (i <= len && j <= len && a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    cout << dp[len][len] << endl;

    return 0;
}