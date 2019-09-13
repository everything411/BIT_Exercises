#include <stdio.h>
double mypower(double n, int p); // ANSI prototype
int main(int argc, char **argv)
{
    int power;
    double number;
    if (argc < 3)
    {
        printf("Usage:%s number power\n", argv[0]);
        return 1;
    }
    if (!sscanf(argv[1], "%lf", &number) || !sscanf(argv[2], "%d", &power))
    {
        printf("Invalid arguments.\n");
        return 1;
    }
    double result;
    result = mypower(number, power);
    printf("%f to the power %d is %lf\n", number, power, result);
    return 0;
}
double mypower(double n, int p) // function definition
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