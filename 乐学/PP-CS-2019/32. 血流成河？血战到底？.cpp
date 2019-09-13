#include <iostream>
#define MAXN 410
using namespace std;
int mahjong_table[MAXN];
int mahjong_win[MAXN];
int tmp_table[MAXN];

int ready_hand_count;
int max_mahjong;
int mahjong_count;
bool is_win(void)
{
    bool win_flag;
    for (int i = 1; i <= max_mahjong; i++)
    {
        if (mahjong_table[i] >= 2)
        {
            win_flag = true;
            mahjong_table[i] -= 2;
            for (int i = 1; i <= max_mahjong; i++)
            {
                tmp_table[i] = mahjong_table[i];
            }
            for (int i = 1; i <= max_mahjong; i++)
            {
                tmp_table[i] %= 3;
                if (tmp_table[i] > tmp_table[i + 1] || tmp_table[i] > tmp_table[i + 2])
                {
                    win_flag = false;
                    break;
                }
                tmp_table[i + 1] -= tmp_table[i];
                tmp_table[i + 2] -= tmp_table[i];
            }
            mahjong_table[i] += 2;
            if (win_flag)
            {
                return true;
            }
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int tmp;

    scanf("%d%d", &max_mahjong, &mahjong_count);
    mahjong_count = 3 * mahjong_count + 1;
    for (int i = 0; i < mahjong_count; i++)
    {
        scanf("%d", &tmp);
        mahjong_table[tmp]++;
    }
    for (int i = 1; i <= max_mahjong; i++)
    {
        mahjong_table[i]++;
        if (is_win())
        {
            mahjong_win[ready_hand_count++] = i;
        }
        mahjong_table[i]--;
    }
    if (ready_hand_count == 0)
    {
        puts("NO");
    }
    else
    {
        for (int i = 0; i < ready_hand_count - 1; i++)
        {
            printf("%d ", mahjong_win[i]);
        }
        printf("%d\n", mahjong_win[ready_hand_count - 1]);
    }
    return 0;
}
