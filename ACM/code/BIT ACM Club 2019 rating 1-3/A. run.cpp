#include <iostream>
#define WALK 0
#define RUN 1
#define MOD 1000000007
using namespace std;
int dp[100100][2];
int ans[100100];
int main(int argc, char const *argv[])
{
    int run_speed, query_count;
    scanf("%d%d", &query_count, &run_speed);
    ans[1] = dp[1][WALK] = 1;
    for (int i = 2; i < 100100; i++)
    {
        dp[i][WALK] = (dp[i - 1][WALK] + dp[i - 1][RUN]) % MOD;
        if (i > run_speed)
        {
            dp[i][RUN] = dp[i - run_speed][WALK];
        }
        ans[i] = (ans[i - 1] + dp[i][RUN] + dp[i][WALK]) % MOD;
    }
    int start, end;
    int query_ans;
    for (int i = 0; i < query_count; i++)
    {
        scanf("%d%d", &start, &end);
        query_ans = ans[end + 1] - ans[start];
        query_ans = (query_ans + MOD) % MOD;
        printf("%d\n", query_ans);
    }
    return 0;
}
