/**
 * 12 5
5 1 2 3  4 5  6   7 8  9  10 >
2 1 2 3 4 =

2 5 6 7 8 >
1 5 6 =
1 5 6 =*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define TRUE 1
#define ORIGIN 0x3f3f3f3f
#define UNKNOWN 2
#define FALSE 0
using namespace std;
int coins[1000];
int left_coins[500];
int right_coins[500];
char *state_string(int state)
{
    switch (state)
    {
    case TRUE:
        return (char *)"TRUE";
        break;
    case ORIGIN:
        return (char *)"ORIGIN";
        break;
    case UNKNOWN:
        return (char *)"UNKNOWN";
        break;
    case FALSE:
        return (char *)"FALSE";
        break;
    default:
        return (char *)"WRONG STATE";
        break;
    }
}
int main(int argc, char const *argv[])
{
    int coin_count, weighting_count;
    int each_side;
    char op;
    scanf("%d%d", &coin_count, &weighting_count);
    memset(coins, 0x3f, sizeof(coins));
    for (int i = 0; i < weighting_count; i++)
    {
        scanf("%d", &each_side);
        for (int i = 0; i < each_side; i++)
        {
            scanf("%d", &left_coins[i]);
        }
        for (int i = 0; i < each_side; i++)
        {
            scanf("%d", &right_coins[i]);
        }
        scanf(" %c", &op);
        switch (op)
        {
        case '>':
        case '<':
            for (int i = 0; i < each_side; i++)
            {
                if (coins[right_coins[i] - 1] != TRUE)
                {
                    coins[right_coins[i] - 1] = UNKNOWN;
                }
                if (coins[left_coins[i] - 1] != TRUE)
                {
                    coins[left_coins[i] - 1] = UNKNOWN;
                }
            }
            for (int i = 0; i < coin_count; i++)
            {
                if (coins[i] != UNKNOWN)
                {
                    coins[i] = TRUE;
                }
            }
            break;
        case '=':
            for (int i = 0; i < each_side; i++)
            {
                coins[right_coins[i] - 1] = TRUE;
                coins[left_coins[i] - 1] = TRUE;
            }
            break;
        }
    }
    int pos;
    int ans_count = 0;
    for (int i = 0; i < coin_count; i++)

    {
        puts(state_string(coins[i]));
        if (coins[i] == UNKNOWN || coins[i] == ORIGIN)
        {
            pos = i;
            ans_count++;
        }
    }
    if (ans_count == 1)
        printf("%d\n", pos + 1);
    else
        puts("0");
    return 0;
}
