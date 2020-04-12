#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    int score;
    char id[32];
} student_t;
int student_cmp(const void *, const void *);
int main(int argc, char const *argv[])
{
    int count;
    scanf("%d", &count);
    getchar(); //get the '\n' out of the buffer
    student_t *student_data = (student_t *)calloc(count, sizeof(student_t));
    student_t *student_ptr[count];
    for (int i = 0; i < count; i++)
    {
        student_ptr[i] = student_data + i;
        scanf("%[^,],%d", student_data[i].id, &student_data[i].score);
        getchar(); //get the '\n' out of the buffer
    }
    qsort(student_ptr, count, sizeof(student_t *), student_cmp);
    for (int i = 0; i < count; i++)
        printf("%s,%d\n", student_ptr[i]->id, student_ptr[i]->score);
    free(student_data);
    return 0;
}
int student_cmp(const void *data_1, const void *data_2)
{
    int score_1 = (*(student_t **)data_1)->score;
    int score_2 = (*(student_t **)data_2)->score;
    if (score_1 >= score_2)
        return -1;
    else
        return 1;
}