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

int count(int n, int m)
{
    if (n < 1 || m < 1)
        return 0; //( 当 n < 1 或 m < 1 时 )
    if (n == 1 || m == 1)
        return 1; //( 当 n = 1 或 m = 1 时 )
    if (n < m)
        return count(n, n); //( 当 n < m 时 )
    if (n == m)
        return count(n, m - 1) + 1;           //( 当 n=m 时 )
    return count(n - m, m) + count(n, m - 1); //( 其他情况 )
}