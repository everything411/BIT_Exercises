#include <stdio.h>
#include <stdlib.h>
#define TOO_EASY "This OJ is too easy for PQ Dashen!"
typedef struct problem
{
    int rank;
    int id;
} problem_t;
int cmp(const void *, const void *);
int main(int argc, char const *argv[])
{
    int case_count;
    int problem_count;
    FILE *fp;
#ifndef DEBUG
    char file_name[128];
    scanf("%s", file_name);
    if (!(fp = fopen(file_name, "r")))
    {
        perror(argv[0]);
        return 1;
    }
#else
    fp = stdin;
#endif
    fscanf(fp, "%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        fscanf(fp, "%d", &problem_count);
        problem_t problem_list[problem_count];
        int flag = 0;
        for (int i = 0; i < problem_count; i++)
        {
            fscanf(fp, "%d%d", &problem_list[i].id, &problem_list[i].rank);
            if (problem_list[i].rank >= 100)
                flag = 1;
        }
        qsort(problem_list, problem_count, sizeof(problem_t), cmp);
        for (int i = 0; i < problem_count; i++)
            if (problem_list[i].rank >= 100)
                printf("%d\n", problem_list[i].id);
        if (!flag)
            puts(TOO_EASY);
        if (i != case_count - 1)
            putchar('\n');
    }

    return 0;
}
int cmp(const void *i, const void *j)
{
    if (((const problem_t *)i)->rank < ((const problem_t *)j)->rank)
        return 1;
    else if (((const problem_t *)i)->rank > ((const problem_t *)j)->rank)
        return -1;
    else
        return ((const problem_t *)i)->id > ((const problem_t *)j)->id ? 1 : -1;
}