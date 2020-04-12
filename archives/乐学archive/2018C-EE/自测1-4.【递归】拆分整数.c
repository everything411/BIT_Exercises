/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>
int main()
{
    int n, count();
    scanf("%d", &n);
    printf("%d\n", count(n, n - 1));
    return 0;
}
   PRESET CODE END - NEVER TOUCH CODE ABOVE */

int count(int m, int n)
{
    if (m < 1 || n < 1)
        return 0;
    if (n == 1 || m == 1)
        return 1;
    if (m > n)
        return count(m, n - 1) + count(m - n, n);
    if (m == n)
        return 1 + count(m, n - 1);
    if (m < n)
        return count(m, m);
}
