#include <stdio.h>
#define IS_LEAP(YEAR) !((YEAR % 100) ? (YEAR % 4) : (YEAR % 400))
int main(void)
{
    int y, m, d, count;
    int year, month, day;
    int day_max[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d", &y);
    for (y = 1990, m = 1, d = 1, count = 0; ~scanf("%d%d%d", &year, &month, &day); y = 1990, m = 1, d = 1, count = 0)
    {
        while (y != year || m != month || d != day)
        {
            d++;
            count++;
            if (d > ((IS_LEAP(y) && m == 2) ? (1 + day_max[m - 1]) : day_max[m - 1]))
            {
                d = 1;
                m++;
            }
            if (m > 12)
            {
                m = 1;
                y++;
            }
        }
        printf("He was %s on %d.%d.%d\n", ((count % 5) < 3) ? "fishing" : "basking", year, month, day);
    }
    return 0;
}