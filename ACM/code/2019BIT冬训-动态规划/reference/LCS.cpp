#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    string a, b;
    while (cin >> a >> b)
    {
        short dp[1000][1000] = {0};
        if (a.length() < b.length())
            swap(a, b);
        int la = a.length(), lb = b.length();
        for (int i = 1; i <= la; i++)
        {
            for (int j = 1; j <= lb; j++)
            {
                if (i <= a.length() && j <= b.length() && a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        cout << dp[la][lb] << endl;
    }
    return 0;
}