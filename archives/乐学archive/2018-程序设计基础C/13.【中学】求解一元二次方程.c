#include <stdio.h>
#include <math.h>
int main(void)
{
    int a, b, c;
    double delta;
    scanf("%d%d%d", &a, &b, &c);
    if (a == 0 && b == 0)
    {
        puts("Input error!");
        return 1;
    }
    double temp2 = -(double)c / (double)b;
    if (temp2 == -0.0)
    temp2 = +0.0;
    if (a == 0)
    {
        printf("x=%.6f\n", temp2);
        return 0;
    }
    delta = (double)b * (double)b - 4.0 * (double)a * (double)c;
    double temp = -(double)b / (double)a / 2.0;
    if (temp == -0.0)
        temp = +0.0;
    if (delta == 0.0)
    {
        printf("x1=x2=%.6f\n", temp);
    }
    else if (delta > 0.0)
    {
        printf("x1=%.6f\nx2=%.6f\n", (-(double)b + sqrt(delta)) / (double)a / 2.0, (-(double)b - sqrt(delta)) / (double)a / 2.0);
    }
    else
    {
        if (b == 0)
            printf("x1=%.6fi\nx2=%.6fi\n", sqrt(-delta) / (double)a / 2.0, - sqrt(-delta) / (double)a / 2.0);
        else
            printf("x1=%.6f+%.6fi\nx2=%.6f-%.6fi\n", -(double)b / (double)a / 2.0, sqrt(-delta) / (double)a / 2.0, -(double)b / (double)a / 2.0, sqrt(-delta) / (double)a / 2.0);
    }
    return 0;
}