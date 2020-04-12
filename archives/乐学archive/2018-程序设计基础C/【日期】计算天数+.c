/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>

// 声明函数原型
int leap_year(int);
int year_days(int);
int days(int, int, int);

int leap_year(int year) // 判断闰年或平年
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
}

int year_days(int year) // 计算一整年的天数
{
    return leap_year(year) ? 366 : 365;
}

int days(int year, int month, int day) // 计算该天month,day 是本年year的第几天
{
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, i;

    if (leap_year(year) && month > 2)
        day++;

    for (i = 1; i < month; i++)
        day += months[i];

    return day;
}
/*   PRESET CODE END - NEVER TOUCH CODE ABOVE */

int main(int argc, char const *argv[])
{
    int year_1, year_2, month_1, month_2, day_1, day_2;
    int ans = 0;
    scanf("%d%d%d%d%d%d", &year_1, &month_1, &day_1, &year_2, &month_2, &day_2);

    if (year_1 == year_2)
    {
        ans = days(year_2, month_2, day_2) - days(year_1, month_1, day_1);
    }
    else
    {
        ans += (leap_year(year_1) ? 366 : 365) - days(year_1, month_1, day_1) + days(year_2, month_2, day_2);
        for (int i = year_1 + 1; i < year_2; i++)
            ans += leap_year(i) ? 366 : 365;
    }
    printf(ans == 1 ? "%d day\n" : "%d days\n", ans);
    return 0;
}
