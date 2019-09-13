
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

struct coin_t
{
    int value;
    int weight;
};

coin_t coins[500];
int coin_types_count;

int dp[10010];

int main(int argc, char *argv[])
{
    int tests;
    scanf("%d", &tests);
    while (tests--)
    {
        int empty_weight, full_weight;
        scanf("%d%d", &empty_weight, &full_weight);
        int coins_weight = full_weight - empty_weight; /* Weight of all coins. */

        scanf("%d", &coin_types_count);
        for (int i = 0; i < coin_types_count; ++i)
            scanf("%d%d", &coins[i].value, &coins[i].weight);

        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        for (int w = 1; w <= coins_weight; ++w)
        {
            for (int ci = 0; ci < coin_types_count; ++ci)
            {
                int prev_weight = w - coins[ci].weight;
                if (prev_weight < 0)
                    continue;
                if (prev_weight && dp[prev_weight] == 0)
                    continue;

                if (dp[w])
                    dp[w] = min(dp[w], dp[prev_weight] + coins[ci].value);
                else
                    dp[w] = dp[prev_weight] + coins[ci].value;
            }
        }

        if (!dp[coins_weight])
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[coins_weight]);
    }

    return 0;
}
