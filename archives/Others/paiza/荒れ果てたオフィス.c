#include <stdio.h>
int main(void)
{
    int count;
    int rank;
    char str[100];

    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%s%d", str, &rank);
        if (rank == 3)
        {
            puts(str);
        }
    }
    return 0;
}