#include <stdio.h>
int prime[1800];
int ans[900];
void calcPrime(void)
{
    int count = 0;
    for (int x = 2; count != 1800; x++)
    {
        for (int div = 2; (div * div) <= x; div++)
            if (x % div == 0)
                goto end_loop;
        prime[count++] = x;
    end_loop:;
    }
}
void calcAns(void)
{
    for (int i = 0; i < 900; i++)
    {
        ans[i] = prime[i] * prime[1799 - i];
    }
}
int main(int argc, char const *argv[])
{
    calcPrime();
    calcAns();
    for (int i = 0; i < 900; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
