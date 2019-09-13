// power.c -- raises numbers to integer powers
#include <stdio.h>
double power(double n, int p); // ANSI prototype
int main(void)
{
    double x, xpow;
    int exp;
    printf("Enter a number and the integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2)
    {
        xpow = power(x, exp); // function call
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");
    return 0;
}
double power(double n, int p) // function definition
{
    double pow = 1;
    int i;
    _Bool flag = 0;
    if (n == 0.0 && p == 0)
    {
        printf("0 to the 0 is undefined, using a value of 1.\n");
        return 1.0;
    }
    if (p < 0)
    {
        p = -p;
        flag = 1;
    }
    for (i = 1; i <= p; i++)
        pow *= n;

    return flag ? 1 / pow : pow; // return the value of pow
}