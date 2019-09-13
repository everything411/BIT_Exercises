#include<stdio.h>
#include<stdlib.h>
long long GCD(long long a, long long b)
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
    long long a, b, c, d, _gcd;
    char operator;
    long long ans[2] = {0};
    scanf("%lld/%lld %c %lld/%lld", &a, &b, &operator, &c, &d);
    switch (operator)
    {
    case '+':
        ans[0] = a * d + c * b;
        ans[1] = b * d;
        break;
    case '-':
        ans[0] = a * d - c * b;
        ans[1] = b * d;
        break;
    case '*':
        ans[0] = a * c;
        ans[1] = b * d;
        break;
    case '/':
        ans[0] = a * d;
        ans[1] = b * c;
    break;
    }
    if(ans[0] != 0)
    {
        _gcd = GCD(llabs(ans[0]), llabs(ans[1]));
        ans[0] /= _gcd;
        ans[1] /= _gcd;
    }
    if (ans[0] != 0 && ans[1] != 1)
        printf("%lld/%lld %c %lld/%lld = %lld/%lld\n", a, b, operator, c, d, ans[0], ans[1]);
    else if (ans[0] == 0)
        printf("%lld/%lld %c %lld/%lld = 0\n", a, b, operator, c, d);
    else if (ans[1] == 1)
        printf("%lld/%lld %c %lld/%lld = %lld\n", a, b, operator, c, d, ans[0]);
    return 0;
}
