#include <stdio.h>
int main(void)
{
    int y;
    int d = 13;
    int count = 0;
    int month[12];
    scanf("%d", &y);
    for (int m = 1; m <= 12; m++)
        month[m - 1] = (((m < 3) ? (((d + 2 * (m + 12) + 3 * (m + 13) / 5 + y - 1 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400) + 1) % 7) : (((d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) + 1) % 7)) == 5) ? count++, 1 : 0;
    if (count == 0)
        printf("There is no Black Fridays in year %d.\n", y);
    else if (count == 1)
        printf("There is 1 Black Friday in year %d.\nIt is:\n", y);
    else
        printf("There are %d Black Fridays in year %d.\nThey are:\n", count, y);
    for (int i = 0; i < 12; i++)
        if (month[i])
            printf("%d/%d/13\n", y, i + 1);
    return 0;
}