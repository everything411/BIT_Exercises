#include <stdio.h>
#define IS_LEAP(YEAR) !((YEAR % 100) ? (YEAR % 4) : (YEAR % 400))
int main(int argc, char const *argv[])
{
    int year, month, day, offset;
    int day_max[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d%d%d", &year, &month, &day, &offset);
    for (int i = 0; i < offset; i++)
    {
        day++;
        if (day > ((IS_LEAP(year) && month == 2) ? (1 + day_max[month - 1]) : day_max[month - 1]))
        {
            day = 1;
            month++;
        }
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    printf("%d.%d.%d\n", year, month, day);
    return 0;
}
