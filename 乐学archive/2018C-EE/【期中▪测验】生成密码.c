#include <stdio.h>
int isPrime(int);
int main(int argc, char const *argv[])
{
    int year, month, day;
    int bigger, smaller;
    _Bool bigger_found = 0, smaller_found = 0;
    scanf("%d,%d,%d", &year, &month, &day);
    int sum = year + month + day;
    for (int i = 0; !bigger_found || !smaller_found; i++)
    {
        if (!smaller_found && isPrime(sum - i))
        {
            smaller = sum - i;
            smaller_found = 1;
        }
        if (!bigger_found && isPrime(sum + i))
        {
            bigger = sum + i;
            bigger_found = 1;
        }
    }
    printf("%d%d\n", smaller, bigger);
    return 0;
}
int isPrime(int number)
{
    int div;       // potential divisors
    _Bool isPrime; // prime flag
    for (div = 2, isPrime = 1; (div * div) <= number; div++)
        if (number % div == 0)
            isPrime = 0; // number  is not prime
    return isPrime;
}