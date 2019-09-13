#include <stdio.h>
typedef struct team
{
    int score;
    int lost;
    int win;
    int draw;
} team_t;
team_t teams[102];
int main(void)
{
    int count;
    char str[110];
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%s", str);
        for (int j = 0; str[j]; j++)
        {
            switch (str[j])
            {
            case 'W':
                teams[i].win++;
                teams[i].score += 2;
                break;
            case 'D':
                teams[i].draw++;
                teams[i].score++;
                break;
            case 'L':
                teams[i].lost++;
                break;
            default:
                break;
            }
        }
    }
    int index = 0;
    int max = -10000;
    for (int i = 0; i < count; i++)
    {
        if (teams[i].score > max)
        {
            max = teams[i].score;
            index = i;
        }
    }
    printf("%d %d %d %d %d\n", index + 1, teams[index].score, teams[index].win, teams[index].draw, teams[index].lost);
    return 0;
}