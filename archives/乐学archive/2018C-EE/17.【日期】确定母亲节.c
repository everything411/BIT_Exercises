#include <stdio.h>
int main(void)
{
    int day[7] = {7, 1, 2, 3, 4, 5, 6};
    int y;
    int m = 5;
    int d = 1;
    scanf("%d", &y);
    printf("%d\n", 14 - day[(d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7]);
    return 0;
}