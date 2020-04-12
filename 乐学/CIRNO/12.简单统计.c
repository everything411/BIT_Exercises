#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int number;
    int count;
} number_data_t;

int cmp(const void *i, const void *j)
{
    return *(const int *)i > *(const int *)j ? 1 : -1;
}
int main(int argc, char const *argv[])
{
    int case_count;
    int number_count;
    int count;
    int diff_number_count;
    int data[1000];
    number_data_t appear_time_count[1000];
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        diff_number_count = 0;
        count = 1;
        scanf("%d", &number_count);
        for (int i = 0; i < number_count; i++)
            scanf("%d", data + i);
        qsort(data, number_count, sizeof(int), cmp);
        for (int i = 1; i < number_count; i++)
            if (data[i - 1] == data[i])
                count++;
            else
            {
                appear_time_count[diff_number_count].number = data[i - 1];
                appear_time_count[diff_number_count++].count = count;
                count = 1;
            }
        appear_time_count[diff_number_count].number = data[number_count - 1];
        appear_time_count[diff_number_count++].count = count;
        printf("%d\n", diff_number_count);
        for (int i = 0; i < diff_number_count; i++)
            printf("%d %d\n", appear_time_count[i].number, appear_time_count[i].count);
    }
    return 0;
}
