#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
typedef struct
{
    unsigned int id;
    char name[8];
    char sex;
    unsigned char score1;
    unsigned char score2;
    unsigned char score3;
} player_t;
int player_cmp(const void *, const void *);
int main(int argc, char const *argv[])
{
    char file_name[32];
    struct stat file_stat;
    scanf("%s", file_name);
    int fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        perror(argv[0]);
        return 1;
    }
    else
        fprintf(stderr, "%s opened at fd %d\n", file_name, fd);
    fstat(fd, &file_stat);
    int count = file_stat.st_size / 0x10;
    player_t *players = (player_t *)malloc(file_stat.st_size);
    read(fd, players, file_stat.st_size);
    player_t *player_top[count];
    /*
    player_t *player_top[99];
    for (int i = 0; i < count; i++)
    {
        player_top[i % 99] = players + i;
    }
    */
    for (int i = 0; i < count; i++)
    {
        player_top[i] = players + i;
    }
    qsort(player_top, count, sizeof(player_t *), player_cmp);
    printf("+-----------------------------------------------------+\n"
           "|                   TOP 99 of %-24d|\n"
           "+-----+--------+----------+---+-----+-----+-----+-----+\n"
           "| TOP |   ID   |   Name   |Sex| SUM | KM1 | KM2 | KM3 |\n"
           "+-----+--------+----------+---+-----+-----+-----+-----+\n",
           count);

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("| %2d  | %06d | %.8s | %c | %3d | %3d | %3d | %3d |\n",
                   i * 5 + j + 1, player_top[i * 5 + j]->id, player_top[i * 5 + j]->name, player_top[i * 5 + j]->sex,
                   player_top[i * 5 + j]->score1 + player_top[i * 5 + j]->score2 + player_top[i * 5 + j]->score3,
                   player_top[i * 5 + j]->score1, player_top[i * 5 + j]->score2, player_top[i * 5 + j]->score3);
        }
        puts("+-----+--------+----------+---+-----+-----+-----+-----+");
    }
    for (int j = 0; j < 4; j++)
    {
        printf("| %2d  | %06d | %.8s | %c | %3d | %3d | %3d | %3d |\n",
               96 + j, player_top[95 + j]->id, player_top[95 + j]->name, player_top[95 + j]->sex,
               player_top[95 + j]->score1 + player_top[95 + j]->score2 + player_top[95 + j]->score3,
               player_top[95 + j]->score1, player_top[95 + j]->score2, player_top[95 + j]->score3);
    }
    puts("+-----+--------+----------+---+-----+-----+-----+-----+");
    close(fd);
    return 0;
}
int player_cmp(const void *data_1, const void *data_2)
{
    int ans = -((*(player_t **)data_1)->score1 + (*(player_t **)data_1)->score2 + (*(player_t **)data_1)->score3 - (*(player_t **)data_2)->score1 - (*(player_t **)data_2)->score2 - (*(player_t **)data_2)->score3);

    if (ans > 0)
    {
        return 1;
    }
    else if (ans == 0)
    {
        return (*(player_t **)data_1)->id - (*(player_t **)data_2)->id;
    }
    else
    {
        return -1;
    }
}