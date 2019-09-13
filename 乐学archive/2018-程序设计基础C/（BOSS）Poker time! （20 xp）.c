#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#define __DEBUG
int is_valid(char *);
void swap(char *, char *);
int is_poker1_bigger(const char *, const char *);
int main(int argc, char const *argv[])
{
    char PokerA[3][4], PokerB[3][4];
    char winner = 'X';
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
    for (int i = 0; i < 3; i++)
        if (is_poker1_bigger(PokerA[i], PokerB[i]))
        {
            winner = 'A';
            break;
        }

    for (int i = 0; i < 3; i++)
        if (is_poker1_bigger(PokerB[i], PokerA[i]))
        {
            winner = 'B';
            break;
        }

    printf("Winner is %c!\nA: %s %s %s\nB: %s %s %s\n", winner, PokerA[0], PokerA[1], PokerA[2], PokerB[0], PokerB[1], PokerB[2]);
    return 0;
}
void swap(char *s1, char *s2)
{
    char temp[4];
    strcpy(temp, s2);
    strcpy(s2, s1);
    strcpy(s1, temp);
}
int is_valid(char *poker)
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
    switch (*poker1)
    {
    case 'H':
        switch (*poker2)
        {
        case 'S':
        case 'D':
        case 'C':
            return 1;
        }
        break;
    case 'S':
        switch (*poker2)
        {
        case 'H':
            return 0;
        case 'D':
        case 'C':
            return 1;
        }
        break;
    case 'D':
        switch (*poker2)
        {
        case 'H':
        case 'S':
            return 0;
        case 'C':
            return 1;
        }
        break;
    case 'C':
        switch (*poker2)
        {
        case 'H':
        case 'S':
        case 'D':
            return 0;
        }
        break;
    }
    if (isdigit(poker1[1]) && !isdigit(poker2[1]))
        return 0;
    if (!isdigit(poker1[1]) && isdigit(poker2[1]))
        return 1;

    if (!isdigit(poker1[1]) && !isdigit(poker2[1]))
    {
        switch (poker1[1])
        {
        case 'J':
            return 0;
            break;
        case 'Q':
            switch (poker2[1])
            {
            case 'A':
            case 'K':
            case 'Q':
                return 0;
            case 'J':
                return 1;
            }
            break;
        case 'K':
            switch (poker2[1])
            {
            case 'A':
            case 'K':
                return 0;
            case 'Q':
            case 'J':
                return 1;
            }
            break;
        case 'A':
            switch (poker2[1])
            {
            case 'A':
                return 0;
            case 'K':
            case 'Q':
            case 'J':
                return 1;
            }
            break;
        }
    }
    if (strtol(poker1 + 1, NULL, 10) > strtol(poker1 + 1, NULL, 10))
        return 1;
    else
        return 0;
}