#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct water
{
    char count[10010];
    char id[32];
} water_t;
int water_cmp(const void *, const void *);
int main(int argc, char const *argv[])
{
    int count;
    scanf("%d", &count);
    water_t *water_data = (water_t *)calloc(count, sizeof(water_t));
    water_t *water_ptr[count];
    for (int i = 0; i < count; i++)
    {
        water_ptr[i] = water_data + i;
        scanf("%s%s", water_data[i].id, water_data[i].count);
    }
    qsort(water_ptr, count, sizeof(water_t *), water_cmp);
    for (int i = 0; i < count; i++)
        puts(water_ptr[i]->id);
    free(water_data);
    return 0;
}
int water_cmp(const void *data_1, const void *data_2)
{
    char *water_count_1 = (*(water_t **)data_1)->count;
    char *water_count_2 = (*(water_t **)data_2)->count;
    int len_1 = strlen(water_count_1);
    int len_2 = strlen(water_count_2);
    if (len_1 > len_2)
        return -1;
    else if (len_1 < len_2)
        return 1;
    else
        for (int i = 0; i < len_1; i++)
            if (water_count_1[i] < water_count_2[i])
                return 1;
            else if (water_count_1[i] > water_count_2[i])
                return -1;
    return strcmp((*(water_t **)data_1)->id, (*(water_t **)data_2)->id);
}