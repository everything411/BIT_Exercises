// divisors.c -- nested ifs display divisors of a number
#include <stdio.h>
int main(void)
{
    int num;      // number to be checked
    int div;      // potential divisors
    _Bool isPrime; // prime flag
    int primes[1024] = {0};
    int count = 0;
    scanf("%d", &num);
    for (int i = 3; i <= num; i += 2)
    {
        for (div = 2, isPrime = 1; (div * div) <= i; div++)
            if (i % div == 0)
                isPrime = 0;
        if (isPrime)
            primes[count++] = i;
    }
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            if (num == primes[i] + primes[j])
            {
                printf("%d=%d+%d\n", num, primes[i], primes[j]);
                return 0;
            }
    return 0;
}