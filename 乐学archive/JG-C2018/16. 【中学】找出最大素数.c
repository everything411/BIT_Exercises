// divisors.c -- nested ifs display divisors of a number
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    unsigned long num; // number to be checked
    unsigned long div; // potential divisors
    bool isPrime;      // prime flag
    unsigned long max_Prime = 2;
    scanf("%lu", &num);
    for (unsigned long i = 3; i <= num; i++)
    {
        for (div = 2, isPrime = true; (div * div) <= i; div++)
        {
            if (i % div == 0)
            {
                isPrime = false; // number is not prime
            }
        }
        if (isPrime)
            max_Prime = i;
    }
    printf("The max prime number is %lu.\n", max_Prime);
    return 0;
}