#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define FLAG (player[0].poker_count == 0 && player[0].poker_count == player[1].poker_count && player[1].poker_count == player[2].poker_count && player[2].poker_count == player[3].poker_count)

typedef struct
{
    int poker_count;
    int heart_count;
    bool C10_flag;
    bool S12_flag;
    bool D11_flag;
    bool has_all_heart_flag;
    int score;
    char poker[16][4];
} player_t;

int main(int argc, char const *argv[])
{
    player_t player[4];
    bool all_heart_flag = 0;
    const int heart_score[] = {-50, -2, -3, -4, -5, -6, -7, -8, -9, -10, -20, -30, -40};
    while (1)
    {
        memset(player, 0, sizeof(player));
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &player[i].poker_count);
            for (int j = 0; j < player[i].poker_count; j++)
            {
                scanf("%s", player[i].poker[j]);
                switch (*player[i].poker[j])
                {
                case 'H':
                    player[i].heart_count++;
                    break;
                case 'S':
                    player[i].S12_flag = 1;
                    break;
                case 'D':
                    player[i].D11_flag = 1;
                    break;
                case 'C':
                    player[i].C10_flag = 1;
                    break;
                default:
                    break;
                }
            }
        }
        if (FLAG)
            break;

        for (int i = 0; i < 4; i++)
        {
            if (player[i].heart_count == 13)
            {
                player[i].has_all_heart_flag = 1;
                all_heart_flag = 1;
                if (player[i].S12_flag && player[i].D11_flag)
                {
                    player[i].score += 500 * (player[i].C10_flag + 1);
                }
                else
                {
                    player[i].score += 200 * (player[i].C10_flag + 1);
                    if (player[i].S12_flag)
                    {
                        player[i].score -= 100 * (player[i].C10_flag + 1);
                    }
                    if (player[i].D11_flag)
                    {
                        player[i].score += 100 * (player[i].C10_flag + 1);
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (player[i].poker[0][0] == 'C' && player[i].poker_count == 1)
            {
                player[i].score = 50;
                continue;
            }

            if (!player[i].has_all_heart_flag)
            {
                if (player[i].S12_flag)
                    player[i].score += -100 * (player[i].C10_flag + 1);
                if (player[i].D11_flag)
                    player[i].score += 100 * (player[i].C10_flag + 1);
                for (int j = 0; j < player[i].poker_count; j++)
                {
                    if (player[i].poker[j][0] == 'H')
                        player[i].score += heart_score[atoi(&player[i].poker[j][1]) - 1] * (player[i].C10_flag + 1);
                }
            }
        }

        //debug
        for (int i = 0; i < 4; i++)
        {
            fprintf(stderr, "\x1b[33m========DEBUG========\n");
            fprintf(stderr, "player[%d]\n", i);
            fprintf(stderr, "poker_count == %d;\n"
                            "heart_count == %d;\n"
                            "C10_flag == %d;\n"
                            "S12_flag == %d;\n"
                            "D11_flag == %d;\n"
                            "has_all_heart_flag == %d;\n"
                            "score == %d;\n",
                    player[i].poker_count, player[i].heart_count, player[i].C10_flag, player[i].S12_flag, player[i].D11_flag, player[i].has_all_heart_flag, player[i].score);
            fprintf(stderr, "========DEBUG========\n\x1b[0m");
        }
        //debug

        for (int i = 0; i < 4; i++)
        {
            printf(!player[i].score ? "0" : "%+d", player[i].score);
            putchar(i != 3 ? ' ' : '\n');
        }
    }
    return 0;
}
