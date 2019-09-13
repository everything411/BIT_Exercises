#include <stdio.h>
#include <math.h>
#define EPS 1e-5
typedef struct player
{
    char name[10];
    int val;
} player_t;

int main(int argc, char const *argv[])
{
    int count;
    int total = 0;
    int curr_index = 0;
    double average;
    double curr_min = 1000.0;
    scanf("%d", &count);
    player_t players[count];
    for (int i = 0; i < count; i++)
    {
        scanf("%s%d", players[i].name, &players[i].val);
        total += players[i].val;
    }
    average = (double)total / count / 2.0;
    for (int i = 0; i < count; i++)
    {
        if (fabs(average - players[i].val) - curr_min < EPS && players[i].val != players[curr_index].val)
        {
            curr_min = fabs(average - players[i].val);
            curr_index = i;
        }
    }
    printf("%d %s\n", total / (count * 2), players[curr_index].name);
    return 0;
}