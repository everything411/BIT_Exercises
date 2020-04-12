#include <stdio.h>
long long gcd(long long a, long long b)
{
    long long c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main(void)
{
    int total;
    scanf("%d", &total);
    long long nums[2][total];
    long long gcd_ans;
    long long numerator, denominator;
    numerator = denominator = 1;
    for (int i = 0; i < total; i++)
        scanf("%lld%lld", nums[0] + i, nums[1] + i);
    for (int i = 0; i < total; i++)
        for (int j = 0; j < total; j++)
            if (nums[0][i] != 0)
            {
                gcd_ans = gcd(nums[0][i], nums[1][j]);
                nums[0][i] /= gcd_ans;
                nums[1][j] /= gcd_ans;
            }
            else
            {
                puts("0");
                return 0;
            }
    for (int i = 0; i < total; i++)
    {
        numerator *= nums[0][i];
        denominator *= nums[1][i];
        gcd_ans = gcd(numerator, denominator);
        numerator /= gcd_ans;
        denominator /= gcd_ans;
    }
    if (denominator == 1)
        printf("%lld\n", numerator);
    else
        printf("%lld/%lld\n", numerator, denominator);
    return 0;
}
