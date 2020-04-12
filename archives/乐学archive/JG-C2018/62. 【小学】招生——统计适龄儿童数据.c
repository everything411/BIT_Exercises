#include <stdio.h>
#include <stdlib.h>
#define CHILDREN_COUNT 180
int id_cmp(const void *, const void *);
typedef struct child
{
    int id;
    int year;
    int month;
    int day;
    char sex;
    char name[10];
} child_t;

int main(int argc, char const *argv[])
{
    child_t child[CHILDREN_COUNT];
    child_t *ptr_child[CHILDREN_COUNT];
    int count = 0;
    for (int i = 0; i < CHILDREN_COUNT; i++)
    {
        scanf("%d,%d-%d-%d,%c,%s",
              &child[i].id, &child[i].year, &child[i].month, &child[i].day,
              &child[i].sex, child[i].name);
        fprintf(stderr, "child %d read successfully\n", i);
        if ((child[i].year < 2013) || (child[i].year == 2013 && child[i].month < 9))
            ptr_child[count++] = child + i;
    }
    qsort(ptr_child, count, sizeof(child_t *), id_cmp);
    printf(" BH   BirthDay  Name  Sex\n"
           "-------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%04d %04d-%02d-%02d %-6s %c\n",
               ptr_child[i]->id, ptr_child[i]->year, ptr_child[i]->month, ptr_child[i]->day,
               ptr_child[i]->name, ptr_child[i]->sex);
    }
    return 0;
}
int id_cmp(const void *data_1, const void *data_2)
{
    return (*(child_t **)data_1)->id > (*(child_t **)data_2)->id ? 1 : -1;
}