#include <stdio.h>
int main(void)
{
    int y, m, d, ans;
    int day_max[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d%d", &y, &m, &d);
    if (!(y % 100 ? y % 4 : y % 400))
        day_max[1]++;
    if (m > 12 || m < 1)
    {
        puts("month is error.");
        return 1;
    }
    if (d < 1 || d > day_max[m - 1])
    {
        puts("day is error.");
        return 1;
    }
    for (int i = 0; i < m - 1; i++)
        d += day_max[i];
    if (m > 2 && !(y % 100 ? y % 4 : y % 400))
        d++;
    y--;
    ans = (y * 365 + y / 4 - y / 100 + y / 400 + d) % 7;
    printf("%d\n", ans);
    return 0;
}