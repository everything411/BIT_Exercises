/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>
char *gets(char *);
struct nn
{
    int no;
    int num;
};

typedef struct nn DATA;

int number(char *, DATA[]);

int main()
{
    DATA b[100];
    char sa[500];
    int i, n;
    gets(sa);
    n = number(sa, b);
    for (i = 0; i < n; i++)
        printf("%d %d\n", b[i].num, b[i].no);
    return 0;
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */
#include <string.h>
#include <stdlib.h>
int number_cmp(const void *data_1, const void *data_2)
{
    int value = (*(DATA **)data_1)->num - (*(DATA **)data_2)->num;
    if (value > 0)
        return 1;
    else if (value == 0)
        return (*(DATA **)data_1)->no - (*(DATA **)data_2)->no;
    else
        return -1;
}
int number(char *str, DATA numbers[])
{
    int num;
    int count = 0;
    //when pos == 1, strchr() returned NULL
    for (char *pos = str; (pos != (char *)1) && sscanf(pos, "%d", &num); pos = strchr(pos, ' ') + 1)
    {
        numbers[count].no = count;
        //here numbers[count].no is used to save the input order of the datas
        numbers[count++].num = num;
    }
    DATA *ptr_numbers[count];
    for (int i = 0; i < count; i++)
        ptr_numbers[i] = numbers + i;
    qsort(ptr_numbers, count, sizeof(DATA *), number_cmp);
    for (int i = 0; i < count; i++)
        ptr_numbers[i]->no = i + 1;
    return count;
}
