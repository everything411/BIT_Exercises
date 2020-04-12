#include <stdio.h>
int main(void)
{
  int y, m, d;
  int day_max[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  scanf("%d%d%d", &y, &m, &d);
  if (!(y % 100 ? y % 4 : y % 400))
    day_max[1]++;
  if (m > 12 || m < 1)
  {
    if (d > 31 || d < 1)
      puts("month and day are wrong.");
    else
      puts("month is wrong.");
    return 1;
  }
  else if (d < 1 || d > day_max[m - 1])
  {
    puts("day is wrong.");
    return 1;
  }
  if (m < 3)
    m += 12, y--;
  printf("%d\n", ((d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) + 1) % 7);
  return 0;
}