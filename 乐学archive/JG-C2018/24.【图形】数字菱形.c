#include <stdio.h>
int main(int argc, char const *argv[])
{
    int start, i, j;
    scanf("%d", &start);
    if (start == 1)
    {
        puts("1 ");
        return 0;
    }
    for (i = 0; i < start * 2 - 2; i++)
        putchar(' ');
    printf("%-2d\n", start);
    for (i = start; i > 1; i--)
    {
        for (int j = 0; j < i * 2 - 4; j++)
            putchar(' ');
        for (j = start; j >= i; j--)
            printf("%-2d", j);
        for (; j <= start; j++)
            printf("%-2d", j);
        putchar('\n');
    }
    for (i = 3; i <= start; i++)
    {
        for (int j = 0; j < i * 2 - 4; j++)
            putchar(' ');
        for (j = start; j >= i; j--)
            printf("%-2d", j);
        for (; j <= start; j++)
            printf("%-2d", j);
        putchar('\n');
    }
    for (i = 0; i < start * 2 - 2; i++)
        putchar(' ');
    printf("%-2d\n", start);
    return 0;
}
