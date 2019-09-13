#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int values[110][110];
int dp[110][110];
int main(int argc, char const *argv[])
{
    int height;
    while (~scanf("%d", &height))
    {
        memset(values, 0, sizeof(values));
        for (int i = 0; i < height; i++)
            for (int j = 0; j <= i; j++)
                scanf("%d", &values[i][j]);
        for (int i = 0; i < height; i++)
            dp[height - 1][i] = values[height - 1][i];
        for (int i = height - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + values[i][j];

        printf("%d\n", dp[0][0]);
    }
    return 0;
}
