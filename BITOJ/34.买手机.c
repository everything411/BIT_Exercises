// num 0 0 2 4 10 24
// sum 1 1 3 7 17 41
#include <stdio.h>
__int128_t num[100];
__int128_t sum[100] = {1, 1};
void print128(__int128_t a)
{
    if (a < 0)
    {
        putchar('-');
        print128(-a);
    }
    else
    {
        if (a > 9)
        {
            print128(a / 10);
        }
        putchar(a % 10 + '0');
    }
}
int main(int argc, char const *argv[])
{
    int a;
    scanf("%d", &a);
    for (int i = 2; i < 100; i++)
    {
        num[i] = sum[i - 1] + sum[i - 2];
        sum[i] = sum[i - 1] + num[i];
    }
    print128(num[a - 1]);
    putchar('\n');
    return 0;
}
