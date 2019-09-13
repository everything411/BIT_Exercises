#include <stdio.h>
int main(int argc, char const *argv[])
{
    int start, i, j;
    scanf("%d", &start);
    if (start == 1)
    {
        puts(" 1");
        return 0;
    }
    for (i = 0; i < start * 2 - 2; i++)
        putchar(' ');
    printf("%2d\n", 1);
    for (i = 1; i < start; i++)
    {
        for (int j = 1; j < (start - i) * 2 - 1; j++)
            putchar(' ');
        for (j = 1; j <= i; j++)
            printf("%2d", j);
        for (; j >= 1; j--)
            printf("%2d", j);
        putchar('\n');
    }
    return 0;
}
