#include <stdio.h>
#define IS_LEAP(YEAR) (!((YEAR) % 100 ? (YEAR) % 4 : (YEAR) % 400))
#define IS_INVALID(YEAR, MONTH, DAY) ((MONTH) > 12 || (MONTH) < 1) || ((DAY) < 1 || (DAY) > DAY_TAB[IS_LEAP((YEAR))][(MONTH)-1])
#define IS_OUT_OF_RANGE(YEAR) ((YEAR) < 2017 || ((YEAR) > 2018))
const int DAY_TAB[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
const int first_target_day[6] = {0, 2, 3, 4, 5, 6};
int main(void)
{
    int year, month, day, target;
    int y, m, d;
    int day_count = 0;
    int count = 0;
    scanf("%d-%d-%d%d", &year, &month, &day, &target);
    printf("[2017-01-01~%d-%02d-%02d,%d]\n", year, month, day, target);
    if (IS_INVALID(year, month, day) || IS_OUT_OF_RANGE(year))
    {
        puts("ERROR!");
        return 1;
    }
    y = 2017;
    m = 1;
    d = first_target_day[target];
    if (year == 2017 && month == 1 && day <= d)
    {
        if (day == d)
        {
            printf("001 2017-01-%02d\n", d);
            return 0;
        }
        else
        {
            printf("NO DATE FOUND!\n");
            return 1;
        }
    }
    while (d != day || m != month || y != year)
    {
        if (day_count++ % 7 == 0)
        {
            printf("%03d %04d-%02d-%02d\n", ++count, y, m, d);
        }
        d++;
        if (d > DAY_TAB[IS_LEAP(y)][m - 1])
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
    //check if the end date is ok?
    if (day_count++ % 7 == 0)
    {
        printf("%03d %04d-%02d-%02d\n", ++count, y, m, d);
    }
    return 0;
}