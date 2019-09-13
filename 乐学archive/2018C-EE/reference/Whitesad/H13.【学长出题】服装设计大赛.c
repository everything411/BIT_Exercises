//Written by Whitesad originally
//Modified by everything411
/*
这是一个题面很长的题……
所以大概能劝退一拨人，
但是算法（其实也就只是弱化的思维算法）很简单
所以我就没有做完（手动doge）
主要注意两点：
1.并没有什么所谓的子串，实际上就是对字符进行处理
2.最后分情况能否加到字符串长，或者不能。对于能的又要分奇偶性讨论
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct clothes
{
    int color[52];
    int color_num;
    int length;
} player_t;
int ch_to_num(char);
int cmp(const void *p1, const void *p2);
void generate_score(player_t *pc, int step);
char *get_winner(player_t *pc);
player_t player[3];

int main()
{
    memset(&player[0], 0, 3 * sizeof(player_t));
    int step;
    scanf("%d", &step);
    char ch = getchar();
    int count = 0;
    int i = 0;
    while (1)
    {
        ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            player[i].length = count;
            count = 0;
            i++;
            if (ch == EOF)
                break;
            else
                continue;
        }
        count++;
        player[i].color[ch_to_num(ch)]++;
    } //读取部分
    for (int i = 0; i < 3; i++)
    {
        qsort(player[i].color, 52, sizeof(int), cmp); //对元素多少进行排序
        generate_score(&player[i], step);
    }

    puts(get_winner(player));
    return 0;
}

int ch_to_num(char ch)
{
    if (islower(ch))
        return ch - 'a';
    else
        return ch - 'A' + 26;
}
int cmp(const void *p1, const void *p2)
{
    return *(int *)p2 - *(int *)p1;
}
void generate_score(player_t *pc, int step)
{
    if (pc->color[0] + step <= pc->length)
        pc->color_num = pc->color[0] + step;
    else if (pc->color[1] == 0 && step == 1)
        pc->color_num = pc->length - 1;
    else
        pc->color_num = pc->length;
}
char *get_winner(player_t *pc)
{
    int score[3];
    for (int i = 0; i < 3; i++)
        score[i] = pc[i].color_num;
    if (score[0] > score[1] && score[0] > score[2])
        return "Beibei";
    if (score[1] > score[0] && score[1] > score[2])
        return "Lili";
    if (score[2] > score[0] && score[2] > score[1])
        return "Gonggong";
    return "Excellent";
}