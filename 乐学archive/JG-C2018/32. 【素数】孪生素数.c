/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <math.h>
int main()
{
    int n, m;
    int isPrime(int); // 若是素数函数isPrim返回1，否则返回0

    scanf("%d%d", &n, &m);
    while (n < m - 1)
    {
        if (isPrime(n) && isPrime(n + 2))
        {
            printf("%d,%d\n", n, n + 2);
        }
        n++;
    }
    return 0;
}
/*  PRESET CODE END - NEVER TOUCH CODE ABOVE */
int isPrime(int x)
{
    int div;       // potential divisors
    _Bool isPrime; // prime flag
    for (div = 2, isPrime = 1; (div * div) <= x; div++)
        if (x % div == 0)
            isPrime = 0; // number  is not prime
    return isPrime;
}
