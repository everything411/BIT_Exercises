#include <stdio.h>
#include <string.h>
int isPrime(int);
int is_back(char *);
int main(int argc, char const *argv[])
{
    int min, max;
    scanf("%d%d", &min, &max);
    char buffer[64];
    for (int i = min; i <= max; i++)
        if (isPrime(i))
        {
            sprintf(buffer, "%d", i);
            if (is_back(buffer))
                puts(buffer);
        }
    return 0;
}

int isPrime(int x)
{
    int div;       // potential divisors
    _Bool isPrime; // prime flag
    for (div = 2, isPrime = 1; (div * div) <= x; div++)
        if (x % div == 0)
            isPrime = 0; // number  is not prime
    return isPrime;
}
int is_back(char *str)
{
    int len = strlen(str);
    int half = len / 2;
    for (int i = 0; i < half; i++)
        if (str[i] != str[len - i - 1])
            return 0;
    return 1;
}