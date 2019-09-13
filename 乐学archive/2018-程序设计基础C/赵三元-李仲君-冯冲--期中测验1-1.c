/*
Compile with gcc 4.8
*/
#include <stdio.h>
int isPrime(int x)
{
    int div;       // potential divisors
    _Bool isPrime; // prime flag
    for (div = 2, isPrime = 1; (div * div) <= x; div++)
        if (x % div == 0)
            isPrime = 0; // number  is not prime
    return isPrime;
}

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    puts((isPrime(num) && num > 1) ? "Yes" : "No");
    return 0;
}
