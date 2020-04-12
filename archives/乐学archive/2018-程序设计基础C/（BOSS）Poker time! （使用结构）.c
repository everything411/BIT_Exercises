#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct poker
{
    char name[8];
    int rank;
} poker_t;
void check_poker(poker_t *);
void calc_rank(poker_t *);
int poker_cmp(const void *, const void *);

char *rank_list[] = {
    "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "CJ", "CQ", "CK", "CA",
    "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "DJ", "DQ", "DK", "DA",
    "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "SJ", "SQ", "SK", "SA",
    "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "HJ", "HQ", "HK", "HA"};
poker_t PokerA[3], PokerB[3];
int main(int argc, char const *argv[])
{

    char winner = 'X';
    scanf("%s%s%s%s%s%s",
          PokerA[0].name, PokerA[1].name, PokerA[2].name,
          PokerB[0].name, PokerB[1].name, PokerB[2].name);
    check_poker(PokerA);
    check_poker(PokerB);
    calc_rank(PokerA);
    calc_rank(PokerB);
    qsort(PokerA, 3, sizeof(poker_t), poker_cmp);
    qsort(PokerB, 3, sizeof(poker_t), poker_cmp);
    for (int i = 0; i < 3; i++)
        if (PokerA[i].rank > PokerB[i].rank)
        {
            winner = 'A';
            break;
        }

    for (int i = 0; i < 3; i++)
        if (PokerB[i].rank > PokerA[i].rank)
        {
            winner = 'B';
            break;
        }
    printf("Winner is %c!\nA: %s %s %s\nB: %s %s %s\n",
           winner, PokerA[0].name, PokerA[1].name, PokerA[2].name,
           PokerB[0].name, PokerB[1].name, PokerB[2].name);
    return 0;
}
void check_poker(poker_t *poker)
{
    int valid = 1;
    for (int i = 0; i < 3; i++)
    {
        if (!(poker[i].name[0] == 'H' || poker[i].name[0] == 'S' || poker[i].name[0] == 'D' || poker[i].name[0] == 'C'))
        {
            valid = 0;
            break;
        }
        if (isdigit(poker[i].name[1]))
        {
            long poker_num = strtol(&poker[i].name[1], NULL, 10);
            if (poker_num < 2 || poker_num > 10)
            {
                valid = 0;
                break;
            }
        }
        else if (!(poker[i].name[1] == 'J' || poker[i].name[1] == 'Q' || poker[i].name[1] == 'K' || poker[i].name[1] == 'A'))
        {
            valid = 0;
            break;
        }
        if (!strcmp(poker[i].name, poker[(i + 1) % 3].name))
        {
            valid = 0;
            break;
        }
    }
    if (!valid)
    {
        puts("Input Error!");
        exit(1);
    }
}
void calc_rank(poker_t *poker)
{

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 52; i++)
        {
            if (!strcmp(poker[j].name, rank_list[i]))
            {
                poker[j].rank = i;
                break;
            }
        }
    }
}
int poker_cmp(const void *data_1, const void *data_2)
{
    return ((const poker_t *)data_1)->rank < ((const poker_t *)data_2)->rank ? 1 : -1;
}