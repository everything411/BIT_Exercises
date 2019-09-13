#include <stdio.h>
#define IS_LEAP(YEAR) !((YEAR % 100) ? (YEAR % 4) : (YEAR % 400))
const int day_max[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *ban_list[] = {"3 and 8.", "4 and 9.", "5 and 0.", "1 and 6.", "2 and 7."};
int calc_day(int, int, int);
int main(int argc, char const *argv[])
{
    int year, month, day;
    fprintf(stderr, "Warning :If your input isn't a valid date, this program may loop forever\n");
    scanf("%d%d%d", &year, &month, &day);
    int offset = calc_day(year, month, day);
    int ban_offset = offset / (13 * 7);
    if (month < 3)
        month += 12, year--;
    int index = ((day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) + 1) % 7;

    if (index == 0 || index == 6)
        puts("Free.");
    else
        puts(ban_list[(index - ban_offset - 1 + 500000) % 5]); //+500000 to avoid  negative index
    return 0;
}
int calc_day(int target_y, int target_m, int target_d)
{
    int ret_val;
    int year = 2012;
    int month = 4;
    int day = 9;
    for (ret_val = 0; !(year == target_y && month == target_m && day == target_d); ret_val++)
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
    return ret_val;
}