/*
Compile with gcc 4.8
*/
#include <stdio.h>
#include <math.h>
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
    double ans = pow(num, 0.2);
    num = ans;
    puts((isPrime(num) && num > 1 && fabs(ans - num) < 0.000001) ? "Yes" : "No");
    return 0;
}
