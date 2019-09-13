#include <stdio.h>
#include <string.h>
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
    char str[16];
    char temp[8] = {0};
    scanf("%s", &str);
    int len = strlen(str);
    int num;
    for (int i = 0; i < len - 1; i++)
    {
        strncpy(temp, str + i, 2);
        sscanf(temp, "%d", &num);
        if (!isPrime(num))
        {
            puts("No");
            return 0;
        }
    }

    puts("Yes");
    return 0;
}
