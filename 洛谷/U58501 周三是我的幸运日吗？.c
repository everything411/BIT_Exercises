#include <stdio.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    struct tm start = {0};
    struct tm date = {0};
    int year, month, day, h_day, h_month;
    scanf("%d%d%d%d%d", &year, &month, &day, &h_month, &h_day);
    start.tm_year = year - 1900;
    start.tm_mon = month - 1;
    start.tm_mday = day;
    date.tm_year = start.tm_year;
    date.tm_mon = h_month - 1;
    date.tm_mday = h_day;
    time_t start_unix = mktime(&start);
    time_t date_unix = mktime(&date);
    if ((date_unix >= start_unix && date.tm_wday == 3) || date.tm_wday == 0 || date.tm_wday == 6)
        puts("yes");
    else
        puts("no");
    return 0;
}
