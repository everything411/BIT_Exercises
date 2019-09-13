/* sort_str.c -- reads in strings and sorts them */
#include <stdio.h>
#include <string.h>
void stsrt(char *strings[], int num); /* string-sort function */
int main(void)
{
    char str[5][256];
    char *ptstr[5];
    scanf("%s%s%s%s%s", ptstr[0] = str[0], ptstr[1] = str[1], ptstr[2] = str[2], ptstr[3] = str[3], ptstr[4] = str[4]);
    stsrt(ptstr, 5); /* string sorter              */
    for (int k = 0; k < 5; k++)
        puts(ptstr[k]); /* sorted pointers            */
    return 0;
}

void stsrt(char *strings[], int num)
{
    char *temp;
    int top, seek;
    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top], strings[seek]) < 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}