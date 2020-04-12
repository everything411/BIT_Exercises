#include <stdio.h>
#include <string.h>
typedef struct person
{
    char name[16];
    int money;
} person_t;
inline int search_name(char *, person_t *, int);
inline void in_money(int, person_t *, int);
inline void out_money(int, person_t *, int);
int main(int argc, char const *argv[])
{
    int person_count;
    char name[16];
    int money_total;
    int out_count, out_each, out_total;
    int person_index;
    scanf("%d", &person_count);
    person_t person_data[person_count];
    memset(person_data, 0, sizeof(person_data));
    for (int i = 0; i < person_count; i++)
        scanf("%s", person_data[i].name);
    for (int i = 0; i < person_count; i++)
    {
        scanf("%s%d%d", name, &money_total, &out_count);
        person_index = search_name(name, person_data, person_count);
        out_each = money_total / (out_count ? out_count : out_count + 1); //avoid div by zero
        out_total = out_each * out_count;
        out_money(person_index, person_data, out_total);
        for (int j = 0; j < out_count; j++)
        {
            scanf("%s", name);
            person_index = search_name(name, person_data, person_count);
            in_money(person_index, person_data, out_each);
        }
    }
    for (int i = 0; i < person_count; i++)
        printf("%s %d\n", person_data[i].name, person_data[i].money);
    return 0;
}
int search_name(char *name, person_t *person_data, int person_count)
{
    fprintf(stderr, "search_name(): %s\n", name);
    for (int i = 0; i < person_count; i++)
        if (!strcmp(name, person_data[i].name))
            return i;
    return -1;
}
void in_money(int index, person_t *person_data, int money)
{
    fprintf(stderr, "in_money(): index %d money %d\n", index, money);
    if (index == -1)
    {
        fputs("Err: Data invalid\n", stderr);
        return;
    }
    person_data[index].money += money;
}
void out_money(int index, person_t *person_data, int money)
{
    fprintf(stderr, "out_money(): index %d money %d\n", index, money);
    if (index == -1)
    {
        fputs("Err: Data invalid\n", stderr);
        return;
    }
    person_data[index].money -= money;
}