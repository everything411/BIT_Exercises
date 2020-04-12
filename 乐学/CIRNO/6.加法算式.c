#include <stdio.h>
#include <string.h>
#define LEN 128
void stsrt(char *strings[], int num);
int main(void)
{
    char origin[LEN];
    char *head_pos[LEN];
    char *temp_pos;
    int i;
    head_pos[0] = origin;
    fgets(origin, 128, stdin);
    *strchr(origin, '\n') = 0;
    for (i = 0; (temp_pos = strchr(head_pos[i], '+')) != 0; i++)
    {
        *temp_pos = 0;
        head_pos[i + 1] = temp_pos + 1;
    }
    stsrt(head_pos, i + 1);
    for (int j = 0; j <= i; j++)
    {
        printf("%s", head_pos[j]);
        if (j != i)
            putchar('+');
    }

    putchar('\n');
    return 0;
}
void stsrt(char *strings[], int num)
{
    char *temp;
    int top, seek;
    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}