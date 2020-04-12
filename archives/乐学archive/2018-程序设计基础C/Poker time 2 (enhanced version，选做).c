#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define __DEBUG
//rank define
#define straight_flush 1000000000
#define three_of_a_kind 100000000
#define straight 10000000
#define one_pair 1000000
#define high_card 100000
#define poker_A 14
#define poker_K 13
#define poker_Q 12
#define poker_J 11
//rank define
int is_valid(const char *);
void swap(char *, char *);
int is_poker1_bigger(const char *, const char *);
int get_rank(const char poker[][4]);
int is_straight_flush(const char poker[][4]);
int is_three_of_a_kind(const char poker[][4]);
int is_straight(const char poker[][4]);
int is_one_pair(const char poker[][4]);
int main(int argc, char const *argv[])
{
    char PokerA[3][4], PokerB[3][4];
    char winner = 0;
    int rankA, rankB;
    scanf("%s%s%s%s%s%s", PokerA[0], PokerA[1], PokerA[2], PokerB[0], PokerB[1], PokerB[2]);
    for (int i = 0; i < 3; i++)
        if (!is_valid(PokerA[i]) || !is_valid(PokerB[i]))
        {
            puts("Input Error!");
            return 0;
        }
    for (int i = 0; i < 3; i++)
        if (!strcmp(PokerA[i], PokerA[(i + 1) % 3]) || !strcmp(PokerB[i], PokerB[(i + 1) % 3]))
        {
            puts("Input Error!");
            return 0;
        }

    for (int i = 0; i < 2; i++)
        for (int j = i + 1; j < 3; j++)
        {
            if (is_poker1_bigger(PokerA[j], PokerA[i]))
                swap(PokerA[j], PokerA[i]);
            if (is_poker1_bigger(PokerB[j], PokerB[i]))
                swap(PokerB[j], PokerB[i]);
        }
    rankA = get_rank(PokerA);
    rankB = get_rank(PokerB);
#ifdef __DEBUG
    printf("rank\nA :%d\tB :%d\n", rankA, rankB);
#endif
    if (rankA > rankB)
    {
        winner = 'A';
    }
    else if (rankA < rankB)
        winner = 'B';
    else if (rankA == rankB && rankA == 0)
    {
        for (int i = 0; i < 3; i++)
            if (is_poker1_bigger(PokerA[i], PokerB[i]))
            {
                winner = 'A';
                goto program_end;
            }

        for (int i = 0; i < 3; i++)
            if (is_poker1_bigger(PokerB[i], PokerA[i]))
            {
                winner = 'B';
                goto program_end;
            }
    }
program_end:
    if (winner)
        printf("Winner is %c!\nA: %s %s %s\nB: %s %s %s\n", winner, PokerA[0], PokerA[1], PokerA[2], PokerB[0], PokerB[1], PokerB[2]);
    else
        printf("Draw!\nA: %s %s %s\nB: %s %s %s\n", PokerA[0], PokerA[1], PokerA[2], PokerB[0], PokerB[1], PokerB[2]);
    return 0;
}
void swap(char *s1, char *s2)
{
    char temp[4];
    strcpy(temp, s2);
    strcpy(s2, s1);
    strcpy(s1, temp);
}
int is_valid(const char *poker)
{
    int valid = 1;
    if (!(*poker == 'H' || *poker == 'S' || *poker == 'D' || *poker == 'C'))
        valid = 0;
    if (isdigit(poker[1]))
    {
        long i = strtol(poker + 1, NULL, 10);
        if (i < 2 || i > 10)
            valid = 0;
    }
    else if (!(poker[1] == 'J' || poker[1] == 'Q' || poker[1] == 'K' || poker[1] == 'A'))
        valid = 0;
    return valid;
}
int is_poker1_bigger(const char *poker1, const char *poker2)
{
    if (isdigit(poker1[1]) && !isdigit(poker2[1]))
        return 0;
    if (!isdigit(poker1[1]) && isdigit(poker2[1]))
        return 1;
    if (isdigit(poker1[1]) && isdigit(poker2[1]))
        if (strtol(poker1 + 1, NULL, 10) > strtol(poker2 + 1, NULL, 10))
            return 1;
        else if (strtol(poker1 + 1, NULL, 10) < strtol(poker2 + 1, NULL, 10))
        {
            return 0;
        }

    if (!isdigit(poker1[1]) && !isdigit(poker2[1]))
        switch (poker1[1])
        {
        case 'A':
            switch (poker2[1])
            {
            case 'K':
            case 'Q':
            case 'J':
                return 1;
            }
            break;
        case 'K':
            switch (poker2[1])
            {
            case 'A':
                return 0;
            case 'Q':
            case 'J':
                return 1;
            }
            break;
        case 'Q':
            switch (poker2[1])
            {
            case 'A':
            case 'K':
                return 0;
            case 'J':
                return 1;
            }
            break;
        case 'J':
            switch (poker2[1])
            {
            case 'A':
            case 'K':
            case 'Q':
                return 0;
            }
            break;
        }
    switch (poker1[0])
    {
    case 'H':
        switch (poker2[0])
        {
        case 'H':
            return 0;
        case 'K':
        case 'Q':
        case 'J':
            return 1;
        }
        break;
    case 'S':
        switch (poker2[0])
        {
        case 'H':
        case 'S':
            return 0;
        case 'D':
        case 'C':
            return 1;
        }
        break;
    case 'D':
        switch (poker2[0])
        {
        case 'H':
        case 'S':
        case 'D':
            return 0;
        case 'C':
            return 1;
        }
        break;
    case 'C':
        return 0;
        break;
    }
}
int get_rank(const char poker[][4])
{
    int rank = 0;
    int ret = 0;
    if ((rank = is_straight_flush(poker)))
        ret = straight_flush + rank;
    else if ((rank = is_three_of_a_kind(poker)))
        ret = three_of_a_kind + rank;
    else if ((rank = is_straight(poker)))
        ret = straight + rank;
    else if ((rank = is_one_pair(poker)))
        ret = one_pair + rank;
    else
        ret = 0;
#ifdef __DEBUG
    printf("get_rank() : rank :%d ret: %d\n", rank, ret);
#endif
    return ret;
}
int is_straight_flush(const char poker[][4])
{
    int rank[3] = {0};
    if ((poker[0][0] == poker[1][0]) && (poker[1][0] == poker[2][0]))
    {
        for (int i = 0; i < 3; i++)
            if (isdigit(poker[i][1]))
                rank[i] = strtol(&poker[i][1], NULL, 10);
            else
                switch (poker[i][1])
                {
                case 'A':
                    rank[i] = poker_A;
                    break;
                case 'K':
                    rank[i] = poker_K;
                    break;
                case 'Q':
                    rank[i] = poker_Q;
                    break;
                case 'J':
                    rank[i] = poker_J;
                    break;
                }
    }
#ifdef __DEBUG
    printf("is_straight_flush() : rank :%d\t%d\t%d\n", rank[0], rank[1], rank[2]);
#endif
    if ((rank[0] - 1 == rank[1]) && (rank[1] - 1 == rank[2]))
        return rank[0];
    else
        return 0;
}
int is_three_of_a_kind(const char poker[][4])
{
    int rank = 0;
    if (poker[0][1] == poker[1][1] && poker[1][1] == poker[2][1])
        if (isdigit(poker[0][1]))
            rank = strtol(&poker[0][1], NULL, 10);
        else
            switch (poker[0][1])
            {
            case 'A':
                rank = poker_A;
                break;
            case 'K':
                rank = poker_K;
                break;
            case 'Q':
                rank = poker_Q;
                break;

            case 'J':
                rank = poker_J;
                break;
            }
    else
        rank = 0;
#ifdef __DEBUG
    printf("is_three_of_a_kind() : rank :%d\n", rank);
#endif
    return rank;
}
int is_straight(const char poker[][4])
{
    int rank[3] = {0};
    for (int i = 0; i < 3; i++)
        if (isdigit(poker[i][1]))
            rank[i] = strtol(&poker[i][1], NULL, 10);
        else
            switch (poker[i][1])
            {
            case 'A':
                rank[i] = poker_A;
                break;
            case 'K':
                rank[i] = poker_K;
                break;
            case 'Q':
                rank[i] = poker_Q;
                break;
            case 'J':
                rank[i] = poker_J;
                break;
            }
#ifdef __DEBUG
    printf("is_straight() : rank :%d\t%d\t%d\n", rank[0], rank[1], rank[2]);
#endif
    if ((rank[0] - 1 == rank[1]) && (rank[1] - 1 == rank[2]))
        return rank[0];
    else
        return 0;
}
int is_one_pair(const char poker[][4])
{
    int rank[3] = {0};
    for (int i = 0; i < 3; i++)
        if (isdigit(poker[i][1]))
            rank[i] = strtol(&poker[i][1], NULL, 10);
        else
            switch (poker[i][1])
            {
            case 'A':
                rank[i] = poker_A;
                break;
            case 'K':
                rank[i] = poker_K;
                break;
            case 'Q':
                rank[i] = poker_Q;
                break;
            case 'J':
                rank[i] = poker_J;
                break;
            }
#ifdef __DEBUG
    printf("is_one_pair() : rank :%d\t%d\t%d\n", rank[0], rank[1], rank[2]);
#endif
    if (rank[0] == rank[1])
        return rank[0];
    else if (rank[1] == rank[2])
        return rank[1];
    else
        return 0;
}